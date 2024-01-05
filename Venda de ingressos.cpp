#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define INGRESSOS 100

typedef struct {
    char nome[50];
    char cpf[15];
    char dataNascimento[11];
} Ingresso;

Ingresso ingressos[INGRESSOS ];
int totalIngressos = 0;

void venderIngresso() { setlocale(LC_ALL,"");
    if (totalIngressos >= INGRESSOS ) {
        printf("Limite de ingressos atingido.\n");
        return;
    }

    printf("Nome: ");
    fgets(ingressos[totalIngressos].nome, sizeof(ingressos[totalIngressos].nome), stdin);
    strtok(ingressos[totalIngressos].nome, "\n");

    printf("CPF: ");
    fgets(ingressos[totalIngressos].cpf, sizeof(ingressos[totalIngressos].cpf), stdin);
    strtok(ingressos[totalIngressos].cpf, "\n");

    printf("Ano de Nascimento: ");
    fgets(ingressos[totalIngressos].dataNascimento, sizeof(ingressos[totalIngressos].dataNascimento), stdin);
    strtok(ingressos[totalIngressos].dataNascimento, "\n");

    totalIngressos++;

    printf("Ingresso vendido com sucesso!\n");
}

void listarIngressos() {
    if (totalIngressos == 0) {
        printf("Nenhum ingresso vendido.\n");
        return;
    }

    printf("Listagem de ingressos:\n");

    for (int i = 0; i < totalIngressos; i++) {
        printf("Nome: %s\n", ingressos[i].nome);
        printf("CPF: %s\n", ingressos[i].cpf);
        printf("Data de Nascimento: %s\n", ingressos[i].dataNascimento);
        printf("===============================\n");
    }
}

void validarIngresso() {
    char cpf[15];
    int ingressoEncontrado = 0;

    printf("Digite o CPF para validar o ingresso: ");
    fgets(cpf, sizeof(cpf), stdin);
    strtok(cpf, "\n");

    for (int i = 0; i < totalIngressos; i++) {
        if (strcmp(ingressos[i].cpf, cpf) == 0) {
            ingressoEncontrado = 1;
            printf("Ingresso v�lido!\n");
            printf("Nome: %s\n", ingressos[i].nome);
            printf("CPF: %s\n", ingressos[i].cpf);
            printf("Data de Nascimento: %s\n", ingressos[i].dataNascimento);
            break;
        }
    }

    if (!ingressoEncontrado) {
        printf("Ingresso inv�lido.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("Selecione uma op��o:\n");
        printf("1 - Vender ingresso\n");
        printf("2 - Listar ingressos vendidos\n");
        printf("3 - Validar ingresso\n");
        printf("4 - Sair\n");
        scanf(" %d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1 :
                venderIngresso();
                break;
            case 2 :
                listarIngressos();
                break;
            case 3 :
                validarIngresso();
                break;
            case 4 :
                printf("Sair do programa...\n");
                break;
            default:
                printf("Op��o inv�lida\n");
        }

        printf("===============================\n");
    } while (opcao != 4);

    return 0;
}



