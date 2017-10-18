#include <ros/ros.h>
#include <std_msgs/Int32.h>

#define INTRODUCE    1// Xin chao, toi la HRobot, toi den tu Hi Tech Mechatronics Lab. Han hanh duoc gap ban
#define FUNNY_WORDS  2// So thich cua toi la chay, nhay, da banh, bong ro va mua
#define STRONG_WORDS 3// To se pha huy the gioi!

void callbackReceivedMsg(const std_msgs::Int32::ConstPtr& msg){
    ROS_INFO("Toi se noi so: [%d]", msg->data);
    switch (msg->data){
        case INTRODUCE:
        system("rosrun sound_play play.py ~/catkin_ws/src/RobotHeadVoice/assets/introduce.wav");
        break;
        case FUNNY_WORDS:
        system("rosrun sound_play play.py ~/catkin_ws/src/RobotHeadVoice/assets/funny_words.wav");
        break;
        case STRONG_WORDS:
        system("rosrun sound_play play.py ~/catkin_ws/src/RobotHeadVoice/assets/strong_words.wav");
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