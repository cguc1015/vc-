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

/* ƒ}ƒX•\¦ */
int displaySquare(Color square) {

	switch (square) {

		/* •F‚ÌÎ‚Í "Z" ‚Å•\¦ */
	case BLACK:
		printf("Z");
		break;

		/* ”’F‚ÌÎ‚Í "œ" ‚Å•\¦ */
	case WHITE:
		printf("œ");
		break;

		/* ‹ó‚«‚Í " " ‚Å•\¦ */
	case EMPTY:
		printf("@");
		break;
	}
	return 0;
}

/* ”Õ‚ğ•\¦ */
int display(void) {
	int x, y;

	for (y = 0; y < HEIGHT; y++) {

		/* ‰¡”Ô†•\¦ */
		if (y == 0) {
			printf(" ‚O‚P‚Q‚R‚S‚T‚U‚V\n");
		}

		/* ”Õ”Ô†•\¦ */
		for (x = 0; x < WIDTH; x++) {
			if (x == 0) {
				printf("%d", y);
			}

			/* Îî•ñ•\¦ */
			displaySquare(stone[y][x]);
		}
		printf("\n");
	}

	return 0;
}