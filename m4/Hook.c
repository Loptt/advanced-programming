#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

void writeFile(int x, int y) {
    FILE *out = fopen("output.txt", "a");

    fprintf(out, "%d %d\n", x, y);

    fclose(out);
}

int main()
{
    Window window;
    XEvent xevent;
    Display *display;

    if ((display = XOpenDisplay(NULL)) == NULL )
    {
        exit(-1);
    }


    window = DefaultRootWindow(display);
    XAllowEvents(display, AsyncBoth, CurrentTime);

    XGrabPointer(display, window, 1, PointerMotionMask | ButtonPressMask | ButtonReleaseMask, 
        GrabModeAsync, GrabModeAsync, None, None, CurrentTime);

    while(1) {
        XNextEvent(display, &xevent);
        
        if (xevent.type == ButtonPress) {
            writeFile(xevent.xmotion.x_root, xevent.xmotion.y_root);
        }
    }

    return 0;
}
