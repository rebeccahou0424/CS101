#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employee.bin"
#define MAX_EMP   10

typedef struct {
    int   id;
    int   age;
    double salary;
    char  name[32];
} employee_t;

void emp_writefile(employee_t emp[], int n);
void emp_readfile(employee_t emp[]);
void emp_info(const employee_t e);

int main(void) {
    employee_t emp[3];

    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0;
    strcpy(emp[0].name, "IU");

    emp[1].id = 2;
    emp[1].age = 26;
    emp[1].salary = 36000.0;
    strcpy(emp[1].name, "taylor");

    emp[2].id = 3;
    emp[2].age = 31;
    emp[2].salary = 90000.0;
    strcpy(emp[2].name, "swift");

    emp_writefile(emp, 3);

    employee_t read_emp[MAX_EMP] = {0};
    emp_readfile(read_emp);

    for (int i = 0; i < 3; i++) {
        emp_info(read_emp[i]);
        puts("");
    }

    return 0;
}

void emp_writefile(employee_t emp[], int n) {
    FILE *fp = fopen(FILE_NAME, "wb+");  
    if (!fp) { perror("fopen"); exit(1); }

    for (int i = 0; i < n; i++) {
        fwrite(emp + i, sizeof(employee_t), 1, fp);       
    }

    fclose(fp);
}

void emp_readfile(employee_t emp[]) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) { perror("fopen"); exit(1); }

    int i = 0;

    while (i < MAX_EMP && fread(emp + i, sizeof(employee_t), 1, fp) == 1) {
        printf("[%d] %d %s\n", i, emp[i].id, emp[i].name);
        i++;
    }


    fclose(fp);
}

void emp_info(const employee_t e) {
    printf("employee id = %d\n", e.id);
    printf("employee name = %s\n", e.name);
    printf("employee age = %d\n", e.age);
    printf("employee salary = %f\n", e.salary);
}
