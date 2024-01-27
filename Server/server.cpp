// Chat Server
#include "servernetwork.hpp"

int main(int argc, char *argv[])
{
     ServerNetwork server_network(2525);
     std::thread packetThread([&server_network]()
                              { server_network.ManagePackets(); });
     std::thread clientThread([&server_network]()
                              { server_network.ConnectClients(&server_network.client_array); });
     clientThread.join();
     packetThread.join();
     return 0;
}
