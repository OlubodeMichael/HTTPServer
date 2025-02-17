# C++ HTTP Server 🚀

A lightweight, multithreaded HTTP server built in C++. This server can handle multiple client requests, serve static files (HTML, CSS, JS, images), and provide API responses.

## 📌 Features
- ✅ **Multithreading** - Handles multiple client connections simultaneously.
- ✅ **Static File Serving** - Serves `index.html`, `style.css`, `script.js`, images, and more.
- ✅ **API Support** - Responds to API requests with JSON data.
- ✅ **Logging** - Logs server events and client requests in `server.log`.
- ✅ **Simple & Fast** - Uses raw sockets for fast communication.

---

## 📂 Project Structure
```
HTTPServer/
│── server/
│   │── HTTPServer.hpp       # Server class header
│   │── HTTPServer.cpp       # Server implementation
│   │── RequestHandler.hpp   # Request processing
│   │── RequestHandler.cpp   # Static file & API handling
│── utils/
│   │── Logger.hpp           # Logging header
│   │── Logger.cpp           # Logger implementation
│── public/
│   │── index.html           # Main webpage
│   │── style.css            # CSS file
│   │── script.js            # JavaScript file
│── config/
│   │── server_config.json   # Server settings
│── README.md                # Project documentation
│── main.cpp                 # Entry point
```

---

## 🚀 Installation & Usage

### **1️⃣ Clone the Repository**
```sh
git clone https://github.com/OlubodeMichael/HTTPServer.git
cd HTTPServer
```

### **2️⃣ Compile the Project**
```sh
g++ -std=c++11 -o HTTPServer main.cpp server/HTTPServer.cpp server/RequestHandler.cpp utils/Logger.cpp -lpthread
```

### **3️⃣ Run the Server**
```sh
./HTTPServer
```
By default, the server runs on **port 8080**.

### **4️⃣ Test the Server**
#### 📌 **Test in Browser**
- Open `http://localhost:8080/` → Serves `index.html`
- Open `http://localhost:8080/index.html` → Direct access to `index.html`
- Open `http://localhost:8080/api` → Returns a JSON response

#### 📌 **Test with cURL**
```sh
curl -v http://localhost:8080/
```
```sh
curl -v http://localhost:8080/api
```

---

## 🌍 API Endpoints
| **Method** | **Endpoint**      | **Function**                      |
|-----------|-----------------|--------------------------------|
| **GET**  | `/`             | Serves `index.html`.          |
| **GET**  | `/index.html`   | Serves `index.html` directly. |
| **GET**  | `/api`          | Returns JSON response.        |

📌 Example API Response (`http://localhost:8080/api`):
```json
{
    "status": "success",
    "message": "Welcome to the C++ HTTP Server"
}
```

---

## 🛠️ Debugging & Logs
- Check the server logs:
```sh
cat server.log
```
- If port 8080 is in use, find the process:
```sh
lsof -i :8080
```
- Kill a process using port 8080:
```sh
kill -9 <PID>
```

---

## 📌 Next Steps
- 🔹 **Add SSL (HTTPS) Support** with OpenSSL
- 🔹 **Support Dynamic Routes** for API
- 🔹 **Implement WebSockets for Real-time Chat**
- 🔹 **Dockerize the Server for Deployment**

---

## 👨‍💻 Author
**Michael Olubode**  
🚀 Built with ❤️ in C++  
📚 GitHub: [OlubodeMichael](https://github.com/OlubodeMichael)  

---

## 🐜 License
This project is licensed under the MIT License.

