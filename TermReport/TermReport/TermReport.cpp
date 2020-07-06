// TermReport.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
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

/* オセロの流れ */
int main(void) {
	Color now, next;

	/* 初期化 */
	init();
	display();

	/* 最初に置く石の色 */
	now = BLACK;

	/* 決着がつくまで無限ループ */
	while (1) {

		/* 自分は黒 */
		if (now == BLACK) {
			play(now);
		}
		/* COMPUTERは白 */
		else if (now == WHITE) {
			com(now);
		}

		/* 石を置いた後の盤表示 */
		display();

		/* 次に置く石の色を決定 */
		next = nextColor(now);

		/* 置ける場所がない場合 */
		if (next == now) {
			printf("置ける場所がありません。\n");
		}
		/* 両方が置けない場合 */
		else if (next == EMPTY) {
			printf("試合終了です\n");

			/* 結果表示して終了 */
			result("result.txt");
			return 0;
		}
		/* 次に置く石を設定 */
		now = next;
	}
	return 0;
}