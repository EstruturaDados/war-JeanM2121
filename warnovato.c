#include <stdio.h>
#include <stdlib.h>
#include <string.h> // STRCSPN
 
// CONSTANTES GLOBAIS

#define MAX_TERRITORIOS 100
#define TAM_STRING 100

// DEFINIÇÃO DA ESTRUTURA STRUCT

struct guerra {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
    
};

//FUNÇÃO LIMPAR BUFF DE ENTRADA

void limparbuffdeentrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
  
// FUNÇÃO PRINCINPAL( MAIN)

int main(){
    struct guerra territorio[MAX_TERRITORIOS];
    int total = 0;
    int opcao;
    int tropas;
    
    

    //LAÇO PRINCIPAL DO MENU

    do {
        //EXIBE MENU DE OPÇÕES
        printf("=============================\n");
        printf("   TERRITORIOS - PARTE 1\n");
        printf("=======================\n");
        printf("1 - Cadastrar territorios\n");
        printf("2 - Listar territorios\n");
        printf("0 - Sair\n");
        printf("-------------------------------\n");
        printf("Escolha uma opção");
    

    // Lê A OPÇÃO DO USUARIO

    scanf("%d", &opcao);
    limparbuffdeentrada(); // limpar o \n deixado pelo scanf

    //PROCESSAMENTO DA OPÇÃO

    switch (opcao) {
    case 1:// cadastro de territorios
    printf("---Cadastro de territorios---\n\n");

        if(total <  MAX_TERRITORIOS){
            printf("digite o nome do territorio:  ");
            fgets(territorio[total].nome, TAM_STRING, stdin);
            printf("digite a cor das tropas:  ");
            fgets(territorio[total].cor, TAM_STRING, stdin);
            printf("digite o quantidade de tropas:  ");
          
            
            territorio[total].nome[strcspn(territorio[total].nome, "\n")] = 
            territorio[total].cor[strcspn(territorio[total].cor, "\n")] = 
            

            
            scanf("%d", &territorio[total], tropas);
            limparbuffdeentrada();

           
            total = total +1;

            printf("\nterritorio cadastrado com sucesso!\n");
        } else {
            printf("biblioteca cheia não é possivel cadastrar mais terriorios.\n");
        }    
        printf("\npressione enter para continuar!\n");
        getchar();  
        break;
    case 2:
    printf("-------- Lista de territorios cadastrados-----\n\n");

    if(total == 0){
        printf("nenhum territorio cadastrado ainda.\n");
    
    } else {
        for(int i = 0;i < total; i++){
            printf("-----------------------\n");
            printf("territorio %d\n", i + 1);
            printf("nome: %s\n", territorio[i].nome);
            printf("cor: %s\n", territorio[i].cor);
            printf("tropas: %d\n", territorio[i].tropas);
        }
        printf("---------------------\n");
    }

    printf("\nPRESSIONE PARA CONTINUAR......\n");
    getchar();
    break;
    
    case 0:
    printf("\nsaindo do sistema....\n");
    break;

    default:
    printf("\nopção invalida! tente novamente.\n!");
    printf("\nPRESSIONE PARA CONTINUAR.....\n");
    getchar();
    break;
}
} while (opcao != 0);

return 0;

}
