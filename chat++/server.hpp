//
//  server.hpp
//  chat++
//
//  Created by Jack Duval on 9/12/23.
//
#pragma once

#include <string>
#include <iostream>
#include <boost/asio.hpp>

class Server {
 public:
    Server();
    ~Server();
    
    std::string read_(boost::asio::ip::tcp::socket& socket);
    void write_(boost::asio::ip::tcp::socket& socket, const std::string& msg);
    
    
 protected:
    std::string m_startup_message = "Server starting...";
};
