//
//  RequestHandler.hpp
//  HTTPServer
//  Header file for handling requests
//  Created by Michael Olubode on 2/16/25.
//

/*
 (Request Processing Header)
 📌 Purpose: Declares methods to parse HTTP requests and generate appropriate responses.

 🔹 Functions to Implement:

 std::string processRequest(std::string request); → Parses HTTP request and determines response.
 std::string serveStaticFile(std::string filePath); → Reads and serves requested static files (HTML, CSS, JS).
 std::string generate404Response(); → Returns a 404 Not Found response.
*/

#ifndef REQUEST_HANDLER_HPP
#define REQUEST_HANDLER_HPP

#include <string>

class RequestHandler {
public:
    // Process incoming HTTP requests
    static std::string processRequest(const std::string& request, const std::string& rootDir);

    // Serve JSON response for API endpoints
    static std::string serveJsonResponse();

    // Serve static files (HTML, CSS, JS, images)
    static std::string serveStaticFile(const std::string& filePath);

    // Handle POST requests
    static std::string handlePostRequest();

    // Generate 404 Not Found response
    static std::string generate404Response();
};

#endif // REQUEST_HANDLER_HPP

