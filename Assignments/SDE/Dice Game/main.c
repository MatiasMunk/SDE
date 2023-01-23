#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    unsigned int throws = 0;
    unsigned int dices = 0;
    
    scanf("%i", &dices);
    
    unsigned char sixes = 0;
    for(;;)
    {
        unsigned char roll = 1 + rand() % 6;
        throws++;
        
        if(roll == 6)
        {
            sixes++;
            if(sixes == dices)
            break;
        }
        else sixes = 0;
    }

    printf("Throws: %i\n", throws / dices);

    return 0;
}