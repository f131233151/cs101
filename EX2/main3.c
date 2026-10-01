#include <stdio.h>

int main(void)
{
    int i = 1;

    
    i = i++ << 2 + 3 << --i;

    printf("i = %d\n", i);

    return 0;
}
