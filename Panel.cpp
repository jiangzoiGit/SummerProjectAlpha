#include "Panel.h"
#include "Configure.h"

Panel::Panel():myMap(),count(0){} //default constructor

Panel::Panel(const int _row, const int _column):myMap(_row,_column),count(0){}   //constructor

void Panel::AddPoint(const Point& p, const int _row, const int _column)
{
    if (_row <= 0 || _column <=0 || _row > myMap.row || _column > myMap.column)
        /* out of range */
        throw ErrorSign(); 
    if (myMap.map[_row][_column] != 0)
        /* already have point */
        throw ErrorSign();
    myMap.map[_row][_column] = p.getIndex();
    ++count;
}

void Panel::DeletePoint(const int _row, const int _column)
{
    if (_row <= 0 || _column <=0 || _row > myMap.row || _column > myMap.column)
        /* out of range */
        throw ErrorSign();
    if (myMap.map[_row][_column] == 0)
        /* there is no point */
        throw ErrorSign();
    myMap.map[_row][_column] = 0;
    --count;
}

bool Panel::judgePath(const Point& start, const Point& finish)
{
    if (start.getX() <= 0 || start.getY() <= 0 || start.getX() > myMap.row || start.getY() > myMap.column
    ||  finish.getX() <= 0 || finish.getY() <= 0 || finish.getX() > myMap.row || finish.getY() > myMap.column)
        throw ErrorSign();

    for (int i=0;i<MapRow;i++)
        for (int j=0;j<MapColumn;j++)
            for (int k=0;k<DIRECTION;k++)
                f[i][j][k] = 3;
    while (que.size()>0) que.pop();
    for (int k=0;k<DIRECTION;k++)
    {
        f[start.getX()][start.getY()][k] = 0;
        que.push(superPoint(start.getX(),start.getY(),k));
    }
    int tempValue;
    while (que.size()>0){
        superPoint now(que.front().getX(),que.front().getY(),que.front().index);
        for (int k=0;k<DIRECTION;k++)
        {
            int nextX = now.getX() + direct[0][k];
            int nextY = now.getY() + direct[1][k];
            if (myMap.map[nextX][nextY] == 0){
                if (now.index == k) 
                    tempValue = f[now.getX()][now.getY()][now.index];
                else 
                    tempValue = f[now.getX()][now.getY()][now.index]+1;
                if (tempValue < f[nextX][nextY][k])
                {
                    f[nextX][nextY][k] = tempValue;
                    que.push(superPoint(nextX,nextY,k));
                    if (nextX == finish.getX() && nextY == finish.getY())
                        return true;
                }
            }
        }
        que.pop();
    } 
    return false;
}

bool Panel::judgeVictory()
{
    return (count == 0);
}

int Panel::getInfo(const int _row, const int _column){

}
