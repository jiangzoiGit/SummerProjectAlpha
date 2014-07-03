#ifndef _MATCH_POINT_H_
#define _MATCH_POINT_H_

/*Declaration of Point class*/
class Point{
public:
    Point():x(-1), y(-1){}                  //default constructor
	Point(int _x, int _y):x(_x), y(_y){}	//constructor of Point(x,y)
	Point(const &Point p):x(p.x), y(p.y){}	//constructor of Point(p)
	Point& operator=(const Point& p);		//overwrite of operator "="
	bool operator==(const Point& p);		//overwirte of operator "=="
	bool operator!=(const Point& p);		//overwrite of operator "!="
	int getX() const;						//get the position of row
	int getY() const;						//get the position of column
    int getIndex() const;
	void setX(const int _x);				//set the position of row
	void setY(const int _y);				//set the position of column
private:
   int x,y;								//the position of this point
   int index;                           //the index of this point
};
#endif
