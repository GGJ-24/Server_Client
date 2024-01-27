// Chat Server
#include "servernetwork.hpp"

void runLoop(ServerNetwork& serverNetwork)
{
     while(true)
     {
          
     }
}

int main(int argc, char *argv[])
{
     ServerNetwork server_network(2525);
     std::thread packetThread([&server_network]()
                              { server_network.ManagePackets(); });
     std::thread clientThread([&server_network]()
                              { server_network.ConnectClients(&server_network.client_array); });
     runLoop(server_network);
     clientThread.detach();
     packetThread.detach();
     return 0;
}
