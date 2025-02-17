//
//  main.cpp
//  HTTPServer
//
//  Created by Michael Olubode on 2/16/25.
//  Entry point of the server

/*
 main.cpp (Entry Point)
 📌 Purpose: Initializes and starts the HTTP server.

 🔹 Implementation Steps:

 Parse server configuration (e.g., port, static file directory).
 Create an instance of HTTPServer.
 Call start() to begin listening for client connections.
 Handle shutdown gracefully on termination.
*/

#include "server/HTTPServer.hpp"

int main() {
    HTTPServer server(8080, "public");
    server.start();
    return 0;
}

