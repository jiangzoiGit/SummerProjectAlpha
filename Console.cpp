#include "Console.h"
#include "Map.h"
#include "Configure.h"
#include <stdio.h>

void Console::init(){
    srand(unsigned(time(0)));
    for (int i=1;i<=MapRow;i++)
        for (int j=1;j<=MapColumn;j++)
            myPanel.AddPoint(i,j,int(random(1,9)));
}

void Console::draw(){
    for (int i=1;i<=MapRow;i++)
    {
        for (int j=1;j<=MapColumn;j++)
        {
            if (myPanel.getInfo(i,j) != 0)
                printf("%d\t",myPanel.getInfo(i,j));
            else
                printf("\t");
        }
        printf("\n");
    }
}

void Console::play(){
    printf("Please give me your choose:\n");
    int x1,y1,x2,y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (myPanel.judgePath(Point(x1,y1),Point(x2,y2)))
    {
        myPanel.DeletePoint(x1,y1);
        myPanel.DeletePoint(x2,y2);
    }

}

Console::Console()
    :myPanel(MapRow,MapColumn)
{
    init();
    try{
        while (!myPanel.judgeVictory()){
            draw();
            play();
            
        }

    }
    catch(...){
        
    }
}
