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

// roslaunch vesc_driver vesc_driver_node.launch
roslaunch racecar auto_teleop.launch
rosrun remote_control talker

*/

#include "carstate.h"
#include "forward.h"
#include "backward.h"
#include "idle.h"
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

std::string GetState(const char *serverURL)
{
    CURL *curl = curl_easy_init();
    char errors[1024];
    int ret;
    if (curl) {
        ret = curl_easy_setopt(curl, CURLOPT_URL, serverURL);
        // if(ret!=0)
            // std::cout << "ret = " << ret << std::endl;
        // curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        // curl_easy_setopt(curl, CURLOPT_USERPWD, "user:pass");
        // curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
        // curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        // curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
        
        // char response_string[1024000];
        // char header_string[1024000];
        std::string response_string;
        std::string header_string;
        ret = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        // if(ret!=0)
            // std::cout << "curl_easy_setopt CURLOPT_WRITEFUNCTION ret = " << ret << std::endl;

        ret = curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        // if(ret!=0)
            // std::cout << "curl_easy_setopt CURLOPT_WRITEDATA ret = " << ret << std::endl;

        ret = curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, &errors);
        // if(ret!=0)
            // std::cout << "curl_easy_setopt CURLOPT_ERRORBUFFER ret = " << ret << std::endl;
        // std::cout << "errors = " << errors << std::endl;
        
        ret = curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
        // if(ret!=0)
            // std::cout << "curl_easy_setopt CURLOPT_HEADERDATA ret = " << ret << std::endl;

        char* url;
        long response_code;
        double elapsed;
        ret = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        // if(ret!=0)
            // std::cout << "curl_easy_getinfo CURLINFO_RESPONSE_CODE ret = " << ret << std::endl;
        
        ret = curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
        // if(ret!=0)
            // std::cout << "curl_easy_getinfo CURLINFO_TOTAL_TIME ret = " << ret << std::endl;
        
        ret = curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);
        // if(ret!=0)
            // std::cout << "curl_easy_getinfo CURLINFO_EFFECTIVE_URL ret = " << ret << std::endl;
        
        ret = curl_easy_perform(curl);
        // if(ret!=0)
            // std::cout << "curl_easy_perform(curl) ret = " << ret << std::endl;
        
        curl_easy_cleanup(curl);
        curl = NULL;
        
        // std::cout << "response_string = " << response_string << std::endl;
        // std::cout << "header_string   = " << header_string << std::endl;
        return response_string;
    }
    else
        return NULL;
}

std::string GetState(std::string serverURL)
{
    return GetState(serverURL.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");


    ros::NodeHandle n;

    // ros::Publisher duty_cycle_pub = n.advertise<std_msgs::Float64>("commands/motor/duty_cycle", 1000);
    // ros::Publisher servo_pub = n.advertise<std_msgs::Float64>("commands/servo/position", 1000);
    
    //ros::Publisher current_pub_ = n.advertise<std_msgs::Float64>("commands/motor/current", 1000);
    //ros::Publisher brake_pub_ = n.advertise<std_msgs::Float64>("commands/motor/brake", 1000);
    //ros::Publisher speed_pub_ = n.advertise<std_msgs::Float64>("commands/motor/speed", 1000);
    //ros::Publisher position_pub_ = n.advertise<std_msgs::Float64>("commands/motor/position", 1000);

    ros::Rate loop_rate(10);

    int count = 0;
    std_msgs::Float64 msg;
    
    std::string state = "right";
    
    std::map<std::string, carstate*> stateMachine;
    
	stateMachine["idle"] = new idle(&n);
	stateMachine["forward"] = new forward(&n);
	stateMachine["left"] = new left(&n);
	stateMachine["right"] = new right(&n);
	stateMachine["leftforward"] = new leftforward(&n);
	stateMachine["rightforward"] = new rightforward(&n);
	stateMachine["backward"] = new backward(&n);
    stateMachine["leftbackward"] = new leftbackward(&n);
	stateMachine["rightbackward"] = new rightbackward(&n);
    
	// std::cout << "state = " << state << std::endl;

    std::string serverURL= "http://10.40.190.113:8080/getstate";
    while (ros::ok())
    {

        // state = GetState("http://10.40.191.28:8080/getstate");
        state = GetState(serverURL);
        std::cout << "state = " << state << std::endl;
        if(state == "")
            break;
            
        
        std::cout << "calling state = " << state << std::endl;
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
        // break;
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
