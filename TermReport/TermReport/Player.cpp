#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"
#include "PutRelation.h"

/* プレイヤーが石を置く */
void play(Color color) {
	int x, y;

	/* 置く場所が決まるまで無限ループ */
	while (1) {
		/* 置く場所の入力受付 */
		fprintf_s(stdout, "\n");
		fprintf_s(stdout, "横方向は？　");
		scanf_s("%d", &x);
		fprintf_s(stdout, "縦方向は？　");
		scanf_s("%d", &y);
		fprintf_s(stdout, "\n");

		/* 入力された場所におけるならループを抜ける */
		if (PutJudge(x, y, color) == OK) {
			break;
		}

		/* 入力された場所に石が置けない場合 */
		fprintf_s(stdout, "そこには石を置くことができません。\n");
		fprintf_s(stdout, "下記に置く事ができます。\n");

		/* 置ける場所を表示 */
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				if (PutJudge(x, y, color) == OK) {
					fprintf_s(stdout, "(%d, %d)\n", x, y);
				}
			}
		}
	}

	/* 最後に石を置く */
	put(x, y, color);
}