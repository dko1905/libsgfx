#include <stdio.h>
#include <sgfx.h>

int main() {
	struct sgfx_window *window = sgfx_open(200, 200, "Hello, world!");
	if (window == NULL) {
		perror("Failed to create window");
		return 1;
	}

	do {
		printf("%c ", sgfx_poll(window));
	} while (1);
	sgfx_close(window);

	return 0;
}
