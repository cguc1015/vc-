#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"
#include "PutRelation.h"

/* COMPUTERが石を置く */
void com(Color color) {
	int x, y;

	/* 置ける場所を探索 */
	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH; x++) {

			/* 置ける場合即終了 */
			if (PutJudge(x, y, color) == OK) {
				put(x, y, color);
				fprintf_s(stdout, "\n");
				fprintf_s(stdout, "COMPUTERが(%d,%d)に石を置きました。\n", x, y);
				fprintf_s(stdout, "\n");
				return;
			}
		}
	}
}