#include <stdio.h>

#define BHCYN "\e[1;96m"
#define BHRED "\e[1;91m"
#define GENERAL_CHAT "\e[0;92m" "[Raffabello]:"
#define COLOR_RESET "\e[0m"
#define NORMAL_CHAT BHCYN "[Info]:" 
#define ACTION_CHAT "\e[0;97m" "Input>" COLOR_RESET
#define ERROR_CHAT BHRED "[Error]!!:" 
#define new_line "\n"

#define filelen 64
#define card_len 256

//函数 
int compare_char(char a, char b);
int compare_strings(char *str1, char *str2);
int len(char *str);

typedef struct Flashcard {
    char front[card_len];
    char back[card_len];
}Flashcard;



int compare_strings(char *str1, char *str2)
{
    if(len(str1) != len(str2))
    {
        return 0; 
    }
    else
    {
        int index = 0;
        while(str1[index] != '\0')
        {
            if(str1[index] != str2[index])
                return 0;
            index ++;
        }
        return 1;
    }
    return 0;
}
//字母是不是相同
int compare_char(char a, char b)
{
    if(a == b)
        return 1;
    else
        return 0;
}

int len(char *str)
{
    int i = 0;
    for(;i < str[i] != '\0'; i ++);
    return i; 
}

int file_management(void)
{
    FILE * file;
    char filename[filelen];
    int error_type = 0; //没有错误
    //这个函数的作用应该是:
    //1做一个新的文件
    printf("请打字文件的名字:" new_line);
    printf(NORMAL_CHAT "文件必须没有点" COLOR_RESET new_line);
    printf(ACTION_CHAT);
    teleport:
    switch(error_type)
    {
        case 1:
            printf(NORMAL_CHAT "你在这里因为你的文件有点，所以请问再打字文件没有点的名字:" COLOR_RESET new_line);
            for(int i = 0; filename[i] != '\0'; i++)
            {
                if(compare_char(filename[i], '.') == 1)
                    printf("[%c]", filename[i]);
                else
                    printf("%c", filename[i]);
            }
            printf(new_line GENERAL_CHAT "为关闭程序打字0." COLOR_RESET new_line);
            printf(ACTION_CHAT);
            error_type = 0;
        break;
    }
    scanf("%s", filename);
    if(compare_char(filename[0], '0') == 1)
    {
        printf(GENERAL_CHAT "你关闭程序，你用我的软件非常谢谢。" COLOR_RESET new_line);
        return 0;
    }
    //文件的名字有没有“。
    for(int index = 0;filename[index] != '\0'; index ++)
    {
        if(compare_char(filename[index], '.') == 1)
        {
            printf(ERROR_CHAT "你打字文件的名字有点所以你不可以" COLOR_RESET new_line);
            error_type = 1;
            goto teleport;
        }
    }

    file = fopen(filename, "w+");
    if(file != NULL)
    {
        printf(NORMAL_CHAT "文件做完了." COLOR_RESET new_line);
        fclose(file);
    }
    return 1;
}


