#include <stdio.h>

int main(void)
{
    int i = 15;

    if (i % 15 == 0)
    {
        printf("Love IU\n");
    }
    else if (i % 3 == 0)
    {
        printf("Love\n");
    }
    else if (i % 5 == 0)
    {
        printf("IU\n");
    }
    else
    {
        printf("%d\n", i);
    }

    return 0;
}
