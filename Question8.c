#include <stdio.h>

void computeTotals(int (*marks)[3], int rows, int totals[])
{
    int i, j, sum;
    for (i = 0; i < rows; i++)
    {
        sum = 0;
        for (j = 0; j < 3; j++)
        {
            sum = sum + *(*(marks + i) + j);
        }
        totals[i] = sum;
    }
}

int findTopper(const int *totals, int rows)
{
    int i, top = 0;
    for (i = 1; i < rows; i++)
    {
        if (*(totals + i) > *(totals + top))
        {
            top = i;
        }
    }
    return top;
}

int main()
{
    int marks[3][3];
    int totals[3];
    int i, j, topper;

    for (i = 0; i < 3; i++)
    {
        printf("Enter marks for Student %d (3 subjects): ", i + 1);
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &marks[i][j]);
        }
    }

    computeTotals(marks, 3, totals);

    for (i = 0; i < 3; i++)
    {
        printf("Total for Student %d: %d\n", i + 1, totals[i]);
    }

    topper = findTopper(totals, 3);
    printf("Student %d is the topper with total %d\n", topper + 1, totals[topper]);

    return 0;
}