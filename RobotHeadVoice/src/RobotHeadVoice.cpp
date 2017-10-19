#include <ros/ros.h>
#include <std_msgs/Int32.h>

#define INTRODUCE      1// Xin chao, toi la HRobot, toi den tu Hi Tech Mechatronics Lab. Han hanh duoc gap ban
#define HOBBY          2// So thich cua toi la chay, nhay, da banh, bong ro va mua
#define DESTROY        3// To se pha huy the gioi!
#define ASKWHAT_ROBOT  4
#define ASKWHAT_HELI   5
#define ASKWHAT_STRONG 6
#define GETAWAY_ROBOT  7
#define GETAWAY_HELI   8


void callbackReceivedMsg(const std_msgs::Int32::ConstPtr& msg){
    ROS_INFO("Toi se noi so: [%d]", msg->data);
    switch (msg->data){
        case INTRODUCE:
        system("rosrun sound_play play.py ~/catkin_ws/src/RobotHeadVoice/assets/introduce.wav");
        break;
        case HOBBY:
        system("rosrun sound_play play.py ~/catkin_ws/src/RobotHeadVoice/assets/hobby.wav");
        break;
        case DESTROY:
        system("rosrun sound_play play.py ~/catkin_ws/src/RobotHeadVoice/assets/destroytheworld.wav");
        break;
        case ASKWHAT_ROBOT:
        system("rosrun sound_play play.py ~/catkin_ws/src/RobotHeadVoice/assets/hoigi_robot.wav");
        break;
        case ASKWHAT_HELI:
        system("rosrun sound_play play.py ~/catkin_ws/src/RobotHeadVoice/assets/hoigi_heli.wav");
        break;
        case ASKWHAT_STRONG:
        system("rosrun sound_play play.py ~/catkin_ws/src/RobotHeadVoice/assets/hoigi_strong.wav");
        break;
        case GETAWAY_ROBOT:
        system("rosrun sound_play play.py ~/catkin_ws/src/RobotHeadVoice/assets/bien_robot.wav");
        break;
        case GETAWAY_HELI:
        system("rosrun sound_play play.py ~/catkin_ws/src/RobotHeadVoice/assets/bien_heli.wav");
        break;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "RobotHeadVoice");
    ros::NodeHandle n;
    ros::Subscriber receivedMsg = n.subscribe("/UXA90_Voice",10, callbackReceivedMsg);
    ros::spin();
    return 0;
}