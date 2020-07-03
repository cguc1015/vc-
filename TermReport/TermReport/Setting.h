#pragma once

#define CHARBUFF 128

void getCurrentDirectory(char *currentDirectory);

int readInt(const char *section, const char *para, const char *file, int defaultValue);
bool writeInt(const char *section, const char *para, const char *file, int value);

double readDouble(const char *section, const char *para, const char *file, double defaultValue);
bool writeDouble(const char *section, const char *para, const char *file, double value);

char* readChar(const char *section, const char *para, const char *file, char *value, const char *defaultValue);
bool writeChar(const char *section, const char *para, const char *file, const char *value);
