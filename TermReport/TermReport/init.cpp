#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"
#include "Setting.h"

/* ”Õ‚ğ‰Šú‰» */
int init(void) {
	int player = readInt("player", "color", "setting.ini", 0);
	int com = readInt("computer", "color", "setting.ini", 0);

	/* ”Õ–Ê‚Ì•\¦ */
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			stone[y][x] = EMPTY;
		}
	}

	/* ”Õ–Ê‚Ì^‚ñ’†‚ÉÎ‚ğ’u‚­ */
	stone[HEIGHT / 2][WIDTH / 2] = BLACK;
	stone[HEIGHT / 2 - 1][WIDTH / 2 - 1] = BLACK;
	stone[HEIGHT / 2 - 1][WIDTH / 2] = WHITE;
	stone[HEIGHT / 2][WIDTH / 2 - 1] = WHITE;

	return 0;
}