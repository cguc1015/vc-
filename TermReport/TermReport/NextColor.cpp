#include "stdafx.h"
#include <stdio.h>
#include "PutRelation.h"

/* �΂�u������ */
Color nextColor(Color now) {
	Color next;

	/* ���̐΂̐F�𑼕��̐F�ɐݒ� */
	if (now == WHITE) {
		next = BLACK;
	}
	else {
		next = WHITE;
	}

	/* ���̐F�̐΂��u���邩�ǂ����𔻒f */
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {

			/* ���肪�u����ꍇ */
			if (PutJudge(x, y, next) == OK) {
				return next;
			}
		}
	}

	/* ���肪�u���Ȃ��ꍇ�������u���邩���f */
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {

			/* �������u����ꍇ */
			if (PutJudge(x, y, now) == OK) {
				return now;
			}
		}
	}

	/* �������ꍇ */
	return EMPTY;
}