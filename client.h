#ifndef CLIENT_H
#define CLIENT_H

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include <sstream>

using boost::asio::ip::tcp;

enum { max_length = 1024 };

int preview(const char* ip, long long hwnd) {
    try
    {
        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints =
            resolver.resolve(tcp::v4(), "127.0.0.1", "1234");

        tcp::socket s(io_context);
        boost::asio::connect(s, endpoints);

        std::stringstream ss;
        ss << ip << ' ' << hwnd;
        std::string message = ss.str();
        boost::asio::write(s, boost::asio::buffer(message, message.length()));

        boost::system::error_code error;
        char buffer[1024] = {0};
        s.read_some(boost::asio::buffer(buffer), error);
        std::string ret{ buffer };
        int userid = std::stoi(ret);
        return userid;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return -1;
}

bool set_osd(long user_id,
             const char* speed, const char* distance,
             const char* train_order, const char* train_number,
             const char* location, const char* driver_number,
             bool is_record, bool is_usb){
    try
    {
        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints =
            resolver.resolve(tcp::v4(), "127.0.0.1", "1234");

        tcp::socket s(io_context);
        boost::asio::connect(s, endpoints);

        std::stringstream ss;
        ss << "osd"
           << ' ' << user_id
           << ' ' << speed
           << ' ' << distance
           << ' ' << train_order
           << ' ' << train_number
           << ' ' << location
           << ' ' << driver_number
           << ' ' << static_cast<int>(is_record)
           << ' ' << static_cast<int>(is_usb);
        std::string message = ss.str();
        boost::asio::write(s, boost::asio::buffer(message, message.length()));

        boost::system::error_code error;
        char buffer[1024] = {0};
        s.read_some(boost::asio::buffer(buffer), error);
        std::string ret{ buffer };
        int userid = std::stoi(ret);
        return userid;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return -1;
}
bool set_time(long user_id, unsigned long year,unsigned long month,unsigned long day,
              unsigned long hour,unsigned long minute,unsigned long second){
    try
    {
        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints =
            resolver.resolve(tcp::v4(), "127.0.0.1", "1234");

        tcp::socket s(io_context);
        boost::asio::connect(s, endpoints);

        std::stringstream ss;
        ss << "time_manual"
           << " " << user_id
           << ' ' << year
           << ' ' << month
           << ' ' << day
           << " " << hour
           << " " << minute
           << " "<< second;
        std::string message = ss.str();
        boost::asio::write(s, boost::asio::buffer(message, message.length()));

        boost::system::error_code error;
        char buffer[1024] = {0};
        s.read_some(boost::asio::buffer(buffer), error);
        std::string ret{ buffer };
        int userid = std::stoi(ret);
        return userid;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return -1;
}
bool sync_time(long user_id){
    try
    {
        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints =
            resolver.resolve(tcp::v4(), "127.0.0.1", "1234");

        tcp::socket s(io_context);
        boost::asio::connect(s, endpoints);

        std::stringstream ss;
        ss << "sync_time" << ' ' << user_id;
        std::string message = ss.str();
        boost::asio::write(s, boost::asio::buffer(message, message.length()));

        boost::system::error_code error;
        char buffer[1024] = {0};
        s.read_some(boost::asio::buffer(buffer), error);
        std::string ret{ buffer };
        int userid = std::stoi(ret);
        return userid;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return -1;
}

#endif // CLIENT_H
