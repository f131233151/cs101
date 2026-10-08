#include <stdio.h>

int main(void)
{
    int i = 119;

    if (i <= 30)
    {
        printf("免費\n");
    }
    else if (i >= 240)
    {
        printf("240元\n");
    }
    else
    {
        if (i % 30)
        {
            int h = (i / 30 + 1) * 30;
            printf("%d 元\n", h);
        }
        else
        {
            printf("%d 元\n", i);
        }
    }

    return 0;
}
