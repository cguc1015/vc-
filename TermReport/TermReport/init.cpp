#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"
#include "Setting.h"

/* �Ղ������� */
int init(void) {
	int player = readInt("player", "color", "setting.ini", 0);
	int com = readInt("computer", "color", "setting.ini", 0);

	/* �Ֆʂ̕\�� */
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			stone[y][x] = EMPTY;
		}
	}

	/* �Ֆʂ̐^�񒆂ɐ΂�u�� */
	stone[HEIGHT / 2][WIDTH / 2] = BLACK;
	stone[HEIGHT / 2 - 1][WIDTH / 2 - 1] = BLACK;
	stone[HEIGHT / 2 - 1][WIDTH / 2] = WHITE;
	stone[HEIGHT / 2][WIDTH / 2 - 1] = WHITE;

	return 0;
}