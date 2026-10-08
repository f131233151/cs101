#include <stdio.h>

int main(void)
{
    int i = 2100;

    if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0)))
    {
        printf("閏年\n");
    }
    else
    {
        printf("不是閏年\n");
    }

    return 0;
}
