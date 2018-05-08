#include "ros/ros.h"
#include "std_msgs/Float64.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include <unistd.h>
#include <ctime>
#include <curl/curl.h>

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

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

std::string GetState(std::string serverURL)
{
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, serverURL);
        // curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        // curl_easy_setopt(curl, CURLOPT_USERPWD, "user:pass");
        // curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
        // curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        // curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
        
        std::string response_string;
        std::string header_string;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
        
        char* url;
        long response_code;
        double elapsed;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
        curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);
        
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl = NULL;
        
        return response_string;
    }
    else
        return NULL;
}

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
    
	stateMachine["forward"] = new forward(&n);
	stateMachine["left"] = new left(&n);
	stateMachine["right"] = new right(&n);
	stateMachine["leftforward"] = new leftforward(&n);
	stateMachine["rightforward"] = new rightforward(&n);
	stateMachine["backward"] = new backward(&n);
    stateMachine["leftbackward"] = new leftbackward(&n);
	stateMachine["rightbackward"] = new rightbackward(&n);
    
	// std::cout << "state = " << state << std::endl;
    
    while (ros::ok())
    {

       // state = GetState("http://10.40.232.67:8080/getstate");
        
       stateMachine[state]->run();

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
