#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 150
#define NUM_STRINGS 1381

int main(int argc, char const *argv[]){

    FILE *arq;
    char jogos[NUM_STRINGS][MAX_LENGTH] = {""};
    int sorteio, n = 0;
    char menu;

    arq = fopen("./game-list/games.txt", "rt");
    

    if (arq == NULL){
        printf("Arquivo nao pode ser aberto\n");
        return 0;
    }
    for (int i = 0; i < NUM_STRINGS; ++i) {
        fgets(jogos[i], 150, arq);
    }
    fclose(arq);
    
    SORTEIO:

    srand( (unsigned)time(NULL) );
    printf("\nNumero de jogos a serem sorteados:");
    scanf("%i", &sorteio);
    printf("\n");

    for (int i = 0; i < sorteio; ++i) {
        n = (rand() % 1380);
        printf("%s", jogos[n]);
    }

    printf("\nQuer fazer o sorteio novamente?");
    scanf("%s", &menu);

    if(menu=='s' || menu=='S'){
        goto SORTEIO;
    }
    else{
        return 0;
    }
    
}
