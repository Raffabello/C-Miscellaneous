#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Control panel
#define size 10
#define make_random_bool 1
#define max_range 64
#define print_vector 0
//

int main(void)
{
    int v[size];
    srand(time(NULL));
    if(make_random_bool == 1)
    {
        for(int i = 0; i < size; i++)
        {
            v[i] = rand() % max_range;
        }
    }
    else
    {
        for(int i = 0; i < size; i ++)
        {
            printf("Enter value at cell no.%d:\n", i + 1);
            scanf("%d", &v[i]);
        }
    }

    //print vector
    for(int i = 0; i < size; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }

}
