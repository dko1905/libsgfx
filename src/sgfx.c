#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>

#include "sgfx.h"

/* Types */
struct sgfx_window {
	Display *display;
	Window window;
	GC gc;
};
/* Globals */
static long event_mask = 1L << 17;

/* Functions */
struct sgfx_window *sgfx_open(uint32_t width, uint32_t height, const char *title) {
	struct sgfx_window *window = malloc(sizeof(struct sgfx_window));
	if (window == NULL) {
		goto malloc_err;
	}

	/* Create display. */
	window->display = XOpenDisplay(NULL); /* Open default display. */
	if (window->display == NULL) {
		goto display_err;
	}

	/* Select screen number & basic colors. */
	int screenNumber = XDefaultScreen(window->display);
	unsigned long color_white = XWhitePixel(window->display, screenNumber);
	unsigned long color_black = XWhitePixel(window->display, screenNumber);

	/* Create window. */
	window->window = XCreateSimpleWindow(window->display,
                                        XDefaultRootWindow(window->display),
                                        50, 50,
                                        width, height,
                                        0, color_black,
                                        color_white);
	if (window->window < 0) {
		goto window_err;
	}
	XMapWindow(window->display, window->window);

	/* Select input/ */
	XSelectInput(window->display, window->window, event_mask);

	/* Create graphics context. */
	window->gc = XCreateGC(window->display, window->window, 0, NULL);
	if (window->gc < 0) {
		goto gc_err;
	}
	XSetForeground(window->display, window->gc, color_white);

	/* Done setting up X11. */
	return window;

	XFreeGC(window->display, window->gc);
gc_err:
window_err:
	XCloseDisplay(window->display);
display_err:
	free(window);
malloc_err:
	return NULL;
}

void sgfx_close(struct sgfx_window *window) {
	XFreeGC(window->display, window->gc);
	XCloseDisplay(window->display);
	free(window);
}

char sgfx_poll(struct sgfx_window *window) {
	XEvent e;
	do {
		XNextEvent(window->display, &e);
		printf("D\n");
		if (e.type == 2) /* KeyPress */
			return XLookupKeysym(&e.xkey, 0);
		else if (e.type == 4) /* ButtonPress */
			return e.xbutton.button;
	} while (e.type != 19); /* != MapNotify */
	return 0;
}
