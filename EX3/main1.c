#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 1; i <= 6; i++)
    {
        // 印前面的空白
        for (j = 1; j <= 6 - i; j++)
        {
            printf(" ");
        }

        // 印數字
        for (j = 1; j <= i; j++)
        {
            printf("%d ", i);
        }

        printf("\n");
    }

    return 0;
}
