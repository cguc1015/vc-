// TermReport.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"
#include "Init.h"
#include "Display.h"
#include "PutRelation.h"
#include "Player.h"
#include "Computer.h"
#include "Result.h"
#include "NextColor.h"

/* �I�Z���̗��� */
int main(void) {
	Color now, next;

	/* ������ */
	init();
	display();

	/* �ŏ��ɒu���΂̐F */
	now = BLACK;

	/* ���������܂Ŗ������[�v */
	while (1) {

		/* �����͍� */
		if (now == BLACK) {
			play(now);
		}
		/* COMPUTER�͔� */
		else if (now == WHITE) {
			com(now);
		}

		/* �΂�u������̔Օ\�� */
		display();

		/* ���ɒu���΂̐F������ */
		next = nextColor(now);

		/* �u����ꏊ���Ȃ��ꍇ */
		if (next == now) {
			printf("�u����ꏊ������܂���B\n");
		}
		/* �������u���Ȃ��ꍇ */
		else if (next == EMPTY) {
			printf("�����I���ł�\n");

			/* ���ʕ\�����ďI�� */
			result("result.txt");
			return 0;
		}
		/* ���ɒu���΂�ݒ� */
		now = next;
	}
	return 0;
}