#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"
#include "PutRelation.h"

/* COMPUTER���΂�u�� */
void com(Color color) {
	int x, y;

	/* �u����ꏊ��T�� */
	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH; x++) {

			/* �u����ꍇ���I�� */
			if (PutJudge(x, y, color) == OK) {
				put(x, y, color);
				fprintf_s(stdout, "\n");
				fprintf_s(stdout, "COMPUTER��(%d,%d)�ɐ΂�u���܂����B\n", x, y);
				fprintf_s(stdout, "\n");
				return;
			}
		}
	}
}