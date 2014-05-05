#include <base/SocketServer.h>

/** Constructor setting server parameters. */
SocketServer::SocketServer(unsigned int port)
{
    // Set logging settings
    server.clear_access_channels(websocketpp::log::alevel::all);

    // Register our message handler
    server.set_message_handler(
                websocketpp::lib::bind(&SocketServer::onMessage, this,
                                       websocketpp::lib::placeholders::_1,
                                       websocketpp::lib::placeholders::_2));

    // Initialize ASIO
    server.init_asio();

    // Listen on port 9002
    server.listen(port);
}

/** Listening loop. */
void SocketServer::run() {

    // Start the server accept loop
    server.start_accept();

    // Start the ASIO io_service run loop
    server.run();
}

/** Process incoming message. */
void SocketServer::onMessage(websocketpp::connection_hdl hdl, message_ptr msg) {
    std::cout << "on_message called with hdl: " << hdl.lock().get()
              << " and message: " << msg->get_payload()
              << std::endl;
}
