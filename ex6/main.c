#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Slide notes:
 * - Page 18 names the age field emp_age, but pages 19 and 25-35 use age.
 *   This follows the later examples and uses age.
 * - The average-age example misspells the function name; this uses the
 *   requested name emp_average_age.
 * - Page 30 lists a count for emp_readfile, while later examples read to EOF.
 *   Here n is the destination array capacity, which prevents an overrun.
 */
typedef struct employee {
    int id;
    char name[12];
    int age;
    float salary;
} employee_t;

void emp_info(employee_t emp)
{
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %02f\n\n", emp.salary);
}

int emp_average_age(employee_t emp[], int n)
{
    int sum = 0;

    if (n <= 0) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }

    return sum / n;
}

void emp_writefile(employee_t emp[], int n)
{
    FILE *fp = fopen("employee.bin", "wb+");

    if (fp == NULL) {
        perror("employee.bin");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        if (fwrite(emp + i, sizeof(employee_t), 1, fp) != 1) {
            perror("fwrite");
            fclose(fp);
            exit(EXIT_FAILURE);
        }
    }

    if (fclose(fp) != 0) {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
}

void emp_readfile(employee_t emp[], int n)
{
    FILE *fp = fopen("employee.bin", "rb");
    int i = 0;

    if (fp == NULL) {
        perror("employee.bin");
        exit(EXIT_FAILURE);
    }

    while (i < n && fread(emp + i, sizeof(employee_t), 1, fp) == 1) {
        printf("[%d] %d %s\n", i, emp[i].id, emp[i].name);
        i++;
    }

    if (ferror(fp)) {
        perror("fread");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    if (fclose(fp) != 0) {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
}

int main(void)
{
    employee_t emp[3] = {0};

    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0f;
    strcpy(emp[0].name, "IU");

    emp[1].id = 2;
    emp[1].age = 26;
    emp[1].salary = 36000.0f;
    strcpy(emp[1].name, "taylor");

    emp[2].id = 3;
    emp[2].age = 31;
    emp[2].salary = 90000.0f;
    strcpy(emp[2].name, "swift");

    printf("Average age: %d\n\n", emp_average_age(emp, 3));

    emp_writefile(emp, 3);

    employee_t read_emp[10] = {0};
    emp_readfile(read_emp, 10);

    for (int i = 0; i < 3; i++) {
        emp_info(read_emp[i]);
    }

    return 0;
}
