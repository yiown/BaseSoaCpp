#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

typedef websocketpp::server<websocketpp::config::asio> Server;
typedef Server::message_ptr message_ptr;

/** WebSocket connection server. */
class SocketServer
{
private:
    /** Server endpoint */
    Server server;

public:
    /**
     * @brief Constructor.
     * @param port Port to use for the server.
     */
    SocketServer(unsigned int port);

    /**
     * @brief Listen and loop.
     */
    void run();

    /**
     * @brief Process incoming message.
     * @param hdl Connection handle.
     * @param msg Message.
     */
    void onMessage(websocketpp::connection_hdl hdl, message_ptr msg);
};

#endif // SOCKETSERVER_H
