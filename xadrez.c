#include <stdio.h>
#include <stdlib.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

// --- Contem funcoes globais utilizadas em mais de uma parte do programa ---
#pragma region Global
// --- Cria uma linha de separacao no console ---
void LinhaSeparadora(){
    printf("--------------------------\n");
}

void PularLinha(){
    puts("");
}

void PrintCima(){
    printf("Cima ");
}

void PrintBaixo(){
    printf("Baixo ");
}

void PrintEsquerda(){
    printf("Esquerda ");
}

void PrintDireita(){
    printf("Direita ");
}
#pragma endregion

// ===========================================================================
// LOOPS
// As funcoes abaixo executam a movimentacao de pecas de xadrez atraves de loops.
#pragma region LOOPS

// --- Implementação de Movimentação do Bispo ---
void MovimentarBispo_Loop(){
    int casas = 0;

    LinhaSeparadora();
    while (casas < 5)
    {
        casas++;
        PrintCima();
        PrintDireita();
    }

    printf("\nO bispo andou %d casas nessa direcao.", casas);
    PularLinha();
}

// --- Implementação de Movimentação da Torre ---
void MovimentarTorre_Loop(){
    int casas = 5;

    LinhaSeparadora();
    for (int i = 1; i <= casas; i++)
    {
        PrintDireita();
    }

    printf("\nA torre andou %d casas nesssa direcao. ", casas);
    PularLinha();
}

// --- Implementação de Movimentação da Rainha (Dama) ---
void MovimentarDama_Loop(){
    int casas = 0;
    int contador = 0;

    LinhaSeparadora();
    do
    {
        casas++;
        PrintEsquerda();
    } while (casas < 8);

    printf("\nA dama andou: %d casa nessa direcao.", casas);
    PularLinha();
}

// --- Implementação de Movimentação do Cavalo (LOOPS ANINHADOS) ---
void MovimentarCavalo_Loop(){
    int casaVertical, casaHorizontal;

    LinhaSeparadora();
    printf("o cavalo andou ");

    for(casaHorizontal = 0; casaHorizontal < 1; casaHorizontal++){
        while (casaVertical < 2)
        {
            PrintBaixo();
            casaVertical++;
        }

        PrintEsquerda();
    }

    printf("\nO cavalo andou %d casas para baixo e %d casa para a esquerda.", casaVertical, casaHorizontal);
    PularLinha();
}
#pragma endregion
// ===========================================================================

// ===========================================================================
// RECURSIVIDADE
// As funcoes abaixo executam a movimentacao de pecas de xadrez atraves de recursividade
#pragma region RECURSIVADADE
// --- A funcao recebe um parametro com o numero de casas que deve andar ---
void MovimentarDama_Recursivo(int n){
    int casas = n;
    // --- O if continuara sendo chamado ate que o valor da casa atinja 0 ---
    if(n > 1){
        PrintEsquerda();
        MovimentarDama_Recursivo(n -1);
    }

    printf("\nA dama andou: %d casas para e Esquerda", casas);
    PularLinha();
}

void MovimentarBispo_Recursivo(int n){
    int casas = n;

    if(n > 1){
        PrintCima();
        PrintDireita();
        MovimentarBispo_Recursivo(n -1);
    }

    printf("\nO bispo andou: %d casas para Cima e para a Diretira", casas);
    PularLinha();
}

void MovimentarTorre_Recursivo(int n){
    int casas = n;

    if(n > 1){
        PrintDireita();
        MovimentarTorre_Recursivo(n -1);
    }

    printf("\nA torre andou: %d casas para Diretira", casas);
    PularLinha();
}
#pragma endregion
// ===========================================================================

// ===========================================================================
// LOOPS COMPLEXOS
// A funcao abaixo movimenta o cavalo utilizando a tecnica de loops complexos
#pragma region LOOPS COMPLEXOS
void MovimentarCavalo_LoopComplexo(){
    for(int i = 0, j = 4; i < j; i++){
        if(i < 2) {
            PrintCima();
            continue;
        }

        if(i == 3){
            PrintDireita();
            break;
        }
    }

    puts("\nO cavalo andou 2 casas para cima e 1 casa para a direita.");
    PularLinha();
}
#pragma endregion
// ===========================================================================

// ===========================================================================
// LOOPS ANINHADOS
// A funcao abaixo movimenta o bispo utilizando a tecnica de loops aninhados
#pragma region LOOPS ANINHADOS (Bispo)
void MovimentarBispo_LoopAninhado(){
    for (int i = 1; i <= 5; i++)
    {
        PrintCima();
        for (int j = i; j <= i; j++)
        {
            PrintDireita();
        }
    }
    PularLinha();
       
}
#pragma endregion
// ===========================================================================

void MenuPeca(){
    int valido = 0;
    int Escolha;

    do
    {
        LinhaSeparadora();
        puts("Qual peca deseja mover ?");
        puts("1 - Dama");
        puts("2 - Bispo");
        puts("3 - Torre");
        puts("4 - Cavalo");
        puts("0 - Sair");
        printf("Escolha: ");
        scanf("%d", &Escolha);
        PularLinha();

        switch (Escolha)
        {
            case 1:
                // MovimentarDama_Loop();
                MovimentarDama_Recursivo(8);
                break;
            case 2:
                // MovimentarBispo_Loop();
                // MovimentarBispo_Recursivo(5);
                MovimentarBispo_LoopAninhado();
                break;
            case 3:
                MovimentarTorre_Loop();
                // MovimentarTorre_Recursivo(5);
                break;
            case 4:
                // MovimentarCavalo_Loop();
                MovimentarCavalo_LoopComplexo();
                break;
            case 0:
                exit;
                valido = 1;
                break;
            default:
                puts("Escolha invalida !");
                system("pause");
                break;
        }
    } while (valido != 1);
    
}

int main(){
    
    MenuPeca();

    return 0;
}