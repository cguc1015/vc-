#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"
#include "Setting.h"

/* 盤を初期化 */
int init(void) {
	
	/* 盤面の範囲確保 */
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			stone[y][x] = EMPTY;
		}
	}

	/* 盤面の真ん中に石を置く */
	stone[HEIGHT / 2][WIDTH / 2] = BLACK;
	stone[HEIGHT / 2 - 1][WIDTH / 2 - 1] = BLACK;
	stone[HEIGHT / 2 - 1][WIDTH / 2] = WHITE;
	stone[HEIGHT / 2][WIDTH / 2 - 1] = WHITE;

	return 0;
}