//
//  server.cpp
//  chat++
//
//  Created by Jack Duval on 9/12/23.
//

#include "server.hpp"

Server::Server() {
    std::cout << m_startup_message << std::endl;
    
    boost::asio::io_service io_service;
    
    // listen
    boost::asio::ip::tcp::acceptor acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1234));
    
    // socket creation
    boost::asio::ip::tcp::socket socket_(io_service);
    
    // wait for connection
    acceptor_.accept(socket_);
    
    // read operation
    std::string message = read_(socket_);
    std::cout << message << std::endl;
    
    // write operation
    write_(socket_, "Server says hi!");
    std::cout << "Sent message from server..." << std::endl;
}

std::string Server::read_(boost::asio::ip::tcp::socket& socket){
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, "\n");
    std::string data = boost::asio::buffer_cast<const char*>(buf.data());
    
    return data;
}

void Server::write_(boost::asio::ip::tcp::socket& socket, const std::string& msg) {
    const std::string msg_term = msg + "\n";
    boost::asio::write(socket, boost::asio::buffer(msg_term));
}

