
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <X11/Xlib.h>
#include <stdio.h>

#define DETECT 0

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define WHITE 7

#ifdef __cplusplus
extern "C" {
#endif

void initgraph(int *gd, int *gm, const char *path);
void closegraph();
void cleardevice();
void setcolor(int color);
void circle(int x, int y, int r);
void line(int x1, int y1, int x2, int y2);
void rectangle(int x1, int y1, int x2, int y2);
void delay(int ms);

#ifdef __cplusplus
}
#endif

#endif
