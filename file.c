#include <stdio.h>
#include "file.h"

void saveToFile(Student students[], int n, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Cannot open file for writing!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s,%s,%d,%s,%.2f\n",
                students[i].id, students[i].name,
                students[i].birthYear, students[i].major, students[i].gpa);
    }
    fclose(f);
    printf("Data saved successfully!\n");
}

void loadFromFile(Student students[], int *n, const char *filename) {          
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf(" No file found, starting fresh.\n");
        return;
    }

    *n = 0;
    while (fscanf(f, "%[^,],%[^,],%d,%[^,],%f\n",
                  students[*n].id, 
				  students[*n].name,
                  &students[*n].birthYear, 
				  students[*n].major,
                  &students[*n].gpa) == 5) {
        (*n)++;
    }
    fclose(f);
    printf("Data loaded successfully!\n");
}
