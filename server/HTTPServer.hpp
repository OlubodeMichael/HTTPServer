//
//  HTTPServer.hpp
//  HTTPServer
//  Header file for server class
//  Created by Michael Olubode on 2/16/25.
//

/*
 (Server Header)
 📌 Purpose: Declares the HTTP server class.

 🔹 Functions to Implement:

 HTTPServer(int port, std::string rootDir); → Constructor to initialize port and root directory.
 void start(); → Starts listening for connections.
 void handleClient(int clientSocket); → Reads request, processes it, and sends a response.
 void stop(); → Gracefully shuts down the server.

*/

#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#include <string>
using namespace std;

class HTTPServer {
private:
    int port;
    int serverSocket;
    string rootDirectory;

public:
    HTTPServer(int port, std::string rootDir);
    void start();
    void handleClient(int clientSocket);
    void stop();
};

#endif // HTTP_SERVER_HPP

