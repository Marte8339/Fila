#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char processo[50];

    struct no *next;
}no;

    struct no *inicio, *fim, *auxiliar;

    int contador = 0;

void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    inicio = NULL;
    auxiliar = NULL;
    fim = NULL;

    int opcao;

    do{
        system("cls");

        printf("\n\tFila");
        printf("\n\n|1|Inserir processo na Fila. ENQUEUE");
        printf("\n|2|Mostrar processo na Fila. SEQUEUE");
        printf("\n|3|Retirar processo da Fila. DEQUEUE");
        printf("\n|4|Sair.");

        printf("\n\nDigite sua opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            system("cls");
            enqueue();
        break;
        case 2:
            system("cls");
            sequeue();
        break;
        case 3:
            system("cls");
            dequeue();
        break;
        case 4:
            system("cls");
            printf("\n\tSaindo...\n");
            exit(0);
        break;
        default:
            system("cls");
            printf("\n\tOpcao nao encontrada!!\n\tTente novamente...\n\n");
            system("pause");
            main();
        }

    }while(opcao < 5);
    return;
}

void enqueue(){
    system("cls");

    if(contador >= 3){
        printf("\n\tLista cheia.\n");
        system("pause");
        main();
    }else if(inicio == NULL){
        fim = (no*)malloc(sizeof(no));
        fim->next = NULL;
        auxiliar = fim;
        inicio = fim;
    }else{
        fim = (no*)malloc(sizeof(no));
        auxiliar->next = fim;
        auxiliar = fim;
        fim->next = NULL;
    }

    printf("\nDigite o processo: ");
    scanf("%s", &fim->processo);

    limparBuffer();

    contador++;
}

void sequeue(){
    char xprocesso[50];
    int achou=0;

    system("cls");

    if(inicio == NULL){
        printf("\nFila vazia.\n");
        system("pause");
    }else{
        auxiliar = inicio;

        printf("\nDigite o nome do processo para ver sua posicao na fila: ");
        scanf("%s", &xprocesso);

        limparBuffer();

        for(int i=0;i<=contador;i++){
            if(strcmp(auxiliar->processo,xprocesso) == 0 && achou == 0){
                printf("\nPosicao: %i| Processo: %s\n", i,auxiliar->processo);
                achou = 1;
                system("pause");
            }else{
                auxiliar=auxiliar->next;
            }
        }

        if(achou == 0){
            printf("\nProcesso nao encontrado na Fila.\n");
            system("pause");
        }
    }
}

void dequeue(){
    if(inicio==NULL){
        printf("\nFila vazia.\n");
        system("pause");
    }else if(inicio == fim){
        free(inicio);
        inicio=NULL;
        auxiliar=NULL;
        fim=NULL;
        contador = 0;

        printf("\nLista esvaziada.\n");
        system("pause");
    }else{
        auxiliar = inicio;
        inicio = inicio->next;
        free(auxiliar);
        auxiliar = inicio;
        contador--;

        printf("\nUm processo foi retirado da lista.\n");
        system("pause");
    }
}
