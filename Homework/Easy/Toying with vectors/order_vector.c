#include <stdio.h>

#define size 3
int main(void)
{
    int x[size];
    int counter = 0;

    while(counter < size)
    {  
        printf("Enter value at x[%d] cell>\n",counter + 1);
        scanf("%d", &x[counter]);
        if(x[counter] < 0)
            ;
        else
            counter++;
    }

    printf("Vector was recorded...");
    counter = 0;
    while(counter < size)
    {
        if(counter < size - 1)
            printf("x[%d]:%d, ", counter + 1, x[counter]);
        else
            printf("x[%d]:%d", counter + 1, x[counter]);
        counter ++;
    }

    int tmp;
    int y[size];
    counter = 0;
    while(counter < size)
    {
        tmp = x[counter];
        int tmp_index = counter;
        int j = 0;
        while(j < size)
        {
            if(j < size && x[j] > x[j + 1])
            {
                int a = x[j];
                int b = x[tmp_index];
                x[tmp_index] = a;
                x[j] = b; 
            }
            j ++;
        }
        counter ++;
    }
    counter = 0;
    printf("\nBelow there is the vector, but ordered from small to big...\n");
    while(counter < size)
    {
        if(counter < size - 1)
            printf("%d, ", x[counter]);
        else
            printf("%d", x[counter]);
        counter ++ ;
    }

    printf("\n");

    return 0;
}
