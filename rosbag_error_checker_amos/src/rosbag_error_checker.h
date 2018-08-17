#ifndef MAP_SERVER_HOLMES
#define MAP_SERVER_HOLMES
#include "ros/ros.h"
#include <nav_msgs/Odometry.h>
#include "core/sensors/PitaScan.h"
#include "geometry_msgs/Pose2D.h"
#include "sensor_msgs/LaserScan.h"
#include "tf/transform_datatypes.h"
#include "tf2_ros/transform_listener.h"
#include "pita_sensor_msgs/PoseScan.h"

#include "rosbag/bag.h"
#include <rosbag/view.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH


// Macro Definition for coloring codes
#define GR(str) "\033[32;5m"#str"\033[0m"
#define RD(str) "\033[31;5m"#str"\033[0m"
#define BG(str) "\033[44;37;5m"#str"\033[0m"
#define COUT std::cout<<std::setw(16)<<(strrchr(__FILE__,'/')+1)<<std::setw(3)<<__LINE__<<" "

static const double     _PI= 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348;
static const double _TWO_PI= 6.2831853071795864769252867665590057683943387987502116419498891846156328125724179972560696;

using namespace std;

class error_log{
    public:
    ros::Duration error_time;
    string error_type;
    string error_topic;
};

// Floating-point modulo
// The result (the remainder) has same sign as the divisor.
// Similar to matlab's mod(); Not similar to fmod() -   Mod(-3,4)= 1   fmod(-3,4)= -3

template<typename T>
T Mod(T x, T y)
{
    static_assert(!std::numeric_limits<T>::is_exact , "Mod: floating-point type expected");
    if (0. == y)
        return x;
    double m= x - y * floor(x/y);
    // handle boundary cases resulted from floating-point cut off:
    if (y > 0)              // modulo range: [0..y)
    {
        if (m>=y)           // Mod(-1e-16             , 360.    ): m= 360.
            return 0;
        if (m<0 )
        {
            if (y+m == y)
                return 0  ; // just in case...
            else
                return y+m; // Mod(106.81415022205296 , _TWO_PI ): m= -1.421e-14
        }
    }
    else                    // modulo range: (y..0]
    {
        if (m<=y)           // Mod(1e-16              , -360.   ): m= -360.
            return 0;
        if (m>0 )
        {
            if (y+m == y)
                return 0  ; // just in case...
            else
                return y+m; // Mod(-106.81415022205296, -_TWO_PI): m= 1.421e-14
        }
    }
    return m;
}

inline double WrapPosNegPI(double fAng);

void add_topics(std::vector<string>& error_check_topics, std::vector<string>& miss_check_topics);


void error_display(std::vector<error_log> error_info_list);

void error_check(string& bag_file ,const std::vector<string>& error_check_topics, 
                 std::vector<error_log>& error_info_list);

void miss_display(std::vector<string> &miss_list);

void miss_check(string& bag_file , std::vector<string>& miss_check_topics, std::vector<string>& miss_list);

double wrap_rot_neg_PI(double theta);
double mod(double x, double y);
void add_miss_check_topics(std::vector<std::string>& topic_list);
void display_list( std::string topic, std::vector<std::string> &list);
void add_topics(vector<string>& error_check_topics, vector<string>& miss_check_topics, string& error_check_topics_str, string& miss_check_topics_str );

#endif
