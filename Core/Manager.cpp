/*****************************************************************************
FileName:   Manager.cpp
Creater:    Xeler
Desc:       Manager Code.
Version:    0.1
******************************************************************************/

#include "Manager.h"

BE_USE

BEvent::BEvent(ManagerType whereFrom, ManagerType wantTo, BString eventMessage) {
    from = whereFrom;
    to = wantTo;
    data = eventMessage;
}

Manager::Manager() {
}

void Manager::processEvent(BEvent event) {

}
