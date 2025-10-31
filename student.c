#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "student.h"
#include "data_student.h" 
void addStudent(Student students[], int *n) {
    printf("\n Add New Student\n");
    char tempID[15];
    int duplicate;

    do {
        duplicate = 0; 

        printf("ID: ");
        scanf("%s", tempID);

        // Chuyen ID sang chu hoa
        for (int i = 0; tempID[i]; i++) {
            tempID[i] = toupper(tempID[i]);
        }

        // Kiem tra ID trung
        for (int i = 0; i < *n; i++) {
            if (strcmp(students[i].id, tempID) == 0) {
                printf("ID already exists, please enter another ID!\n");
                duplicate = 1;
                break;
            }
        }

    }while (duplicate == 1);

    // Sao chep ID da kiem tra vao danh sach sinh vien
    strcpy(students[*n].id, tempID);

    printf("Name: ");
    getchar(); 
    fgets(students[*n].name,50, stdin);
    students[*n].name[strcspn(students[*n].name, "\n")] = '\0'; 
    
    do {
    printf("Birth Year: ");
    scanf("%d", &students[*n].birthYear);
    } while (students[*n].birthYear < 1900 || students[*n].birthYear > 2025);

    printf("Major: ");
    getchar();
    fgets(students[*n].major, 50 , stdin);
    students[*n].major[strcspn(students[*n].major, "\n")] = '\0';
    for (int i = 0; students[*n].major[i]; i++){
    	students[*n].major[i] = toupper(students[*n].major[i]);
	}	

    printf("Enter 5 scores (from 1 to 10):\n");
	for (int i = 0; i < 5; i++) {
    	do {
        	printf("Score %d: ", i + 1);
        	scanf("%f", &students[*n].scores[i]);
        	if (students[*n].scores[i] < 1 || students[*n].scores[i] > 10) {
            	printf("Invalid score! Please enter a value between 1 and 10.\n");
        	}
    	} while (students[*n].scores[i] < 1 || students[*n].scores[i] > 10);
	}

	students[*n].gpa = calculateStudentGPA(&students[*n]);

    (*n)++; // Tang so luong sinh vien
    printf("Student added successfully!\n");
}

void displayStudents(Student students[], int n) {
    if (n == 0) {
        printf("\n No students to display.\n");
        return;
    }

    printf("\n%-10s | %-20s | %-15s | %-10s | %-5s\n",
           "ID", "Name", "Major", "Year", "GPA");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10s | %-20s | %-15s | %-10d | %-5.2f\n",
               students[i].id,
               students[i].name,
               students[i].major,
               students[i].birthYear,
               students[i].gpa);
    }

    printf("-----------------------------------------------------------------------\n");
    printf("Total students: %d\n", n);
}

void editStudent(Student students[], int n) {
    char id[15];

    // Nhap ID can chinh sua
    printf("Enter ID to edit: ");
    scanf("%s", id);

    // Duyet toan bo danh sach sinh vien
    for (int i = 0; i < n; i++) {
        // So sanh ID nhap vao voi ID trong danh sach
        if (strcmp(students[i].id, id) == 0) {

            printf("\nEditing student %s:\n", id);

            // Nhap ten moi
            printf("New name: ");
            getchar();  // Xoa ki tu '\n' con sot trong bo nho dem
            fgets(students[i].name, 50, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0'; // xoa dau enter cuoi chuoi

            // Nhap chuyen nganh moi
            printf("New major: ");
            fgets(students[i].major, 30, stdin);
            students[i].major[strcspn(students[i].major, "\n")] = '\0';
            for (int j = 0; students[i].major[j]; j++) {
    			students[i].major[j] = toupper(students[i].major[j]);
			}

            
            // Nhap GPA moi
            printf("New GPA: ");
            scanf("%f", &students[i].gpa);

            printf("Updated successfully!\n");
            return;  
        }
    }

    // Neu khong tim thay sinh vien nao cos id khop
    printf("Student not found!\n");
}

void deleteStudent(Student students[], int *n) {
    char id[15];
    printf("Enter ID to delete: ");
    scanf("%s", id);

    for (int i = 0; i < *n; i++) {
        if (strcmp(students[i].id, id) == 0) {
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;
            printf("Deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

int searchByID(Student students[], int n, char id[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].id, id) == 0)
            return i;
    }
    return -1;
}

int searchByName(Student students[], int n, char name[]) {
    char keyword[50];
    strcpy(keyword, name);

    // Chuyen keyword sang chu thuong
    for (int k = 0; keyword[k]; k++) {
        keyword[k] = tolower(keyword[k]);
    }

    for (int i = 0; i < n; i++) {
        char temp[50];
        strcpy(temp, students[i].name);

        // Chuyen ten sinh vien sang chu thuong
        for (int j = 0; temp[j]; j++) {
            temp[j] = tolower(temp[j]);
        }

        // Tim tu khoa trong ten
        if (strstr(temp, keyword) != NULL) {
            return i;   // tra ve vi tri dau tien tim thay
        }
    }
    return -1; // khong tim thay
}

void sortByGPA(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].gpa < students[j + 1].gpa) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Sorted by GPA (descending)\n");
    displayStudents(students, n); 
}

void sortByName(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (_stricmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Sorted by name (A-Z)\n");
    displayStudents(students, n);

}

void sortByBirthYear(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].birthYear > students[j].birthYear) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Sorted by Birth Year (oldest to youngest).\n");
    displayStudents(students, n);
}

float calculateStudentGPA(Student *s) {
    float sum = 0;
    int numSubjects = 0;

    for (int i = 0; i < 5; i++) {
        if (s->scores[i] >= 0) {
            sum += s->scores[i];
            numSubjects++;
        }
    }

    if (numSubjects == 0) return 0;
    s->gpa = sum / numSubjects;
    return s->gpa;
}

float calculateOverallGPA(Student students[], int n) {
    if (n == 0) return 0;
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += students[i].gpa;
    }
    return total / n;
}





