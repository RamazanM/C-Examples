#include "graph.c"
#include <time.h>
struct koordinat
{
  int x;
  int y;
};

typedef struct koordinat pozisyon;

main()
{
                                                                            int gd=DETECT,gm;initgraph(&gd,&gm,""); /* initialization of graphic mode */
                                                                            setfillstyle(SOLID_FILL, getmaxcolor());
  srand(time(NULL));
  int i;
  pozisyon gplot[10];

  for(i=0;i<10;i++)
  {
    gplot[i].x=rand()%120+30;
    gplot[i].y=rand()%300+100;
  }

  for(i=0;i<10;i++)
  {
      plot( gplot[i].x , gplot[i].y );
  }
                                                                                    sleep(10);
}
