#include <stdlib.h>
#include <stdio.h>
#include <linux/input.h>
#include <linux/input-event-codes.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

static const char *const event_values[3] = {"RELEASED", "PRESSED", "REPEATED"};
static int queue[10];

void append(int value) {
	for (int i = 1; i < 10; ++i) {
		queue[i - 1] = queue[i];
	}
	queue[9] = value;
}
int main() {
	const char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	struct input_event ev;
	int fd;

	fd = open(dev, O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
	}
	while (1) {
		read(fd, &ev, sizeof ev);
		if (ev.type == EV_KEY && ev.value == 1) {
			append(ev.code);
			if (queue[9] == KEY_E && queue[8] == KEY_P) {
				printf("\n\nI passed the Exam!\n\n");
			}
			if (queue[9] == KEY_P && queue[8] == KEY_A && queue[7] == KEY_C) {
				printf("\n\nGet some cappuccino\n\n");
			}
			if (queue[9] == KEY_A && queue[8] == KEY_N && queue[7] == KEY_W && queue[6] == KEY_I) {
				printf("\n\nI want A!\n\n");
			}
		}
            		
	}
    	fflush(stdout);
    	fprintf(stderr, "%s.\n", strerror(errno));
    	return EXIT_FAILURE;
}
