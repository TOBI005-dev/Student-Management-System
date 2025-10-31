#ifndef STUDENT_H
#define STUDENT_H
#include "data_student.h"
// CRUD 
void addStudent(Student students[] , int *n);
void editStudent(Student students[] , int n);
void displayStudents(Student students[], int n);
void deleteStudent(Student students[] , int *n);

//SORT 
void sortByName(Student students[] , int n) ;
void sortByGPA(Student students[] , int n);
void sortByBirthYear(Student students[], int n);

//SEARCH
int searchByID(Student students[] , int n, char id[]);
int searchByName(Student students[] , int n , char name[]);

//GPA
float calculateOverallGPA(Student students[] , int n);
float calculateStudentGPA(Student *s); 

#endif