#pragma once

/* �Ղ̃T�C�Y */
#define SIZE 8
#define WIDTH SIZE
#define HEIGHT SIZE

/* �΂̐F */
enum Color {
	BLACK,
	WHITE,
	EMPTY
};

/* �Ղ�\���񎟌��z�� */
static Color stone[HEIGHT][WIDTH];

/* �΂�u���邩�ǂ����̔��f */
enum Judge {
	OK,
	NG
};