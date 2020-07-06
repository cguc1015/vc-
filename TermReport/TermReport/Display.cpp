#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"


/* �΂�\�� */
int displaySquare(Color square) {

	switch (square) {

		/* ���F�̐΂� "�Z" �ŕ\�� */
	case BLACK:
		printf("�Z");
		break;

		/* ���F�̐΂� "��" �ŕ\�� */
	case WHITE:
		printf("��");
		break;

		/* �󂫂� " " �ŕ\�� */
	case EMPTY:
		printf("�@");
		break;
	}
	return 0;
}

/* �Ղ�\�� */
int display(void) {
	int x, y;

	for (y = 0; y < HEIGHT; y++) {

		/* �����W�\�� */
		if (y == 0) {
			printf(" �O�P�Q�R�S�T�U�V\n");
		}

		/* �c���W�\�� */
		for (x = 0; x < WIDTH; x++) {
			if (x == 0) {
				printf("%d", y);
			}

			/* �Ώ��\�� */
			displaySquare(stone[y][x]);
		}
		printf("\n");
	}

	return 0;
}