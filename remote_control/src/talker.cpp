#include "ros/ros.h"
#include "std_msgs/Float64.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

/*

To run.

roslaunch vesc_driver vesc_driver_node.launch
rosrun remote_control talker

*/

#include "carstate.h"
#include "forward.h"
#include "backward.h"
#include "left.h"
#include "right.h"
#include "leftforward.h"
#include "rightforward.h"
#include "leftbackward.h"
#include "rightbackward.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");


    ros::NodeHandle n;

    ros::Publisher duty_cycle_pub = n.advertise<std_msgs::Float64>("commands/motor/duty_cycle", 1000);
    ros::Publisher servo_pub = n.advertise<std_msgs::Float64>("commands/servo/position", 1000);
    
    //ros::Publisher current_pub_ = n.advertise<std_msgs::Float64>("commands/motor/current", 1000);
    //ros::Publisher brake_pub_ = n.advertise<std_msgs::Float64>("commands/motor/brake", 1000);
    //ros::Publisher speed_pub_ = n.advertise<std_msgs::Float64>("commands/motor/speed", 1000);
    //ros::Publisher position_pub_ = n.advertise<std_msgs::Float64>("commands/motor/position", 1000);

    ros::Rate loop_rate(10);

    int count = 0;
    std_msgs::Float64 msg;
    
    std::string state = "forward";
    
    std::map<std::string, carstate*> stateMachine;
    
	stateMachine["forward"] = new forward();
	stateMachine["left"] = new left();
	stateMachine["right"] = new right();
	stateMachine["leftforward"] = new leftforward();
	stateMachine["rightforward"] = new rightforward();
	stateMachine["backward"] = new backward();
    stateMachine["leftbackward"] = new leftbackward();
	stateMachine["rightbackward"] = new rightbackward();
    
	state = stateMachine[state]->run();

	// std::cout << "state = " << state << std::endl;
    
    while (ros::ok())
    {
        state = stateMachine[state]->run();

        /*msg.data = static_cast<float>(count*0.0001);

        ROS_INFO("%s", msg.data);

        duty_cycle_pub.publish(msg);
        servo_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;*/
        if(state == "break")
            break;
    }
    
    /*
    
    The car use an old verison...
    
    for(const auto &i : stateMachine)
    {
        delete stateMachine[i.first];
        //stateMachine[i.first] = NULL;
    }*/
    
    delete stateMachine["forward"];
    delete stateMachine["left"];
    delete stateMachine["right"];
    delete stateMachine["leftforward"];
    delete stateMachine["rightforward"]; 
    delete stateMachine["backward"];
    delete stateMachine["leftbackward"];
    delete stateMachine["rightbackward"];
}