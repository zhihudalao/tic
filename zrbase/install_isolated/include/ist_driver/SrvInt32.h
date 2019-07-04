// Generated by gencpp from file ist_driver/SrvInt32.msg
// DO NOT EDIT!


#ifndef IST_DRIVER_MESSAGE_SRVINT32_H
#define IST_DRIVER_MESSAGE_SRVINT32_H

#include <ros/service_traits.h>


#include <ist_driver/SrvInt32Request.h>
#include <ist_driver/SrvInt32Response.h>


namespace ist_driver
{

struct SrvInt32
{

typedef SrvInt32Request Request;
typedef SrvInt32Response Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SrvInt32
} // namespace ist_driver


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::ist_driver::SrvInt32 > {
  static const char* value()
  {
    return "6cd15d79626e4186c53fc1d4dab3625b";
  }

  static const char* value(const ::ist_driver::SrvInt32&) { return value(); }
};

template<>
struct DataType< ::ist_driver::SrvInt32 > {
  static const char* value()
  {
    return "ist_driver/SrvInt32";
  }

  static const char* value(const ::ist_driver::SrvInt32&) { return value(); }
};


// service_traits::MD5Sum< ::ist_driver::SrvInt32Request> should match 
// service_traits::MD5Sum< ::ist_driver::SrvInt32 > 
template<>
struct MD5Sum< ::ist_driver::SrvInt32Request>
{
  static const char* value()
  {
    return MD5Sum< ::ist_driver::SrvInt32 >::value();
  }
  static const char* value(const ::ist_driver::SrvInt32Request&)
  {
    return value();
  }
};

// service_traits::DataType< ::ist_driver::SrvInt32Request> should match 
// service_traits::DataType< ::ist_driver::SrvInt32 > 
template<>
struct DataType< ::ist_driver::SrvInt32Request>
{
  static const char* value()
  {
    return DataType< ::ist_driver::SrvInt32 >::value();
  }
  static const char* value(const ::ist_driver::SrvInt32Request&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::ist_driver::SrvInt32Response> should match 
// service_traits::MD5Sum< ::ist_driver::SrvInt32 > 
template<>
struct MD5Sum< ::ist_driver::SrvInt32Response>
{
  static const char* value()
  {
    return MD5Sum< ::ist_driver::SrvInt32 >::value();
  }
  static const char* value(const ::ist_driver::SrvInt32Response&)
  {
    return value();
  }
};

// service_traits::DataType< ::ist_driver::SrvInt32Response> should match 
// service_traits::DataType< ::ist_driver::SrvInt32 > 
template<>
struct DataType< ::ist_driver::SrvInt32Response>
{
  static const char* value()
  {
    return DataType< ::ist_driver::SrvInt32 >::value();
  }
  static const char* value(const ::ist_driver::SrvInt32Response&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // IST_DRIVER_MESSAGE_SRVINT32_H
