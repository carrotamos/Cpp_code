#include "rosbag_error_checker.h"

using namespace std;



// default priors, could be set in launch file
static double dist_max = 10; 
static double theta_max = 3.14;
// double t_max = 2.0;
double freq_min = 3;
static double time_min = 2;

void add_topics(vector<string>& error_check_topics, vector<string>& miss_check_topics, string& error_check_topics_str, string& miss_check_topics_str )
{

    int idx1 = 0;
    int idx2 = 0;

    while(error_check_topics_str.length() > 2 ) 
    {     
        idx2 = error_check_topics_str.find(';');
        error_check_topics.push_back(error_check_topics_str.substr(idx1,idx2));
        cout << "=========" << endl;
        cout << error_check_topics_str.substr(idx1,idx2) << endl;
        error_check_topics_str.erase(idx1, idx2+1);
    }

    idx1 = 0;
    idx2 = 0;

    while(miss_check_topics_str.length() > 2 ) 
    {     
        idx2 = miss_check_topics_str.find(';');
        miss_check_topics.push_back(miss_check_topics_str.substr(idx1,idx2));
        cout << "=========" << endl;
        cout << miss_check_topics_str.substr(idx1,idx2) << endl;
        miss_check_topics_str.erase(idx1, idx2+1);
    }

}


