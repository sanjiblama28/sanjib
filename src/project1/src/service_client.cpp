#include "ros/ros.h"
#include "project1/WeatherStatusCheck.h"

#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "weather_status_service_client_node");

  ros::NodeHandle node_handle;

  ros::ServiceClient client = node_handle.serviceClient<project1::WeatherStatusCheck>("weather_status_check");

  project1::WeatherStatusCheck weather_status_check_srv;

  int input_num;

  std::cout << "Type '0' to quit" << std::endl;

  while (ros::ok())
  {
    std::cout << "Enter a GPS location of the autonomous vehicle: ";
    std::cin >> input_num;

    weather_status_check_srv.request.number = input_num;

    if (input_num == 0)
    {
      ROS_INFO("Exiting Application...");
      return 0;
    }

    if (client.call(weather_status_check_srv))
    {
      std::string resp;
      resp = weather_status_check_srv.response.answer;

      std::cout << "The weather is " << resp << std::endl;
    }
    else
    {
      ROS_ERROR("Service Call Failed");
      return 1;
    }

    std::cin.clear();


  }
}
