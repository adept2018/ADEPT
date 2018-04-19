#include <basic_motion_planner/basic_motion_planner.h>

int main(int argc, char** argv) {

    // Initialize ROS:
    ros::init(argc, argv, "basic_motion_planner");
    ros::NodeHandle nh;
    MotionComputer motionComputer(nh);

    //pub = nh.advertise<std::vector<float> >("/bmp", 1);

    ros::Rate rate(40.0);
    std::cout << "Running the basic motion planner" << std::endl;
    while (nh.ok()) {
        ros::spinOnce();

        if (!motionComputer.computeMotion()) {
            std::cout << "ERROR: Cannot compute motion." << std::endl;
            return -1;
        }

        

        //pub.publish();
    }

    return 0;
}
