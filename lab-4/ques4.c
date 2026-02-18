//pointer to a structure
#include <stdio.h>
#include <string.h>
struct Employee {
    int id;
    char name[50];
    float salary;
};
int main() {
    struct Employee emp;
    struct Employee *p = &emp;
    printf("Enter Employee ID: ");
    scanf("%d", &p->id);
    
    printf("Enter Employee Name: ");
    scanf("%s", p->name);

    printf("Enter Employee Salary: ");
    scanf("%f", &p->salary);

    printf("\nEmployee Details:\n");
    printf("ID: %d\n", p->id);
    printf("Name: %s\n", p->name);
    printf("Salary: %.2f\n", p->salary);

    printf("\nAddresses of Employee Members:\n");
    printf("Address of ID: %p\n", &p->id);
    printf("Address of Name: %p\n",&p->name);
    printf("Address of Salary: %p\n",&p->salary);

    return 0;
}