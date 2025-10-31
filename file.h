#ifndef FILE_H
#define FILE_H

#include "student.h"

void saveToFile(Student students[], int n, const char *filename);
void loadFromFile(Student students[], int *n, const char *filename);

#endif
