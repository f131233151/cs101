#include <stdio.h>

int main(void)
{
    int i = 1599;

    if (i <= 1500)
    {
        printf("70元\n");
    }
    else
    {
        int n = i - 1500;

        if (n % 100)
        {
            int h = (n / 100 + 1) * 10;
            printf("%d 元\n", 70 + h);
        }
        else
        {
            printf("%d 元\n", 70 + (n / 100) * 10);
        }
    }

    return 0;
}
