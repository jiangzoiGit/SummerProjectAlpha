#ifndef _MATCH_MAP_H_
#define _MATCH_MAP_H_
namespace Map{
class ERROR{};
}

struct Map{
    Map():map(NULL),row(-1),column(-1){}
    Map(int _row, int _column):row(_row),column(_column){
        if (map!=NULL) delete map;
        map = new int[(row+2)*(column+2)];     // for the convenience of Algorithm of PathChecker.
        if (map == NULL) throw Map::ERROR;
        for (int i=0;i<row+2;i++)
            for (int j=0;j<column+2;j++)
                map[i][j] = 0;
    }
    ~Map(){
        if (map!=NULL) delete map;
    }
    int *map;
    int row;
    int column;
};

#endif
