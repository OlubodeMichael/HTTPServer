//
//  HTTPServer.cpp
//  HTTPServer
//  Implementation of the server
//  Created by Michael Olubode on 2/16/25.
//

/*
 (Server Implementation)
 📌 Purpose: Implements socket creation, request handling, and response sending.

 🔹 Implementation Steps:
 - Create a TCP socket using socket(AF_INET, SOCK_STREAM, 0).
 - Bind the socket to the server’s IP address and port using bind().
 - Listen for incoming connections using listen().
 - Accept new connections with accept().
 - Read client requests using recv().
 - Pass the request to RequestHandler for processing.
 - Send HTTP responses using send().
 - Close the connection after sending the response.
*/

#include "HTTPServer.hpp"
#include "RequestHandler.hpp"
#include "../Utils/Logger.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <thread>

using namespace std;

HTTPServer::HTTPServer(int port, string rootDir) {
    this->port = port;
    this->rootDirectory = rootDir;
    this->serverSocket = -1;
}

void HTTPServer::start() {
    struct sockaddr_in serverAddr;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        Logger::logError("Error creating socket!");
        return;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    // ✅ Correct bind usage
    if (::bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        Logger::logError("Error binding to port " + std::to_string(port));
        close(serverSocket);
        return;
    }

    if (listen(serverSocket, 10) < 0) {
        Logger::logError("Error listening on port " + std::to_string(port));
        close(serverSocket);
        return;
    }

    Logger::logInfo("Server started on port " + std::to_string(port));
    std::cout << "Server started on port " << port << std::endl;

    while (true) {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket < 0) {
            Logger::logError("Error accepting connection!");
            continue;
        }

        // Handle each client in a new thread
        std::thread(&HTTPServer::handleClient, this, clientSocket).detach();
    }
}

void HTTPServer::handleClient(int clientSocket) {
    Logger::logInfo("New client connected.");

    char buffer[30000] = {0};
    ssize_t bytesRead = read(clientSocket, buffer, sizeof(buffer));

    if (bytesRead <= 0) {
        Logger::logError("Failed to read request.");
        close(clientSocket);
        return;
    }

    std::string request(buffer);
    Logger::logInfo("Received request: " + request);

    // ✅ Process request using RequestHandler instead of hardcoded response
    std::string response = RequestHandler::processRequest(request, rootDirectory);

    // ✅ Send response
    write(clientSocket, response.c_str(), response.length());
    
    Logger::logInfo("Response sent to client.");
    close(clientSocket);
}


