#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include "Setting.h"


void getCurrentDirectory(char* currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

int readInt(const char* section, const char* para, const char* file, int defaultValue) {
	return GetPrivateProfileInt(section, para, defaultValue, file);
}

char* readChar(const char* section, const char* para, const char* file, char* value, const char* defaultValue) {
	char keyValue[CHARBUFF];
	GetPrivateProfileString(section, para, defaultValue, keyValue, CHARBUFF, file);
	return keyValue;
}

double readDouble(const char* section, const char* para, const char* file, double defaultValue) {
	char keyValue[CHARBUFF];
	char default[CHARBUFF];
	sprintf_s(default, "%lf", defaultValue);
	GetPrivateProfileString(section, para, default, keyValue, CHARBUFF, file);
	return strtod(keyValue, NULL);
}

bool writeChar(const char* section, const char* para, const char* file, const char* value) {
	return WritePrivateProfileString(section, para, value, file);
}

bool writeInt(const char* section, const char* para, const char* file, int value) {
	char s[CHARBUFF];
	sprintf_s(s, "%d", value);
	return WritePrivateProfileString(section, para, s, file);
}

bool writeDouble(const char* section, const char* para, const char* file, double value) {
	char s[CHARBUFF];
	sprintf_s(s, "%lf", value);
	return WritePrivateProfileString(section, para, s, file);
}
