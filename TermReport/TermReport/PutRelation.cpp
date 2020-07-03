#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"

/* 指定した場所に石を置く */
int put(int x, int y, Color color) {

	Color other;

	/* 相手の石の色 */
	if (color == BLACK) {
		other = WHITE;
	}
	else if (color == WHITE) {
		other = BLACK;
	}
	else {
		return -1;
	}

	/* 全方向に対して挟んだ石をひっくり返す */
	for (int j = -1; j < 2; j++) {
		for (int i = -1; i < 2; i++) {

			/* 真ん中は置いた場所なので判断不要 */
			if (i == 0 && j == 0) {
				continue;
			}

			/* 隣が相手の色でなければ判断不要 */
			if (stone[y + j][x + i] != other) {
				continue;
			}

			/* 置こうとしているマスから遠い方向へ１マスずつ確認 */
			for (int m = 2; m < SIZE; m++) {

				/* 盤面外のマスはチェックしない */
				if (0 <= x + i * m && x + i * m < WIDTH && 0 <= y + j * m && y + j * m < HEIGHT) {

					/* 空きが見つかる場合終了 */
					if (stone[y + j * m][x + i * m] == EMPTY) {
						break;
					}

					/* 自分の色の石がある */
					if (stone[y + j * m][x + i * m] == color) {

						/* 石を置く */
						stone[y][x] = color;

						/* 挟んだ石をひっくり返す */
						for (int n = 1; n < m; n++) {
							stone[y + j * n][x + i * n] = color;
						}
					}
				}
			}
		}
	}

	return 0;
}

/* 指定した場所に石を置けるか判断 */
Judge PutJudge(int x, int y, Color color) {

	Color other;
	int count = 0;

	/* 石が置いてある場合 */
	if (stone[y][x] != EMPTY) {
		return NG;
	}

	/* 相手の石の色 */
	if (color == BLACK) {
		other = WHITE;
	}
	else if (color == WHITE) {
		other = BLACK;
	}
	else {
		return NG;
	}

	/* 全方向に対して挟んだ石を確認 */
	for (int j = -1; j < 2; j++) {
		for (int i = -1; i < 2; i++) {

			/* 真ん中方向は判断不要 */
			if (i == 0 && j == 0) {
				continue;
			}

			/* 隣が相手の色でない場合判断不要 */
			if (stone[y + j][x + i] != other) {
				continue;
			}

			/* 置こうとしているマスから遠い方向へ１マスずつ確認 */
			for (int m = 2; m < SIZE; m++) {

				/* 盤面外のマスは判断不要*/
				if (0 <= x + i * m && x + i * m < WIDTH && 0 <= y + j * m && y + j * m < HEIGHT) {

					/* 空きが見つかる場合終了 */
					if (stone[y + j * m][x + i * m] == EMPTY) {
						break;
					}

					/* 自分の色の石がある場合 */
					if (stone[y + j * m][x + i * m] == color) {

						/* 石がひっくり返る方向をカウント */
						count++;
					}
				}
			}
		}
	}

	if (count == 0) {
		return NG;
	}

	return OK;
}