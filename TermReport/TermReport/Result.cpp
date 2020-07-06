#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"

/* ���ʃt�@�C�����o�͂��� */
void result(const char *fileName) {

	FILE *fp;

	errno_t error;
	error = fopen_s(&fp, fileName, "w");

	/* ���΂ƍ��΂��J�E���g */
	int black_count = 0;
	int white_count = 0;

	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {

		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				if (stone[y][x] == BLACK) {
					black_count++;
				}
				else if (stone[y][x] == WHITE) {
					white_count++;
				}
			}
		}

		/* ���ʕ\�� */
		if (black_count > white_count) {
			fprintf(fp, "���Ȃ��̏����ł��I�I\n");
		}
		else if (white_count > black_count) {
			fprintf(fp, "COMPUTER�̏����ł�...�B\n");
		}
		else {
			fprintf(fp, "���������ł��B\n");
		}
		fprintf(fp, "(��:%d / ��:%d)\n", black_count, white_count);
		fprintf_s(stdout, "�ΐ팋�ʃt�@�C��(%s)���쐬���܂���.\n", fileName);
	}
	fclose(fp);
}