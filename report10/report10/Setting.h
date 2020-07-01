#pragma once

#define CHARBUFF 128

void getCurrentDirectory(char *currentDirectory);

int getIntFromINI(const char *section, const char *para, const char *file, int defaultValue);
bool setIntFromINI(const char *section, const char *para, const char *file, int value);

double getDoubleFromINI(const char *section, const char *para, const char *file, double defaultValue);
bool setDoubleFromINI(const char *section, const char *para, const char *file, double value);

bool setCharFromINI(const char *section, const char *para, const char *file, const char *value);
