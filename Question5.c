#include <stdio.h>

void printGrid(int (*grid)[5])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int countNeighbours(int (*grid)[5], int row, int col)
{
    int i, j, r, c, count = 0;
    for (i = -1; i <= 1; i++)
    {
        for (j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            r = row + i;
            c = col + j;
            if (r >= 0 && r < 5 && c >= 0 && c < 5)
            {
                if (grid[r][c] & 1)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

void nextGeneration(int (*grid)[5])
{
    int r, c, n;

    for (r = 0; r < 5; r++)
    {
        for (c = 0; c < 5; c++)
        {
            n = countNeighbours(grid, r, c);
            if (grid[r][c] & 1)
            {
                if (n == 2 || n == 3)
                {
                    grid[r][c] = grid[r][c] | 2;
                }
            }
            else
            {
                if (n == 3)
                {
                    grid[r][c] = grid[r][c] | 2;
                }
            }
        }
    }

    for (r = 0; r < 5; r++)
    {
        for (c = 0; c < 5; c++)
        {
            grid[r][c] >>= 1;
        }
    }
}

int main()
{
    int grid[5][5] = {0};
    int gens, g;

    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    while (1)
    {
        printf("Enter number of generations (0-50): ");
        scanf("%d", &gens);
        if (gens < 0 || gens > 50)
        {
            printf("Invalid number\n");
        }
        else
        {
            break;
        }
    }

    printf("Generation 0:\n");
    printGrid(grid);

    for (g = 1; g <= gens; g++)
    {
        nextGeneration(grid);
        printf("Generation %d:\n", g);
        printGrid(grid);
    }

    return 0;
}