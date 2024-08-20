#include "WindowMgr.h"

CurrWindow* WindowMgr::getWindow(int width, int height, const std::string &title){
    return new CurrWindow(width, height, title);
}


