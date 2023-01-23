#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    unsigned char throws = 0;
    
    for(;;)
    {
        throws++;
        unsigned char throw = 1 + rand() % 6;
        if(throw == 6) break;
    }

    printf("Throws: %i\n", throws);

    return 0;
}