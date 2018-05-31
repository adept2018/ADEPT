#include <basic_motion_planner/basic_motion_planner.h>

int main(int argc, char** argv) {

    // Initialize ROS:
    ros::init(argc, argv, "basic_motion_planner");
    ros::NodeHandle nh;
    MotionComputer motionComputer(nh);

    pubPose = nh.advertise<geometry_msgs::PoseStamped>("bmp/pose", 10);
    pubCloud = nh.advertise<sensor_msgs::PointCloud2>("bmp/cloud", 10);
    pubDirection = nh.advertise<geometry_msgs::PoseStamped>("bmp/direction", 10);
    pubAck = nh.advertise<ackermann_msgs::AckermannDriveStamped>("vesc/high_level/ackermann_cmd_mux/input/default/", 10);

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

        float steeringAngle = 0;

        if (!cloud.empty()) {
            // Some stuff for visualization
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

            geometry_msgs::PoseStamped direction;
            direction.header.frame_id = "bmp";

            direction.pose.position.x = 0;
            direction.pose.position.y = 0;
            direction.pose.position.z = 0;

            direction.pose.orientation.x = 1;
            direction.pose.orientation.y = 0;
            direction.pose.orientation.z = 0;
            direction.pose.orientation.w = 0;
            pubDirection.publish(direction);
            // End of stuff for visualization

            // Computed angle
            steeringAngle = motionComputer.v[2];
        }


        ackermann_msgs::AckermannDriveStamped ackMsg;
        ackMsg.header.frame_id = "bmp";

        // 0 or computed angle from motionComputer
        ackMsg.drive.steering_angle = steeringAngle;
        // Use fixed speed (m/s)
        ackMsg.drive.speed = 0.5;

        rate.sleep();
    }
}
