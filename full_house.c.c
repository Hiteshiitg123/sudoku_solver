#include <stdio.h>

int main()
{
    int a[9][9];
    int b[9][9];

    int sum , zeroes;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &a[i][j]);
            b[i][j] = 0;
        }
        
    }

label2:

    

    for (int i = 0; i < 9; i++)
    {
        sum = 0, zeroes = 0;

        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] == 0)
            {
                zeroes++;
            }

            sum += a[i][j];
        }

        if (zeroes == 1)
        {
            for (int j = 0; j < 9; j++)
            {
                if (a[i][j] == 0)
                {
                    a[i][j] = 45 - sum;
                }
            }
        }
    }

    

    for (int j = 0; j < 9; j++)
    {
        sum = 0, zeroes = 0;

        for (int i = 0; i < 9; i++)
        {
            if (a[i][j] == 0)
            {
                zeroes++;
            }

            sum += a[i][j];
        }

        if (zeroes == 1)
        {
            for (int i = 0; i < 9; i++)
            {
                if (a[i][j] == 0)
                {
                    a[i][j] = 45 - sum;
                }
            }
        }
    }

    int k = 0, l = 0, n = 0;

label:

    sum = 0, zeroes = 0;

    for (int i = 3 * k; i < 3 * (k + 1); i++)
    {
        for (int j = 3 * l; j < 3 * (l + 1); j++)
        {
            if (a[i][j] == 0)
            {
                zeroes++;
            }

            sum += a[i][j];
            n++;
        }
    }

    if (zeroes == 1)
    {
        for (int i = 3 * k; i < 3 * (k + 1); i++)
        {
            for (int j = 3 * l; j < 3 * (l + 1); j++)
            {
                if (a[i][j] == 0)
                {
                    a[i][j] = 45 - sum;
                }
            }
        }
    }
    if (n == 9 || n == 18 || n == 36 || n == 45 || n == 63 || n == 72)
    {
        l++;
        goto label;
    }

    if (n == 27 || n == 54)
    {
        l = 0;
        k++;
        goto label;
    }

    int x = 0;
    

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] == 0)
            {
                x++;
            }
        }
    }

    int z = 0;

    if (x != 0)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (a[i][j] == b[i][j])
                {
                    z++;
                }
            }
        }

        if (z == 81)
        {
            goto label3;
        }

        else
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    b[i][j] = a[i][j];
                }
            }
        }

        goto label2;
    }

label3:

    printf("\n");

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", a[i][j]);
        }

        printf("\n");
    }

    return 0;
}