#ifndef SGFX_H
#define SGFX_H
#include <stdint.h>

struct sgfx_window;

/**
 * @brief Open a new graphics window.
 * @param width Width of the new window.
 * @param height Height of the new window.
 * @param title Title of the new widnow.
 * @return Returns a `sgfx_window` pointer on success, or `NULL`.
 */
struct sgfx_window *sgfx_open(uint32_t width, uint32_t height, const char *title);

/**
 * @brief Close/free an opened window.
 * @param window Pointer to the `sgfx_window` struct.
 */
void sgfx_close(struct sgfx_window *window);

/**
 * @brief Poll for events.
 * @param window Pointer to the `sgfx_window` struct.
 * @return Event cast to a char.
 */
char sgfx_poll(struct sgfx_window *window);


/**
 * @brief Draw a point at (x,y).
 * @return 0 on success and -1 on error.
 */
int sgfx_point(uint32_t x, uint32_t y);

/**
 * @brief Draw line on window, from (x1,y1) to (x2,y2).
 * @param x1 Coordinate pair of the start of the line.
 * @param y1 Coordinate pair of the start of the line.
 * @param x2 Coordinate pair of the stop of the line.
 * @param y2 Coordinate pair of the stop of the line.
 * @return 0 on success and -1 on error.
 */
int sgfx_line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);

/**
 * @brief Clear screen.
 * @return 0 on success and -1 on error.
 */
int sgfx_clear();

/**
 * @brief Set clear color.
 * @return 0 on success and -1 on error.
 */
int sgfx_clear_color(uint8_t red, uint8_t green, uint8_t blue);

/**
 * @brief Wait until a mouse or key event.
 * @return Returns event as a `char`.
 */
char sgfx_wait();



#endif
