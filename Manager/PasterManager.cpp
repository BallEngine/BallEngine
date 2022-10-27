/*****************************************************************************
FileName:   PasterManager.cpp
Author:     Xeler
Desc:       PasterManager & Paster class code.
******************************************************************************/

#include "PasterManager.h"
#include "../Core/BallEngine.h"

BE_USE

PasterManager::PasterManager(SDL_Texture *basePic) {
    baseScreen = BPaster(basePic);
}

PasterManager::~PasterManager() {
    clear();
}

void PasterManager::processEvent(BEvent event) {

}

PtrNum PasterManager::addPaster(const BPaster &paster) {
    PtrNum point = (PtrNum) (&paster);
    bool valid = checkPasterValid(point);
    while (valid) {
        point++;
        valid = checkPasterValid(point);
    }
    setPaster(point, paster);
    return point;
}

bool PasterManager::removePaster(PtrNum point) {
    bool valid = checkPasterValid(point);
    if (valid) {
        pasterMap.erase(point);
    }
    return valid;
}

void PasterManager::clear() {
    pasterMap.clear();
}

BPaster &PasterManager::operator[](PtrNum point) {
    return getPaster(point);
}

BPaster &PasterManager::getPaster(PtrNum point) {
    bool valid = checkPasterValid(point);
    if (valid) {
        return pasterMap[point];
    }
    return baseScreen;
}

bool PasterManager::setPaster(PtrNum point, const BPaster &paster) {
    std::pair<PtrNum, BPaster> valuePair(point, paster);
    pasterMap.insert(valuePair);
    return valuePair.first;
}

bool PasterManager::checkPasterValid(PtrNum point) {
    return pasterMap.find(point) != pasterMap.end();
}

SDL_Texture PasterManager::drawScreen(unsigned short framesSpace) {
    SDL_Texture newScreen = baseScreen.getFrame();
    auto ic = pasterMap.begin();
    while (ic != pasterMap.end()) {
        newScreen.drawPic(ic->second.getFrame(), 0, 0);
        ic++;
    }
    return newScreen;
}
