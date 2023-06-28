#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadrastro {
	char nome[50];
	int idade;
	int saldo_atual;

};



int main()
{
    //setlocale(LC_ALL, "Portuguese");
    printf("UAIBANK\n");
        printf(" 1 Inserção de um novo usuário: ");
    	printf("\n================================================ \n");
    	printf(" 2 Inserção de vários usuários: ");
    	printf("\n================================================ \n");
    	printf(" 3 Busca de um usuário por id: ");
    	printf("\n================================================ \n");
    	printf(" 4 Transferências entre usuários: ");
    	printf("\n================================================ \n");
    	printf(" 5 Remoção de um usuário por id: ");
    	printf("\n");

    char opt = 0;
    do {
        opt = getch();
        if (opt == '1'){
            //puts("1");
            struct cadrastro c;
        	setbuf(stdin, NULL);
        	gets(c.nome);
        	setbuf(stdin, NULL);
        	scanf("%d",&c.idade);
        	setbuf(stdin, NULL);
        	scanf("%d",&c.saldo_atual);
        	setbuf(stdin, NULL);

        }
        if (opt == '2'){
            //puts("2");
            int q;
            scanf("%d",&q);
        	struct cadrastro c[q];
        	for (int i=0;i<q;i++){
            	setbuf(stdin, NULL);
            	gets(c[i].nome);
            	setbuf(stdin, NULL);
            	scanf("%d",&c[i].idade);
            	setbuf(stdin, NULL);
            	scanf("%d",&c[i].saldo_atual);
            	setbuf(stdin, NULL);
            	printf("\n================================================ \n");
        	}


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
