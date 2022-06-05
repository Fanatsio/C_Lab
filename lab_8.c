#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#define ESC 27 

int mygetch ()
{
    struct termios oldt , newt ;
    int c ;
    tcgetattr ( STDIN_FILENO , & oldt ) ;
    newt = oldt ;
    newt . c_lflag &= ~( ICANON | ECHO ) ;
    tcsetattr ( STDIN_FILENO , TCSANOW , & newt ) ;
    c = getchar () ;
    tcsetattr ( STDIN_FILENO , TCSANOW , & oldt ) ;
    return c ;
}

int main() 
{
    puts("Для завершения программы нажмите <ESC> в начале строки");
    while (mygetch() != ESC)
    {
        char s[80], *p;
        printf("Enter -> ");
        scanf("%s", s);
        p = strchr(s, '.');
        int wasError = 0;
        for (int i = 0; i < strlen(s); i++)
        if (s[i] != '.' && (s[i] < '0' || s[i] > '9')) 
        {
            printf("Не число\n");
            wasError = 1;
            break;
        }
        if (wasError)
            continue;
        if (p == NULL || p == s || p == s + strlen(s) - 1 || strchr(p + 1, '.') != NULL) 
            printf("Число не вещественное\n");
        else 
            printf("Число вещественное\n");
        if (mygetch() == ESC)
            break;
    }
    return 0;
}