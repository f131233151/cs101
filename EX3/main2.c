#include <stdio.h>

int main(void)
{
    int i = 8;

    if (i & (i - 1))
    {
        printf("false\n");
    }
    else
    {
        printf("true\n");
    }

    return 0;
}
