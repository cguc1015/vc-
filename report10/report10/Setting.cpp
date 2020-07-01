#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include "setting.h"

void getCurrentDirectory(char* currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

int getIntFromINI(const char* section, const char* para, const char* file, int defaultValue) {
	return GetPrivateProfileInt(section, para, defaultValue, file);
}

bool setIntFromINI(const char* section, const char* para, const char* file, int value) {
	char s[CHARBUFF];
	sprintf_s(s, "%d", value);
	return WritePrivateProfileString(section, para, s, file);
}

double getDoubleFromINI(const char* section, const char* para, const char* file, double defaultValue) {
	char keyValue[CHARBUFF];
	char default[CHARBUFF];
	sprintf_s(default, "%lf", defaultValue);
	GetPrivateProfileString(section, para, default , keyValue, CHARBUFF, file);
	return strtod(keyValue, NULL);
}

bool setDoubleFromINI(const char* section, const char* para, const char* file, double value) {
	char s[CHARBUFF];
	sprintf_s(s, "%lf", value);
	return WritePrivateProfileString(section, para, s, file);
}

bool setCharFromINI(const char* section, const char* para, const char* file, const char* value) {
	return WritePrivateProfileString(section, para, value, file);
}


