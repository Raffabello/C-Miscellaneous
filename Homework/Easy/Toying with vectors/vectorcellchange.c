#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Control panel
#define size 5
#define make_random_bool 1//if set to 0, means that a random vector won't be generated.
#define max_range 64
#define print_vector 0
//


int main(void)
{
    int v[size];
    srand(time(NULL));
    if(make_random_bool == 1)
    {   
        printf("!make_random_bool set to true.\n");
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
    printf("\033[0;36m"); //this will set the color of the output
    for(int i = 0; i < size; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }
    printf("\033[0m"); //this will default the color set beforehand.

    //Change position 
    int index = 0;
    int number_bool = 0;
    int picked_number;
    //Check if number is in vector    
    while(number_bool == 0)
    {
        printf("Now pick a number from the vector:");
        scanf("%d", &picked_number);
            while(index < size)
            {
                if(picked_number == v[index])
                {
                    number_bool = 1;
                    break;
                }
                index++;
            }
        if(number_bool == 0)
        {
            printf("The vector does not include this number.\n");
            index = 0;
        }
        else
        {
            printf("%d is included in the vector.The cell is no.%d\n", picked_number, index);
        }
    }

    //core:change the cell
    int new_cell;
    int old_cell = index;
    int tmp_number;//will contain the value of the new cell
    printf("---Cell modifier>\n");
    printf("Current value: %d\nCurrent cell: %d\n", picked_number, index);
    printf("Enter the new cell:");
    scanf("%d", &new_cell); 
    while(new_cell > size)
    {
        printf("The cell exceed the size of the vector, please enter a valid cell:");
        scanf("%d", &new_cell);
    }
    //change_cell
    tmp_number = v[new_cell];
    v[new_cell] = picked_number;
    v[old_cell] = tmp_number;
    for(int k = 0; k < size; k++) //sorry for using k as index, just to change a little.
    {
        if(k == new_cell)
        {
            printf("\033[0;31m");
            printf("v[%d] = >>%d<< switched. NEW\n", k, v[k]);
            printf("\033[0m");
        }
        else if (k == old_cell)
        {
            printf("\033[0;31m");
            printf("v[%d] = >>%d<< switched. OLD\n",k, v[k]);
            printf("\033[0m");
        }
        else
            printf("v[%d] = %d\n",k, v[k]);
    }

    return 0;
}
