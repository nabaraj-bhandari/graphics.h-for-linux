
#include "graphics.h"

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  cleardevice(); // optional

  setcolor(RED);
  circle(300, 200, 100);

  setcolor(GREEN);
  rectangle(100, 100, 200, 200);

  setcolor(BLUE);
  line(50, 50, 400, 400);

  delay(5000);
  closegraph();
  return 0;
}
