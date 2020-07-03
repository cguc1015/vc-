#pragma once

/* 盤のサイズ */
#define SIZE 8
#define WIDTH SIZE
#define HEIGHT SIZE

/* 石の色 */
enum Color {
	BLACK,
	WHITE,
	EMPTY
};

/* 盤を表す二次元配列 */
static Color stone[HEIGHT][WIDTH];

/* 石を置けるかどうかの判断 */
enum Judge {
	OK,
	NG
};