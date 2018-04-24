#include "ros/ros.h"
#include "std_msgs/Float64.h"

#include <string>
#include <map>
#include <sstream>

#include <iostream>
#include <vector>
#include <string>
#include <map>


/*


#include "remote_control/carstate.h"
#include "remote_control/forward.h"
*/
class carstate
{
protected:
	static double speed;
	static double angle;
	// static std:vector<Vector2D> path;

public:
	carstate(void);

	virtual std::string run(void) = 0;

	// void Target(Vector2D vector);

	virtual ~carstate(void);
};

class forward: public carstate
{

protected:

public:
	forward(void);

	std::string run(void);

	~forward(void);
};

carstate::carstate(void)
{

}

carstate::~carstate(void)
{
	std::cout << "delete carstate\n";
}

double carstate::speed = 0;
double carstate::angle = 0;

forward::forward(void): carstate()
{

}

std::string forward::run(void)
{
	return "har kört";
}

forward::~forward(void)
{
	std::cout << "delete forward\n";
}



/*

How to start it.
roslaunch vesc_driver vesc_driver_node.launch
roslaunch vesc_driver remote_control.launch

*/

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
    
	state = stateMachine[state]->run();

	// std::cout << "state = " << state << std::endl;

	delete stateMachine["forward"];
    
    while (ros::ok())
    {
        // state = stateMachine[state]->run();

        /*msg.data = static_cast<float>(count*0.0001);

        ROS_INFO("%s", msg.data);

        duty_cycle_pub.publish(msg);
        servo_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;*/
    }


    return 0;
}
