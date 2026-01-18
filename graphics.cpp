
#include "graphics.h"
#include <unistd.h>

static Display *display;
static Window window;
static GC gc;
static int screen;
static unsigned long colors[8];

void initgraph(int *gd, int *gm, const char *path) {
  display = XOpenDisplay(NULL);
  screen = DefaultScreen(display);

  window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10,
                               800, 600, 1, BlackPixel(display, screen),
                               WhitePixel(display, screen));

  XSelectInput(display, window, ExposureMask | KeyPressMask);
  XMapWindow(display, window);

  // Wait until window is ready
  XEvent e;
  XWindowAttributes gwa;
  while (1) {
    XNextEvent(display, &e);
    if (e.type == Expose)
      break;
  }

  gc = XCreateGC(display, window, 0, 0);

  Colormap colormap = DefaultColormap(display, screen);
  XColor xcolor;

  const char *names[] = {"black", "blue",    "green", "cyan",
                         "red",   "magenta", "brown", "white"};

  for (int i = 0; i < 8; i++) {
    XParseColor(display, colormap, names[i], &xcolor);
    XAllocColor(display, colormap, &xcolor);
    colors[i] = xcolor.pixel;
  }

  setcolor(WHITE);
}

void closegraph() {
  XFreeGC(display, gc);
  XDestroyWindow(display, window);
  XCloseDisplay(display);
}

void cleardevice() { XClearWindow(display, window); }

void setcolor(int color) { XSetForeground(display, gc, colors[color]); }

void circle(int x, int y, int r) {
  XDrawArc(display, window, gc, x - r, y - r, 2 * r, 2 * r, 0, 360 * 64);
  XFlush(display);
}

void line(int x1, int y1, int x2, int y2) {
  XDrawLine(display, window, gc, x1, y1, x2, y2);
  XFlush(display);
}

void rectangle(int x1, int y1, int x2, int y2) {
  XDrawRectangle(display, window, gc, x1, y1, x2 - x1, y2 - y1);
  XFlush(display);
}

void delay(int ms) { usleep(ms * 1000); }
