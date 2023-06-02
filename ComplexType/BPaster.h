/*****************************************************************************
FileName:   BPaster.h
Author:     Xeler
Desc:       Paster class.
******************************************************************************/

#ifndef BALLENGINE_BPASTER_H
#define BALLENGINE_BPASTER_H

#include <vector>
#include <string>

#include <SDL2/SDL.h>

#include "../define.h"

BE_BEGIN
    enum PasterAction {
        Click = 0,
        Press,
        Release,
        In,
        Out
    };

    class BPaster {
    public:
        BPaster();

        explicit BPaster(SDL_Texture pics[], unsigned int picCount = 1);

        ~BPaster();

        BPaster &operator=(const BPaster &paster);

        void frameControl(int frameNumber = 1);

        SDL_Texture getFrame();

        void setPosition(unsigned short posX, unsigned short posY);

        void movePasterTo(unsigned short posX, unsigned short posY);

        void bindAction(PasterAction actionType, std::string actionScript);

    private:
        std::vector<SDL_Texture> pictures;
        int picPoint = 0, picNumber = 0;
    };

BE_END

#endif //BALLENGINE_BPASTER_H
