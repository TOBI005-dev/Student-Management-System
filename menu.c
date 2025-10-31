#include <stdio.h>
#include "menu.h"

void displayMenu() {
    printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
    printf("1. Add student\n");
    printf("2. Display all students\n");
    printf("3. Edit student\n");
    printf("4. Delete student\n");
    printf("5. Search student by ID\n");
    printf("6. Search student by name\n");
    printf("7. Sort by GPA\n");
    printf("8. Sort by name\n");
    printf("9. Sort by birth year\n");
    printf("10. Save to file\n");
    printf("11. Load from file\n");
    printf("12. Calculate overall GPA of all students\n");
    printf("0. Exit\n");
}
