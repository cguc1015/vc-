#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"

/* �w�肵���ꏊ�ɐ΂�u�� */
int put(int x, int y, Color color) {

	Color other;

	/* ����̐΂̐F */
	if (color == BLACK) {
		other = WHITE;
	}
	else if (color == WHITE) {
		other = BLACK;
	}
	else {
		return -1;
	}

	/* �S�����ɑ΂��ċ��񂾐΂��Ђ�����Ԃ� */
	for (int j = -1; j < 2; j++) {
		for (int i = -1; i < 2; i++) {

			/* �^�񒆂͒u�����ꏊ�Ȃ̂Ŕ��f�s�v */
			if (i == 0 && j == 0) {
				continue;
			}

			/* �ׂ�����̐F�łȂ���Δ��f�s�v */
			if (stone[y + j][x + i] != other) {
				continue;
			}

			/* �u�����Ƃ��Ă���}�X���牓�������ւP�}�X���m�F */
			for (int m = 2; m < SIZE; m++) {

				/* �ՖʊO�̃}�X�̓`�F�b�N���Ȃ� */
				if (0 <= x + i * m && x + i * m < WIDTH && 0 <= y + j * m && y + j * m < HEIGHT) {

					/* �󂫂�������ꍇ�I�� */
					if (stone[y + j * m][x + i * m] == EMPTY) {
						break;
					}

					/* �����̐F�̐΂����� */
					if (stone[y + j * m][x + i * m] == color) {

						/* �΂�u�� */
						stone[y][x] = color;

						/* ���񂾐΂��Ђ�����Ԃ� */
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

/* �w�肵���ꏊ�ɐ΂�u���邩���f */
Judge PutJudge(int x, int y, Color color) {

	Color other;
	int count = 0;

	/* �΂��u���Ă���ꍇ */
	if (stone[y][x] != EMPTY) {
		return NG;
	}

	/* ����̐΂̐F */
	if (color == BLACK) {
		other = WHITE;
	}
	else if (color == WHITE) {
		other = BLACK;
	}
	else {
		return NG;
	}

	/* �S�����ɑ΂��ċ��񂾐΂��m�F */
	for (int j = -1; j < 2; j++) {
		for (int i = -1; i < 2; i++) {

			/* �^�񒆕����͔��f�s�v */
			if (i == 0 && j == 0) {
				continue;
			}

			/* �ׂ�����̐F�łȂ��ꍇ���f�s�v */
			if (stone[y + j][x + i] != other) {
				continue;
			}

			/* �u�����Ƃ��Ă���}�X���牓�������ւP�}�X���m�F */
			for (int m = 2; m < SIZE; m++) {

				/* �ՖʊO�̃}�X�͔��f�s�v*/
				if (0 <= x + i * m && x + i * m < WIDTH && 0 <= y + j * m && y + j * m < HEIGHT) {

					/* �󂫂�������ꍇ�I�� */
					if (stone[y + j * m][x + i * m] == EMPTY) {
						break;
					}

					/* �����̐F�̐΂�����ꍇ */
					if (stone[y + j * m][x + i * m] == color) {

						/* �΂��Ђ�����Ԃ�������J�E���g */
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