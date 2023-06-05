/*****************************************************************************
FileName:   BPaster.h
Author:     Xeler
Desc:       Paster class.
******************************************************************************/

#ifndef BALLENGINE_BPASTER_H
#define BALLENGINE_BPASTER_H

#include <vector>
#include <map>
#include <string>

#include <SDL2/SDL.h>

#include "../define.h"

BE_BEGIN

    struct PosPair {
        unsigned int x, y;
    };

    enum PasterAction {
        Click = 0,
        Press,
        Release,
        In,
        Out,
        Listen
    };

    class BPaster {
    public:
        BPaster();

        explicit BPaster(const std::string& defaultTag, SDL_Surface pics[], unsigned int picCount = 1);

        ~BPaster();

        void addPicList(std::string tag, SDL_Surface pics[], unsigned int picCount = 1);

        BPaster &operator=(const BPaster &paster);

        void setFrame(int frameNumber = 1);

        void setPos(PosPair pos);

        SDL_Texture getFrame();

        PosPair getPos();

        void bindAction(PasterAction actionType, std::string actionScript);

    private:
        std::map<std::string, std::vector<SDL_Texture> *> m_textures;

        std::string m_activeTag;

        PosPair m_pasterPos;

        int m_picPoint = 0, m_picNumber = 0;
    };

BE_END

#endif //BALLENGINE_BPASTER_H