void miss_check(string& bag_file ,vector<string>& miss_check_topics, 
                vector<string>& miss_list)
{
    rosbag::Bag bag(bag_file,rosbag::bagmode::Read);
    rosbag::View miss_check_view(bag, rosbag::TopicQuery(miss_check_topics));
    
    ros::Time init_Time;

    int count = 0;

    vector<double> duration(miss_check_topics.size(),0);

    vector<double>::iterator iter_duration = duration.begin();
    vector<string>::iterator iter_topics = miss_check_topics.begin();
    // while(iter2 != duration.end())
    //     cout << *iter2++ << endl;


    foreach(rosbag::MessageInstance const m, miss_check_view) // for each message in the bag
    {   
        ros::Time const& now_time = m.getTime();

        if (count++ == 0)
            init_Time = now_time;
        
        iter_topics = find(miss_check_topics.begin(), miss_check_topics.end(), m.getTopic());

        iter_duration = duration.begin() + (iter_topics - miss_check_topics.begin());
        // cout << *iter_duration << endl;
        *iter_duration = (now_time - init_Time).toSec();
    }
    bag.close();
    iter_duration = duration.begin();
    iter_topics = miss_check_topics.begin();
   
    //     cout << *iter2++ << endl;
    while(iter_duration != duration.end())
        if (*iter_duration++ < time_min)
            miss_list.push_back(*iter_topics++);

    cout << GR(##### Topic Check #####) << endl;

    if ( miss_list.empty())
        cout << GR(No Topic Missing) << endl;
    else  
        miss_display(miss_list);
    cout << "" << endl;
}

void error_check(string& bag_file ,const vector<string>& error_check_topics, 
                 vector<error_log>& error_info_list)
{
    rosbag::Bag bag(bag_file,rosbag::bagmode::Read);
    rosbag::View error_check_view(bag, rosbag::TopicQuery(error_check_topics));
    // previous time init
    ros::Time prev_Time;
    ros::Time init_Time;

    double x_prev = 0;
    double y_prev = 0;
    double theta_prev = 0;

    // error counters 
    int error_count = 0;
    int count_dist = 0;
    int count_theta = 0;
    int count_freq = 0;
    int frame_count = 0;

    foreach(rosbag::MessageInstance const m, error_check_view) // for each message in the bag
    {    
        const pita_sensor_msgs::PoseScan::ConstPtr pita_msg = m.instantiate<pita_sensor_msgs::PoseScan>();

        geometry_msgs::Pose2D pita_pose;

        // Examing Odometry Message 
        if (pita_msg != NULL)
        {
            bool dist_good = true;
            bool theta_good = true;
            bool freq_good = true;
            pita_pose = pita_msg->pose;
            string topic_name = "/scan_with_pose";

            double x = abs(pita_pose.x - x_prev);
            double y = abs(pita_pose.y - y_prev);

            double theta;
            double dist;
            ros::Time const& now_time = m.getTime();
            // cout << GR(TIME:) << now_time << endl;
            double freq;
            // cout << (now_time-prev_Time).toSec() << endl;
            if (frame_count != 0)
            {
                
                theta = WrapPosNegPI(pita_pose.theta - theta_prev);
                dist = sqrt(x*x + y*y);
                dist_good = dist < dist_max;
                // cout << "dist_good: " << dist_good << endl; 
                // theta_good = theta < theta_max;
            // check freqeuncy/scan_with_pose
                double t = (now_time - prev_Time).toSec();
                // freq_good = t < t_max;
                freq = int(1/t);
                freq_good = freq > freq_min;
            }
            else 
            {
                init_Time = now_time;
                freq_good = 1;
            }

            theta_prev = pita_pose.theta; 
            x_prev = pita_pose.x;
            y_prev = pita_pose.y;
            prev_Time = now_time;            
            

            if (!(dist_good && theta_good && freq_good)) 
                error_count++;


            frame_count++;
            // return error information 

            if (!freq_good)
            {
                count_freq++;
                error_log* e = new error_log();
                ros::Duration d((now_time - init_Time).toSec());
                e->error_time = d;
                e->error_topic = topic_name;
                e->error_type = "Frequency out of range at value: " + to_string(freq);
                error_info_list.push_back(*e);
                delete e;
            }


            if (!dist_good)
            {
                count_dist++;
                error_log* e = new error_log();
                ros::Duration d((now_time - init_Time).toSec());
                e->error_time = d;
                e->error_topic = topic_name;
                e->error_type = "Distance out of range at value: " + to_string(dist);
                error_info_list.push_back(*e);
                delete e;
            }

            if (!theta_good)
            {
                count_theta++;
                error_log* e = new error_log();
                ros::Duration d((now_time - init_Time).toSec());
                e->error_time = d;
                e->error_topic = topic_name;
                e->error_type = "Theta out of range at value: " + to_string(theta);
                error_info_list.push_back(*e);
                delete e;
            }

        }
        
    }
    if (frame_count > 0)
    {
    cout << GR(##### ERROR INFO #####) << endl;
    if (error_count > 0)
    {
            error_display(error_info_list);
            cout << GR(Total Errors found: )<< error_count << endl;
            cout << GR(Number of distance errors: ) << count_dist << endl;
            cout << GR(Number of theta errors: ) << count_theta << endl;
            cout << GR(Number of frequency errors: ) << count_freq << endl;
        }
        else 
            cout << GR(No Errors Found) << endl;
    }else{
        cout << RD(##### FATAL: BAG READ FAILED #####) << endl << endl;;
    }
    cout << " " << endl;
    bag.close();
}

void display_list(string topic,vector<string>& topic_list)
{
    std::vector<string>::iterator iter = topic_list.begin();
    cout << GR(====) << topic << endl; 
    while(iter != topic_list.end())
        cout << *iter++ << endl;
    cout << endl;
}

void error_display(vector<error_log> error_info_list){
    vector<error_log>::iterator iter = error_info_list.begin();
    while (iter != error_info_list.end())
    {
        cout << RD(Time: ) << iter->error_time << endl;
        cout << RD(Error Topic: ) << iter->error_topic << endl;
        cout << RD(Error Type: ) << iter->error_type << endl;
        cout << " "<< endl;
        iter++;
    }
}

void miss_display(vector<string> &miss_list)
{
    vector<string>::iterator iter = miss_list.begin();
    while(iter < miss_list.end())
         cout << RD(Topic: ) << *iter++ << " " << RD( is missing) << endl;

    cout << "  " << endl;
}


// wrap [rad] angle to [-PI..PI)
inline double WrapPosNegPI(double fAng)
{
    return Mod(fAng + _PI, _TWO_PI) - _PI;
}


int main(int argc, char **argv)
{
    cout << GR(===== System On =====) << endl << endl;
    
    ros::init(argc, argv, "map_server_holmes");
    ros::NodeHandle node;  

    string bag_file("/home/derrick/catkin_ws/src/bag/bag_wop/map_server_test_2018-07-02-14-04-11.bag"); 
    string error_check_topics_str("/topic1;/topic2;");
    string miss_check_topics_str("/topic1;/topic2;");
    // get parameters from roslaunch 
    ros::param::get("~bag_file", bag_file);
    ros::param::get("~dist_max", dist_max);
    ros::param::get("~theta_max", theta_max);
    ros::param::get("~freq_min", freq_min);
    ros::param::get("~time_min", time_min);
    ros::param::get("~miss_check_topics_str", miss_check_topics_str);
    ros::param::get("~error_check_topics_str", error_check_topics_str);

    cout << BG(Bag Name: ) << bag_file << endl << endl;
    
    vector<string> error_check_topics; 
    vector<string> miss_check_topics;

    add_topics(error_check_topics, miss_check_topics, error_check_topics_str, miss_check_topics_str);
    
    display_list("Contents in error check topic list",error_check_topics);
    display_list("Contents in miss check topic list", miss_check_topics);
    
    // cout << "start" << endl;

    vector<error_log> error_info_list;
    vector<string> miss_list;


    error_check(bag_file, error_check_topics, error_info_list);
    miss_check(bag_file, miss_check_topics, miss_list);

    cout << GR(===== System Off =====) << endl;
    return 0;
}