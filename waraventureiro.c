#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[100];
    char cor[50];
    int tropas;
} territorio;

void liberarMemoria(territorio *p, int n) {
    for (int i = 0; i < n; i++) {
        free(p[i].nome);  // libera o nome do território
        free(p[i].cor);   // libera a cor do território
    }
    free(p); // libera o vetor principal
}

void limparbuffdeentrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int numTerritorios = 5;
    territorio *mapa = (territorio *) malloc(numTerritorios * sizeof(territorio));
    if (!mapa) {
        printf("Erro na memória!\n");
        return 1;
    }

    srand(time(NULL));

    printf("=== Cadastro de Territórios ===\n");
    for(int i = 0; i < numTerritorios; i++) {
        territorio *t = &mapa[i];
        printf("Nome do Território: ");
        fgets(t->nome, 100, stdin);

        printf("Cor do território: ");
        fgets(t->cor, 50, stdin);

        printf("Número de tropas: ");
        scanf("%d", &t->tropas);
        getchar();
        printf("\n========================================\n");
    }

    printf("\n=== Lista de Territórios ===\n");
    for(int i = 0; i < numTerritorios; i++) {
        territorio *t = &mapa[i];
        printf("Território: %s", t->nome);
        printf("Cor: %s", t->cor);
        printf("Tropas: %d\n", t->tropas);
        printf("\n----------------------\n");
    }

    int defensor, atacante;
    printf("Escolha seu território defensor (1 a 5): ");
    scanf("%d", &defensor);
    printf("Escolha seu território atacante (1 a 5): ");
    scanf("%d", &atacante);

    if(defensor == atacante) {
        printf(". FIM DE JOGO !!!!\n");
        free(mapa);
        return 0;
    }

    territorio *XDefensor = &mapa[defensor-1];
    territorio *XAtacante = &mapa[atacante-1];

    int dado_defensor = (rand() % 6) + 1;
    int dado_atacante = (rand() % 6) + 1;

    printf("\nBatalha entre %s e %s\n", XDefensor->nome, XAtacante->nome);
    printf("Defensor rolou: %d 🎲\n", dado_defensor);
    printf("Atacante rolou: %d 🎲\n", dado_atacante);

    if(dado_defensor > dado_atacante) {
        printf("Defensor venceu!\n");
        XAtacante->tropas -= 1;
        if(XAtacante->tropas <= 0) {
            printf("Território conquistado pelo defensor!\n");
            XAtacante->tropas = 1;
            strcpy(XAtacante->cor, XDefensor->cor);
        }
    } else if(dado_atacante > dado_defensor) {
        printf("Atacante venceu!\n");
        XDefensor->tropas -= 1;
    } else {
        printf("Empate!\n");
    }

    free(mapa);
    return 0;
}