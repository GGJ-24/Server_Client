//Chat Client
#include "clientnetwork.hpp"

int main(int argc, char * argv[]){
     ClientNetwork client_network;
     client_network.Connect("localHost", 2525);
     std::thread packetThread([&client_network]()
                              { client_network.ReceivePackets(&client_network.socket); });
     std::thread clientThread([&client_network]()
                              { client_network.Run(); });
     clientThread.join();
     packetThread.join();
     return 0;
}
