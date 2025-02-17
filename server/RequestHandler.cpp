//
//  RequestHandler.cpp
//  HTTPServer
//  Implementation of request processing
//  Created by Michael Olubode on 2/16/25.
//

/*
 (Request Processing Implementation)
 📌 Purpose: Implements request parsing and response generation.

 🔹 Implementation Steps:

 Extract HTTP method (GET/POST) and requested URL from the raw request string.
 If the URL maps to a static file (e.g., /index.html), serve the file using serveStaticFile().
 If the file does not exist, return generate404Response().
 Format and return an HTTP response (HTTP/1.1 200 OK with headers).

*/

#include "RequestHandler.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

std::string RequestHandler::processRequest(const std::string& request, const std::string& rootDir) {
    // ✅ Ensure `/` serves `index.html`
    if (request.find("GET / ") != std::string::npos || request.find("GET / HTTP") != std::string::npos) {
        return serveStaticFile(rootDir + "/index.html");
    }

    // ✅ Serve other static files (CSS, JS, images, etc.)
    if (request.find("GET ") != std::string::npos) {
        size_t pos = request.find(" ");
        size_t endPos = request.find(" ", pos + 1);
        std::string filePath = rootDir + request.substr(pos + 1, endPos - pos - 1);

        return serveStaticFile(filePath);
    }

    // ✅ Handle API request (JSON response)
    if (request.find("GET /api") != std::string::npos) {
        return serveJsonResponse();
    }

    return generate404Response();
}


std::string RequestHandler::serveJsonResponse() {
    std::string jsonResponse = R"({
        "status": "success",
        "message": "Welcome to the C++ HTTP Server"
    })";

    return "HTTP/1.1 200 OK\r\n"
           "Content-Type: application/json\r\n"
           "Content-Length: " + std::to_string(jsonResponse.size()) + "\r\n"
           "\r\n" + jsonResponse;
}


std::string RequestHandler::serveStaticFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) return generate404Response();

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    std::string contentType = "text/plain"; // Default content type

    if (filePath.find(".html") != std::string::npos) contentType = "text/html";
    if (filePath.find(".css") != std::string::npos) contentType = "text/css";
    if (filePath.find(".js") != std::string::npos) contentType = "application/javascript";
    if (filePath.find(".png") != std::string::npos) contentType = "image/png";
    if (filePath.find(".jpg") != std::string::npos || filePath.find(".jpeg") != std::string::npos) contentType = "image/jpeg";

    return "HTTP/1.1 200 OK\r\n"
           "Content-Type: " + contentType + "\r\n"
           "Content-Length: " + std::to_string(content.size()) + "\r\n"
           "\r\n" + content;
}

std::string RequestHandler::handlePostRequest() {
    return "HTTP/1.1 200 OK\r\n"
           "Content-Type: text/plain\r\n"
           "Content-Length: 16\r\n"
           "\r\n"
           "POST Request OK";
}

std::string RequestHandler::generate404Response() {
    return "HTTP/1.1 404 Not Found\r\n"
           "Content-Length: 13\r\n"
           "\r\n"
           "404 Not Found";
}
