# Linux BGI-style Graphics for C

This project is a **Turbo C++-style graphics system for Linux**, implemented in **C** using **X11**.

It allows you to:

- Draw circles, rectangles, lines, ellipses, arcs
- Set colors
- Clear the screen
- Delay execution
- Animate shapes
- Interact with mouse and keyboard (future upgrades)

All using **Turbo C++-style `graphics.h` functions**.

---

## Features

- `initgraph(&gd, &gm, path)` – Initialize graphics window
- `closegraph()` – Close graphics window
- `cleardevice()` – Clear screen
- `setcolor(color)` – Set current drawing color
- `circle(x, y, r)` – Draw a circle
- `line(x1, y1, x2, y2)` – Draw a line
- `rectangle(x1, y1, x2, y2)` – Draw a rectangle
- `delay(ms)` – Pause execution

---

## Colors

| Constant | Color   |
| -------- | ------- |
| BLACK    | Black   |
| BLUE     | Blue    |
| GREEN    | Green   |
| CYAN     | Cyan    |
| RED      | Red     |
| MAGENTA  | Magenta |
| BROWN    | Brown   |
| WHITE    | White   |

---

## Files

- `graphics.h` → Header file with function declarations
- `graphics.c` → Implementation using X11
- `main.c` → Example C program using graphics functions

---

## Installation (Arch Linux)

1. Install **X11 development libraries**:

```bash
sudo pacman -S libx11
```

1. Place `graphics.h`, `graphics.c`, and your `main.c` in the **same folder**.

---

## Compilation

Compile your C program with **gcc**:

```bash
gcc main.c graphics.c -lX11 -o app
```

Explanation:

- `main.c` → Your program
- `graphics.c` → Our graphics library
- `-lX11` → Link to X11 library
- `-o app` → Output executable

---

## Running

```bash
./app
```

A window will open. You should now see your shapes appear.

---

## Example Program

```c
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

    delay(5000); // keep window open for 5 seconds
    closegraph();
    return 0;
}
```

✅ Expected: red circle, green rectangle, blue line in a single window.

---

## Tips for Learning

1. Start with **simple shapes** (`circle`, `line`, `rectangle`)
2. Combine colors with `setcolor()`
3. Use `cleardevice()` to clear the screen for animations
4. Use loops with `delay()` to make animations
5. Once comfortable, you can implement:
   - `ellipse()`
   - `arc()`
   - `floodfill()`
   - `outtextxy()`
   - Keyboard and mouse input

---

## Example: Moving Circle Animation

```c
#include "graphics.h"

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    for (int x = 50; x < 500; x += 5) {
        cleardevice();
        setcolor(RED);
        circle(x, 300, 50);
        delay(50);
    }

    closegraph();
    return 0;
}
```

✅ Teaches clearing and redrawing for animations.

---

## Why this Works on Linux

- Classic `graphics.h` from Turbo C++ is **Windows-only**
- `libgraph` and other BGI libraries often **fail on modern Linux**
- This implementation uses **X11**, which is **native to Linux**
- No broken dependencies, fully compatible with C
