//
//  main.cpp
//  chat++
//
//  Created by Jack Duval on 9/12/23.
//
#include "client.hpp"
#include "server.hpp"
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    Client* p_client = nullptr;
    Server* p_server = nullptr;
    
    std::string client_flag = "--client";
    std::string server_flag = "--server";
    
    if (argc < 2 || !client_flag.compare(argv[1])) {
        p_client = new Client();
    } else if (!server_flag.compare(argv[1])) {
        p_server = new Server();
    } else {
        std::cout << "Flag not recognized.\n" <<
        "You can use --client or --server.\n\n" <<
        "Defaulting to client." << std::endl;
        
        p_client = new Client();
    }
    
    return 0;
}
