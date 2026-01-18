
#include "graphics.h"
#include <unistd.h>

static Display *display;
static Window window;
static GC gc;
static int screen;
static unsigned long colors[8];

static XEvent e;

void initgraph(int *gd, int *gm, const char *path) {
  display = XOpenDisplay(NULL);
  if (!display) {
    fprintf(stderr, "Cannot open display\n");
    return;
  }

  screen = DefaultScreen(display);

  window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10,
                               800, 600, 1, BlackPixel(display, screen),
                               WhitePixel(display, screen));

  XSelectInput(display, window, ExposureMask | KeyPressMask);
  XMapWindow(display, window);

  // Wait until window is visible
  XFlush(display);
  usleep(100000); // 0.1s delay
  while (XPending(display))
    XNextEvent(display, &e);

  gc = XCreateGC(display, window, 0, NULL);

  Colormap colormap = DefaultColormap(display, screen);
  XColor xcolor;

  const char *names[] = {"black", "blue",    "green", "cyan",
                         "red",   "magenta", "brown", "white"};

  for (int i = 0; i < 8; i++) {
    XParseColor(display, colormap, names[i], &xcolor);
    XAllocColor(display, colormap, &xcolor);
    colors[i] = xcolor.pixel;
  }

  XSetForeground(display, gc, colors[WHITE]);
  XFlush(display);
}

void closegraph() {
  XFreeGC(display, gc);
  XDestroyWindow(display, window);
  XCloseDisplay(display);
}

void cleardevice() {
  XClearWindow(display, window);
  XFlush(display);
  usleep(10000);
}

void setcolor(int color) { XSetForeground(display, gc, colors[color]); }

void circle(int x, int y, int r) {
  XDrawArc(display, window, gc, x - r, y - r, 2 * r, 2 * r, 0, 360 * 64);
  XFlush(display);
  usleep(10000);
}

void line(int x1, int y1, int x2, int y2) {
  XDrawLine(display, window, gc, x1, y1, x2, y2);
  XFlush(display);
  usleep(10000);
}

void rectangle(int x1, int y1, int x2, int y2) {
  XDrawRectangle(display, window, gc, x1, y1, x2 - x1, y2 - y1);
  XFlush(display);
  usleep(10000);
}

void delay(int ms) { usleep(ms * 1000); }
