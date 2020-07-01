// report10.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include<Windows.h>
#include<mmsystem.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include "Setting.h"

#define NUMTHREAD 2
#define USEMUTEX

struct Consumer {
	char* name;
	int moveTime;
	int homeTime;
	int buyTime;
	int purchase;
	int numBought;
};

struct shop {
	int numBought;
	int appleSum;
};

char currentDirectory[CHARBUFF];
char settingFile[CHARBUFF];
HANDLE threadMutexA;
HANDLE threadMutexB;

std::vector<int> threadQueue;

shop shop1;
Consumer consumer1;
Consumer consumer2;

void processA() {
	consumer1.name = "sakura";
	consumer1.numBought = 0;

	char section[CHARBUFF];
	sprintf_s(section, "consumer1");

	char keyWord[CHARBUFF];

	sprintf_s(keyWord, "moveTime");
	consumer1.moveTime = getIntFromINI(section, keyWord, settingFile, -1);

	sprintf_s(keyWord, "homeTime");
	consumer1.homeTime = getIntFromINI(section, keyWord, settingFile, -1);

	sprintf_s(keyWord, "buyTime");
	consumer1.buyTime = getIntFromINI(section, keyWord, settingFile, -1);

	sprintf_s(keyWord, "purchase");
	consumer1.purchase = getIntFromINI(section, keyWord, settingFile, -1);

	while (shop1.numBought < shop1.appleSum) {
		Sleep(consumer1.moveTime);

		WaitForSingleObject(threadMutexA, INFINITE);

		Sleep(consumer1.buyTime);
		int prev = shop1.numBought;
		if (shop1.numBought <= shop1.appleSum - consumer1.purchase) {
			shop1.numBought += consumer1.purchase;
			consumer1.numBought += consumer1.purchase;
		}
		else {
			consumer1.numBought += shop1.appleSum - shop1.numBought;
			shop1.numBought = shop1.appleSum;
		}

		fprintf_s(stdout, "finish thread%s process %d -> %d\n", consumer1.name, prev, shop1.numBought);
		fprintf_s(stdout, "%s apple sum = %d\n", consumer1.name, consumer1.numBought);
		fprintf_s(stdout, "\n");

		ReleaseMutex(threadMutexB);
		Sleep(consumer1.moveTime + consumer1.homeTime);

	}
	fprintf_s(stdout, "finish all\n\n");
}

void processB() {
	consumer2.name = "tomoyo";

	consumer2.numBought = 0;

	char section[CHARBUFF];
	sprintf_s(section, "consumer2");

	char keyWord[CHARBUFF];

	sprintf_s(keyWord, "moveTime");
	consumer2.moveTime = getIntFromINI(section, keyWord, settingFile, -1);

	sprintf_s(keyWord, "homeTime");
	consumer2.homeTime = getIntFromINI(section, keyWord, settingFile, -1);

	sprintf_s(keyWord, "buyTime");
	consumer2.buyTime = getIntFromINI(section, keyWord, settingFile, -1);

	sprintf_s(keyWord, "purchase");
	consumer2.purchase = getIntFromINI(section, keyWord, settingFile, -1);

	while (shop1.numBought < shop1.appleSum) {
		Sleep(consumer2.moveTime);

		WaitForSingleObject(threadMutexB, INFINITE);

		Sleep(consumer2.buyTime);
		int prev = shop1.numBought;
		if (shop1.numBought <= shop1.appleSum - consumer2.purchase) {
			shop1.numBought += consumer2.purchase;
			consumer2.numBought += consumer2.purchase;
		}
		else {
			consumer2.numBought += shop1.appleSum - shop1.numBought;
			shop1.numBought = shop1.appleSum;
		}

		fprintf_s(stdout, "finish thread%s process %d -> %d\n", consumer2.name, prev, shop1.numBought);

		fprintf_s(stdout, "%s apple sum = %d\n", consumer2.name, consumer2.numBought);
		fprintf_s(stdout, "\n");

		ReleaseMutex(threadMutexA);
		Sleep(consumer2.moveTime + consumer2.homeTime);

	}
	fprintf_s(stdout, "finish all\n\n");
}

void threadSampleA(LPVOID data) {
	processA();
}

void threadSampleB(LPVOID data) {
	processB();
}

int main() {

	shop1.numBought = 0;

	getCurrentDirectory(currentDirectory);
	sprintf_s(settingFile, "%s\\shopping.ini", currentDirectory);

	char section[CHARBUFF];
	sprintf_s(section, "shop1");

	char keyWord[CHARBUFF];
	sprintf_s(keyWord, "appleSum");

	shop1.appleSum = getIntFromINI(section, keyWord, settingFile, -1);

	HANDLE threadHandler[NUMTHREAD];
	DWORD threadID[NUMTHREAD];
	threadMutexA = CreateMutex(NULL, FALSE, NULL);
	threadMutexB = CreateMutex(NULL, FALSE, NULL);

	threadHandler[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threadSampleA, NULL, 0, &threadID[0]);
	threadHandler[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threadSampleB, NULL, 0, &threadID[1]);

	for (int i = 0; i < NUMTHREAD; i++) {
		WaitForSingleObject(threadHandler[i], INFINITE);
		CloseHandle(threadHandler[i]);
	}

	FILE* fp;
	errno_t error;

	error = fopen_s(&fp, "result.txt", "w");

	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		fprintf(fp, "さくらさん：%d個\n", consumer1.numBought);
		fprintf(fp, "ともよさん：%d個\n", consumer2.numBought);
		fclose(fp);
	}

	CloseHandle(threadMutexA);
	CloseHandle(threadMutexB);
	fprintf(stdout, "End \n");

	return 0;
}
