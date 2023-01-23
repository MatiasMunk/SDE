#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    unsigned int dices = 0;
    scanf("%i", &dices);
    
    for(int i = 0; i < 10; i++)
    {
        unsigned int throws = 0;
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
    }

    return 0;
}