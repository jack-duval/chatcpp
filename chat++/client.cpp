//
//  client.cpp
//  chat++
//
//  Created by Jack Duval on 9/12/23.
//

#include "client.hpp"

Client::Client() {
    std::cout << m_startup_message << std::endl;
    
    boost::asio::io_service io_service;
    
    // socket creation
    boost::asio::ip::tcp::socket socket(io_service);
    
    // connection
    socket.connect(boost::asio::ip::tcp::endpoint(
      boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    
    // Request message from client
    const std::string msg = "Client says wassup!\n";
    boost::system::error_code error;
    
    boost::asio::write(socket, boost::asio::buffer(msg), error);
    
    if (!error) {
        std::cout << "Client sent message successfully" << std::endl;
    } else {
        std::cout << "Send failed: " << error.message() << std::endl;
    }
    
    // Getting response from server
    boost::asio::streambuf recv_buffer;
    boost::asio::read(socket, recv_buffer, boost::asio::transfer_all(), error);
    
    if (error && error != boost::asio::error::eof) {
        std::cout << "Receive failed." << error.message() << std::endl;
    } else {
        const char* data = boost::asio::buffer_cast<const char*>(recv_buffer.data());
        std::cout << data << std::endl;
    }
}
