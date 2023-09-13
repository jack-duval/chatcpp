//
//  client.hpp
//  chat++
//
//  Created by Jack Duval on 9/12/23.
//
#pragma once

#include <string>
#include <iostream>
#include <boost/asio.hpp>

class Client {
 public:
    Client();
    ~Client();

 protected:
    std::string m_startup_message = "Client starting...";
};
