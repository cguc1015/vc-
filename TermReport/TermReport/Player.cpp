#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"
#include "PutRelation.h"

/* �v���C���[���΂�u�� */
void play(Color color) {
	int x, y;

	/* �u���ꏊ�����܂�܂Ŗ������[�v */
	while (1) {
		/* �u���ꏊ�̓��͎�t */
		fprintf_s(stdout, "\n");
		fprintf_s(stdout, "�������́H�@");
		scanf_s("%d", &x);
		fprintf_s(stdout, "�c�����́H�@");
		scanf_s("%d", &y);
		fprintf_s(stdout, "\n");

		/* ���͂��ꂽ�ꏊ�ɂ�����Ȃ烋�[�v�𔲂��� */
		if (PutJudge(x, y, color) == OK) {
			break;
		}

		/* ���͂��ꂽ�ꏊ�ɐ΂��u���Ȃ��ꍇ */
		fprintf_s(stdout, "�����ɂ͐΂�u�����Ƃ��ł��܂���B\n");
		fprintf_s(stdout, "���L�ɒu�������ł��܂��B\n");

		/* �u����ꏊ��\�� */
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				if (PutJudge(x, y, color) == OK) {
					fprintf_s(stdout, "(%d, %d)\n", x, y);
				}
			}
		}
	}

	/* �Ō�ɐ΂�u�� */
	put(x, y, color);
}