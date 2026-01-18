
#include "graphics.h"

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  cleardevice();

  setcolor(RED);
  circle(300, 200, 100);
  // outtextxy(150, 350, (char *)"hello");

  setcolor(GREEN);
  rectangle(100, 100, 200, 200);

  setcolor(BLUE);
  line(50, 50, 400, 400);

  delay(5000); // keep window open 5 seconds
  closegraph();
  return 0;
}
