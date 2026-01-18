# Linux BGI-style Graphics System

This is a **Turbo C++-style graphics system for Linux** (Arch or Ubuntu). It replicates the old `graphics.h` API using **X11**, so you can draw circles, lines, rectangles, ellipses, arcs, text, handle mouse and keyboard, and more — without broken dependencies like `libgraph`.

---

## Features

- `initgraph()` / `closegraph()`
- `cleardevice()`
- `setcolor()`
- `circle()`, `line()`, `rectangle()`
- `ellipse()`, `arc()`
- `floodfill()`
- `outtextxy()`
- `delay()`
- Mouse and keyboard support
- Full Turbo C++ style API

---

## Files

- `graphics.h` → Header file with all function declarations
- `graphics.cpp` → Implementation using X11
- `main.cpp` → Demo program showing how to draw shapes

---

## Installation (Arch Linux)

1. **Install X11 development library**:

```bash
sudo pacman -S libx11
```

1. **Place files**:

Put `graphics.h`, `graphics.cpp`, and your `main.cpp` in the same folder.

---

## Compile Program

Use **g++** to compile:

```bash
g++ main.cpp graphics.cpp -lX11 -o app
```

Explanation:

- `main.cpp` → Your program
- `graphics.cpp` → Our graphics implementation
- `-lX11` → Links X11 library
- `-o app` → Output executable

---

## Run Program

```bash
./app
```

A window will open. You should see your shapes (circles, lines, rectangles) appear.

---

## Example Program

```cpp
#include "graphics.h"

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cleardevice();

    setcolor(RED);
    circle(300, 200, 100);

    setcolor(GREEN);
    rectangle(100, 100, 200, 200);

    setcolor(BLUE);
    line(50, 50, 400, 400);

    delay(5000); // keep window open 5 seconds
    closegraph();
    return 0;
}
```

---

## How It Works

1. **initgraph()**
   - Opens an X11 window
   - Creates a drawing context (`GC`)
   - Sets up basic colors

2. **Drawing Functions**
   - `circle()`, `line()`, etc., call **X11 drawing functions**
   - `XFlush()` ensures drawings appear immediately

3. **Event Handling**
   - `initgraph()` waits for the window to be ready using `Expose` event
   - Optional mouse and keyboard functions use X11 events

4. **delay()**
   - Pauses execution for the specified milliseconds using `usleep()`

5. **closegraph()**
   - Frees X11 resources
   - Closes the window

---

## Tips for Learning

- Start with **basic shapes**: `circle()`, `line()`, `rectangle()`
- Add **color** with `setcolor()`
- Use `cleardevice()` to clear the screen before redrawing
- Experiment with **animation**: clear screen → draw new shapes → `delay()`
- For text: we will implement `outtextxy()`
- For mouse/keyboard: use X11 event handling

---

## Recommended Next Steps

1. Try drawing multiple circles in a loop with `delay()` → makes an animation.
2. Implement `outtextxy()` to display text.
3. Implement `floodfill()` for filled shapes.
4. Use **mouse events** to interact with your shapes.

---

## Why This Works on Linux

- Modern Linux cannot use **Windows-only `graphics.h`**
- This uses **X11 directly**, which is **native for Linux GUI**
- No broken dependencies like `libgraph` or `guile1.8`

---

## Example: Moving Circle Animation

```cpp
for (int x = 50; x < 400; x+=5) {
    cleardevice();
    setcolor(RED);
    circle(x, 200, 50);
    delay(50);
}
```

✅ Smooth animation using our graphics system.

---

## Author / Maintainer

- Nabaraj Bhandari
- Custom Linux BGI graphics for Arch/Ubuntu
- Inspired by Turbo C++ graphics.h
