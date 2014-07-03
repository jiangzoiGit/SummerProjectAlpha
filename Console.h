#ifndef _MATCH_CONSOLE_H_
#define _MATCH_CONSOLE_H_

#include "Panel.h"
#include "Map.h"

class Console{
public:
    Console();
    void init();
    void draw();
    void play();
private:
    Panel myPanel;
}
#endif 
