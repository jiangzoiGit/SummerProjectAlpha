#ifndef _MATCH_CONFIGURE_H_
#define _MATCH_CONFIGURE_H_

#include <cstdlib>
#include <ctime>
double random(double start,double finish)
{
    return start+(finish-start)*rand()/(RAND_MAX + 1.0);
}
const int MapRow = 14;
const int MapColumn = 15;
const int TOTALPOINT = MapRow * MapColumn;
const int DIRECTION = 4;
/* four direction of superPoint */
const int direct[2][4]={{1,0,-1,0},
                        {0,1,0,-1}}
class ErrorSign{};
#endif
