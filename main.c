#include <stdio.h>
#include <string.h>
#include "student.h"
#include "file.h"
#include "menu.h"

int main() {
    Student students[100];
    int n = 0;
    int choice;

    loadFromFile(students, &n, "students.txt");

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &n); break;
            case 2: displayStudents(students, n); break;
            case 3: editStudent(students, n); break;
            case 4: deleteStudent(students, &n); break;
            case 5: {
                char id[15];
                printf("Enter ID: ");
                scanf("%s", id);
                int pos = searchByID(students, n, id);
                if (pos != -1)
                    printf("Found: %s - %s - %.2f\n", students[pos].id, students[pos].name, students[pos].gpa);
                else
                    printf("Not found!\n");
                break;
            }
            case 6: {
                char name[50];
                printf("Enter name keyword: ");
                getchar();
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                int pos = searchByName(students, n, name);
                if (pos != -1)
                    printf("Found: %s - %s - %.2f\n", students[pos].id, students[pos].name, students[pos].gpa);
                else
                    printf("Not found!\n");
                break;
            }
            case 7: sortByGPA(students, n); break;
            case 8: sortByName(students, n); break;
            case 9: saveToFile(students, n, "students.txt"); break;
            case 10: loadFromFile(students, &n, "students.txt"); break;
            case 11: {
    			printf("\n--- GPA of Each Student ---\n");
    			for (int i = 0; i < n; i++) {
        		students[i].gpa = calculateStudentGPA(&students[i]);
        		printf("%-10s | %-20s | GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    		}

    		float overall = calculateOverallGPA(students, n);
    		printf("\n Overall GPA of all students: %.2f\n", overall);
    		break;
			}

            case 0: printf(" Exiting program.\n"); break;
            default: printf(" Invalid choice!\n");
        }
    } while (choice != 0);
    
    return 0;
}
