# rosbag_error_checker

## Description 

The program is used for checking if a recorded rosbag is recorded correctly. 

What it actually does is:

1. Check if messages from required topics (currently include /scan, /scan_with_pose, /odom2D) are missed. Specifically, the duration of message in a given topic is checked. 
2. Check if there are evident error in odometry information. (e.g. the robot moves 10 meters between two frame). Specifically, the below informations are checked:
   1. distance: dist = sqrt( (x - x_prev)^2 +( y - y_prev)^2)
   2. theta : theta = wrap(theta - theta_prev)
   3. frequency: freq = 1/ (now_time - prev_time

## Installation 

Put the package in the ros_workspace/src and use catkin_make to build.

## Usage 

The program can be used through roslaunch. 

```
roslaunch rosbag_error_checker error_checker.launch
```

Below are the parameters that can be set directly in launch file:

1. *string* bag_file: directory of rosbag file 
2. *double* dist_max: maximum allowed translation of robot motion between two frames  
3. *double* theta_max: maximum allowed rotation of robot motion between two frames 
4. *double* freq_min: minimum allowed frequency between two frames.
5. *double* time_min: minimum allowed duration for a given topic to be listed exist.   
6. *string* miss_check_topics_str: miss check topics. 
7. *string* error_check_topics_str: error check topics

**Notice:**  For parameter 6 and 7, the topics must be inputed in form: *"/topic1;/topic2;"*. Remember the quote when passing arguments through command line and remember the semicolon at the end of the string.



Available of passing arguments through command line. e.g. 

```
roslaunch rosbag_error_checker error_checker.launch miss_check_topics_str:="/scan;/odom2D;" error_check_topics_str="/scan_with_pose;"
```



## Modification Cookbook  

本程序可能需要修改的地方包括：

1. 错误检测和信息缺失检测的topics （直接修改add_topics方法）
2. 错误检测policy （直接修改 miss_check 方法）
3. 信息缺失检测policy （直接修改 error_check方法）



## Common Error

#### core dumped

发生的主要原因是空指针。容易出错的地方时 message instance 的实例化的时候，即：error_check 方法中的m.instantiate。本程序写有空指针保护，理论上不会出现这个问题。如果出现了可以用print定位，从这个角度考虑出现的原因。



## Contributer 

siyu.zhang@narwel.com