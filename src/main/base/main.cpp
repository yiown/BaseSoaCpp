#include <base/Config.h>
#include <base/SocketServer.h>
#include <iostream>

/** Main entry point. */
int main() {
    try {

        Config config("config.ini");
        SocketServer server(config.get<unsigned int>("serverPort"));

        server.run();

    } catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "unknown exception" << std::endl;
    }
}
