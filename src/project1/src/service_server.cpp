#include "ros/ros.h"
#include "project1/WeatherStatusCheck.h"

bool determineWeatherStatus(project1::WeatherStatusCheck::Request &req,
                      project1::WeatherStatusCheck::Response &res)
{
  int remainder = req.number % 2;

  if(remainder == 0)
  {
    res.answer = "Good";
  }
  else if (remainder == 1)
  {
    res.answer = "Bad";
  }
  else
  {
    return false;
  }

  return true;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "weather_status_service_server_node");

  ros::NodeHandle node_handle;

  ros::ServiceServer service = node_handle.advertiseService("weather_status_check", determineWeatherStatus);

  ROS_INFO("Weather Status Check Server Running...");

  ros::spin();

  return 0;
}
