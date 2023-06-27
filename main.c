#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    printf("UAIBANK\n");

    char opt = 0;
    do {
        opt = getch();
        if (opt == '1'){
            puts("1");
        }
        if (opt == '2'){
            puts("2");
        }
        if (opt == '3'){
            puts("3");
        }
        if (opt == '4'){
            puts("4");
        }
        if (opt == '5'){
            puts("5");
        }
    } while(opt != 0x08 && opt != 0x1B);


    return 0;
}
