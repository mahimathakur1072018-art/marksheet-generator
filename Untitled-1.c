//1. BASIC — MARKSHEET GENERATOR
#include <stdio.h>

int calculateTotal(int marks[], int n)
{
    int total = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        total += marks[i];
    }

    return total;
}

float calculatePercentage(int total, int n)
{
    return (float)total / n;
}

char calculateGrade(float percentage)
{
    if (percentage >= 90)
        return 'A';
    else if (percentage >= 80)
        return 'B';
    else if (percentage >= 70)
        return 'C';
    else if (percentage >= 60)
        return 'D';
    else if (percentage > 33)
        return 'E';
    else
        return 'F';
}

int main(void)
{
    int marks[5];
    int i, total, failedSubjects = 0;
    int number, valid, digits, ch;
    float percentage;
    char grade;

    printf("===== MARKSHEET GENERATOR =====\n\n");
    printf("Enter whole numbers from 1 to 100.\n");
    printf("Overall passing criteria: more than 33%%.\n\n");

    for (i = 0; i < 5; i++)
    {
        while (1)
        {
            printf("Subject %d: ", i + 1);

            number = 0;
            valid = 1;
            digits = 0;

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
                if (ch >= '0' && ch <= '9')
                {
                    digits = 1;

                    if (number <= 100)
                        number = number * 10 + (ch - '0');
                }
                else
                {
                    valid = 0;
                }
            }

            if (ch == EOF && digits == 0)
            {
                printf("\nInput ended.\n");
                return 0;
            }

            if (valid && digits && number >= 1 && number <= 100)
            {
                marks[i] = number;
                break;
            }

            printf("Invalid input! Enter a whole number from 1 to 100.\n");
        }
    }

    total = calculateTotal(marks, 5);
    percentage = calculatePercentage(total, 5);
    grade = calculateGrade(percentage);

    printf("\n========== MARKSHEET ==========\n");

    for (i = 0; i < 5; i++)
    {
        printf("Subject %d : %d - ", i + 1, marks[i]);

        if (marks[i] >= 33)
        {
            printf("PASS\n");
        }
        else
        {
            printf("FAIL\n");
            failedSubjects++;
        }
    }

    printf("-------------------------------\n");
    printf("Total           : %d / 500\n", total);
    printf("Percentage      : %.2f%%\n", percentage);
    printf("Grade           : %c\n", grade);
    printf("Subjects failed : %d\n", failedSubjects);

    if (percentage > 33)
        printf("Overall result  : PASS\n");
    else
        printf("Overall result  : FAIL\n");

    printf("===============================\n");

    return 0;
}