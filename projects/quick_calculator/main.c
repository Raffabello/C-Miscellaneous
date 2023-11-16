#include <stdio.h>
#include <string.h>

//some global rules
#define cyan "\e[1;36m"
#define red "\e[0;31m"
#define reset "\e[0m"

int start_calculator(void); //Check this code block, because you will see how to make a simple menu

//What can be done
void free_mode(void);
void call_help(int option);
int main(void)
{
    start_calculator();
    return 1;
}

int start_calculator(void)
{
    char help_symbol;
    int option;
    printf(cyan);
    /*Ignore this, just drawing*/
    for(int i = 0; i <= 5; i ++)
        printf("*");
    printf("\n>>>>>Quick Calculator v1.0\n");
    for(int i = 0; i<= 5; i ++)
        printf("*");
    printf("\nDeveloped by Raffabello.\n-->Menu\n");
    printf(reset);
    /**/

    do
    {
        printf("\n\t1)Free mode\n\t0)Exit.\n\n\tIf you don't understand a command, just type\n\t [command]?\nWhat do you want to do?\n");
        scanf("%d%c", &option,&help_symbol);
        //Why Switch in a do while?Because this way we make a switch loopable rather than a procedural task,
        //we can also use a goto, every time the user enters a number that is not an option
        //But this case it will exit once the task is done.
        switch(option)
        {
            case 1:
                if(help_symbol != '?')
                {
                    free_mode();
                }
                else
                {
                    call_help(option);
                }
            break;
            default:
                printf("This command is not recognized, retry ...\n>");
            break;
        }

    }while(option != 0);

    printf("Calculator is OFF. Thank you for using.\n");

    return 1;
}

void free_mode(void)
{
    printf("Hello World");
}

void call_help(int option)
{
    switch(option)
    {   
        int throwaway;
        case 1:
            printf("This is the free mode, that means you can type directly the calculations in it, such as 67+32 and get the result\nor just change like 5*125\n");
            printf("Press any key to reload the menu...\n");
            scanf("%d", &throwaway);
        break;
    }
    start_calculator();
}
