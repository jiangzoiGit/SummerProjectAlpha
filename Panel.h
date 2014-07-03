#ifndef _MATCH_PANEL_H_
#define _MATCH_PANEL_H_

#include <queue>
#include "Point.h"
#include "Map.h"
#include "Configure.h"

/* Core function    bool judge(Point& start, Point& finish)
 * Algorithm:       SPFA 
 * Input:           the Pointer of map && start Point && finish Point
 * Output:          true - there is at least one accessable path between start and finish Points
 *                  false - there is no accessable path between start and finish Points
 */

class superPoint : public Point
{
public:
    superPoint():Point(),index(-1){}
    superPoint(const int _row, const int _column, const int _index):Point(_row,_column), index(_index){}
    int getX(){ return Point::getX();}
    int getY(){ return Point::getY();}
    int index;
};

class Panel{
public:
    Panel();
    Panel(const int _row, const int _column);
    void AddPoint(const Point& p, const int _row, const int _column);    //add point into Panel
    void DeletePoint(const int _row, const int _column);                 //delete point out of Panel

    bool judgePath(const Point& start, const Point& finish);                    //judge whether there is a path between tow point;
    bool judgeVictory();    //judge whether the game achieve the victory state
    int getInfo(const int _row, const int _column);
private:
    queue<superPoint> que;      // the queue of Point
    Map myMap;              // the map of this Panel
    int count;              // the number of point left
    int f[MapRow][MapColumn][DIRECTION];                 //function for SPFA
};

#endif
