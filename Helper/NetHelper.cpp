/*****************************************************************************
FileName:   NetHelper.cpp
Creater:    Xeler
Desc:       Build.
Version:    0.1
******************************************************************************/


#include "NetHelper.h"

using namespace be;

NetHelper::NetHelper(unsigned int port, BString ip) {
    connectSocket = socket(AF_INET, SOCK_DGRAM, 0);
    runtime = true;
    memset(&connectAddress, 0, sizeof(sockaddr_in));
    connectAddress.sin_addr.S_un.S_addr = htonl(inet_addr(ip.toCStyleStr()));
    connectAddress.sin_port = htons(port);
    runtime = bind(connectSocket, (sockaddr *) &connectAddress, sizeof(sockaddr_in));
    runtime = runtime && listen(connectSocket, SOMAXCONN);
}

void NetHelper::serverStart() {

}

void NetHelper::clientStart() {
    
}

void NetHelper::close() {

}

bool NetHelper::isCrash() {
    return true;
}

bool NetHelper::sendMessage(BString message) {
    return true;
}

BString NetHelper::getMessage() {
    return BString();
}
