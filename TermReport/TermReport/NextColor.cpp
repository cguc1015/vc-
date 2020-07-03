#include "stdafx.h"
#include <stdio.h>
#include "PutRelation.h"

/* 石を置く順番 */
Color nextColor(Color now) {
	Color next;

	/* 次の石の色を他方の色に設定 */
	if (now == WHITE) {
		next = BLACK;
	}
	else {
		next = WHITE;
	}

	/* 次の色の石が置けるかどうかを判断 */
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {

			/* 相手が置ける場合 */
			if (PutJudge(x, y, next) == OK) {
				return next;
			}
		}
	}

	/* 相手が置けない場合自分が置けるか判断 */
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {

			/* 自分が置ける場合 */
			if (PutJudge(x, y, now) == OK) {
				return now;
			}
		}
	}

	/* 両方が場合 */
	return EMPTY;
}