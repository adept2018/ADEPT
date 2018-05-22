#include <basic_motion_planner/basic_motion_planner.h>

int main(int argc, char** argv) {

    // Initialize ROS:
    ros::init(argc, argv, "basic_motion_planner");
    ros::NodeHandle nh;
    MotionComputer motionComputer(nh);

    pubPose = nh.advertise<geometry_msgs::PoseStamped>("bmp/pose", 10);
    pubCloud = nh.advertise<sensor_msgs::PointCloud2>("bmp/cloud", 10);

    pcl::PointCloud<pcl::PointXYZ> cloud;
    sensor_msgs::PointCloud2 pclmsg;

    ros::Rate rate(40.0);
    std::cout << "Running the basic motion planner." << std::endl;

    while (nh.ok()) {
        ros::spinOnce();

        if (!motionComputer.computeMotion()) {
            std::cout << "ERROR: Cannot compute motion." << std::endl;
            return -1;
        }

        cloud = motionComputer.cloud;

        if (!cloud.empty()) {
            geometry_msgs::PoseStamped outputMsg;
            outputMsg.header.frame_id = "bmp";

            outputMsg.pose.position.x = 0;
            outputMsg.pose.position.y = 0;
            outputMsg.pose.position.z = 0;

            outputMsg.pose.orientation.x = motionComputer.v[0];
            outputMsg.pose.orientation.y = motionComputer.v[1];
            outputMsg.pose.orientation.z = 0;
            outputMsg.pose.orientation.w = 0;

            pcl::toROSMsg(cloud, pclmsg);
            pclmsg.header.frame_id = "bmp";
            pubCloud.publish(pclmsg);
            pubPose.publish(outputMsg);

            std::cout<<"publish: x="<<motionComputer.v[0]<<" y="<<motionComputer.v[1]<<std::endl;
        }


        rate.sleep();
    }
}
