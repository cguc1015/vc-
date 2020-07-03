#include "stdafx.h"
#include <stdio.h>
#include "OthelloDatabase.h"

/* 結果ファイルを出力する */
void result(const char *fileName) {

	FILE *fp;

	errno_t error;
	error = fopen_s(&fp, fileName, "w");

	/* 白石と黒石をカウント */
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

		/* 結果表示 */
		if (black_count > white_count) {
			fprintf(fp, "あなたの勝利です！！\n");
		}
		else if (white_count > black_count) {
			fprintf(fp, "COMの勝利で...。\n");
		}
		else {
			fprintf(fp, "引き分けです。\n");
		}
		fprintf(fp, "(黒:%d / 白:%d)\n", black_count, white_count);
		fprintf_s(stdout, "対戦結果ファイル(%s)を作成しました.\n", fileName);
	}
	fclose(fp);
}