#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[100];
    unsigned short int idade;
    float saldo;
}cadastro; // Struct principal usada para cada cadastro


int userRegister(){ // Cria um usuário por vez
    cadastro users_temp;
    scanf("%100[^,], %u, %f", &users_temp.nome,&users_temp.idade, &users_temp.saldo); setbuf(stdin,NULL);
    //printf("%s, %d, %.2f\n", users_temp.nome, users_temp.idade, users_temp.saldo);
    writeUser(users_temp);
    return 0;
}

int getLines(FILE* f){ // Função para retornar o número de linhas do arquivo
    rewind(f);
    int lines = 0;
    int ch;
    while ((ch = fgetc(f)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }
    return lines;
}

int writeUser(cadastro c){ // Função para escrever um único usuário no arquivo usando append (opções 1 e 2)
    FILE* usuariosArquivo = fopen("usuarios.txt", "a");
    fprintf(usuariosArquivo, "%s, %d, %.2f\n", c.nome,c.idade, c.saldo); // Grava o usuario no arquivo
    fclose(usuariosArquivo);
    return 0;
}

cadastro* openFile(){ // Função para abrir o arquivo inteiro em um array de structs
    FILE* usuariosArquivo = fopen("usuarios.txt", "r");
    int lines = getLines(usuariosArquivo);
    cadastro* users = malloc(lines * sizeof(cadastro));
    if (users == NULL) {
        printf("Falha ao alocar memória.\n");
        fclose(usuariosArquivo);
        return 1;
    }
    rewind(usuariosArquivo);
    for (int i = 0; i < lines; i++) {
        fscanf(usuariosArquivo, "%100[^,], %u, %f\n", users[i].nome, &(users[i].idade), &(users[i].saldo));

    }
    fclose(usuariosArquivo);
    return users;
}

int saveAllUsers(cadastro* c, int numUsers){ // Função para salvar o arquivo inteiro (opções 4 e 5)
    FILE* usuariosArquivo = fopen("usuarios.txt", "w");
    for (int i = 0; i < numUsers; i++){
        fprintf(usuariosArquivo, "%s, %d, %.2f\n", c[i].nome,c[i].idade, c[i].saldo);
        //printf("%s, %d, %.2f\n", c[i].nome, c[i].idade, c[i].saldo);
    }
    fclose(usuariosArquivo);
    return 0;
}

int main()
{
    setlocale(LC_ALL,"");
    printf("UAIBANK\n");
    printf(" 1 Inserção de um novo usuário: ");
    //Inserção de usurarios deverá ser feita separado por virgula.
    printf("\n================================================ \n");
    printf(" 2 Inserção de vários usuários: ");
    printf("\n================================================ \n");
    printf(" 3 Busca de um usuário por id: ");
    printf("\n================================================ \n");
    printf(" 4 Transferências entre usuários: ");
    printf("\n================================================ \n");
    printf(" 5 Remoção de um usuário por id: \n\n");



    char opt = 0;
    do {
        opt = getch();
        if (opt == '1'){
            puts("1");
            userRegister(1);
            printf("\n================================================ \n");

        }
        if (opt == '2'){
            puts("2");
            short int rep;
            scanf("%u", &rep); setbuf(stdin,NULL);
            for (int i = 0; i < rep; i++){ // Chama a função de registro quantas vezes desejado
                userRegister();
            }
            printf("\n================================================ \n");

        }
        if (opt == '3'){
            puts("3");

            FILE* usuariosArquivo = fopen("usuarios.txt", "r");
            cadastro* users;
            users = openFile();
            int lines = getLines(usuariosArquivo);
            int p;
            scanf("%d",&p);
            if (p<lines){
                printf("%s, %d, %.2f\n", users[p].nome, users[p].idade, users[p].saldo);
            }  // Mostra o usuários de ID p
            fclose(usuariosArquivo);
            printf("\n================================================ \n");

        }
        if (opt == '4'){
            puts("4");
            int idO, idD;
            float quant;
            scanf("%u,%u,%f", &idO, &idD, &quant); //Separados por virgula
            cadastro* users;
            users = openFile();
            users[idO].saldo -= quant;
            users[idD].saldo += quant;
            FILE* usuariosArquivo = fopen("usuarios.txt", "r");
            int lines = getLines(usuariosArquivo);
            fclose(usuariosArquivo);
            saveAllUsers(users, lines);
            printf("\n================================================ \n");

        }
        if (opt == '5'){
            puts("5");
            int id;
            scanf("%u", &id);
            cadastro* users;
            users = openFile();
            strcpy(users[id].nome,"xxxxx");
            users[id].idade = 0;
            users[id].saldo = 0;
            FILE* usuariosArquivo = fopen("usuarios.txt", "r");
            int lines = getLines(usuariosArquivo);
            fclose(usuariosArquivo);
            saveAllUsers(users, lines);
            printf("\n================================================ \n");

        }
    } while(opt != 0x08 && opt != 0x1B); // Encerra o programa quando apertar ESC ou Backspace


    return 0;
}
