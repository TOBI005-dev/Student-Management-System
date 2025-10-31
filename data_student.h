#ifndef DATA_STUDENT_H
#define DATA_STUDENT_H

typedef struct {
    char id[15];
    char name[50];
    int birthYear;
    char major[30];
    float scores[5];
    float gpa;
}Student;

#endif
