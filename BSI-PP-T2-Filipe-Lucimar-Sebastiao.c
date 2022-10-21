// Filipe - Lucimar - Sebastiao
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define count 4

int A, B;

void *func (void *arg) {

    long operacao = (long) arg;

    int dormir = 1 + rand()%20;

    if (operacao == 1)
    {
        int So = A+B;
        printf("Eu sou a Thread SOMA %d e vou dormir por %d segundos!\n", So, dormir);
        sleep(dormir);
        printf("Eu sou a Thread SOMA %d. Ja se passaram %d segundos, entao terminei!\n", So, dormir);
    } else if (operacao == 2)
    {
        int Su = A-B;
        printf("Eu sou a Thread SUBTRACAO %d e vou dormir por %d segundos!\n", Su, dormir);
        sleep(dormir);
        printf("Eu sou a Thread SUBTRACAO %d. Ja se passaram %d segundos, entao terminei!\n", Su, dormir);
    } else if (operacao == 3)
    {
        int Mu = A*B;
        printf("Eu sou a Thread MULTIPLICACAO %d e vou dormir por %d segundos!\n", Mu, dormir);
        sleep(dormir);
        printf("Eu sou a Thread MULTIPLICACAO %d. Ja se passaram %d segundos, entao terminei!\n", Mu, dormir);
    } else if (operacao == 4)
    {
        int Di = A/B;
        printf("Eu sou a Thread DIVISAO %d e vou dormir por %d segundos!\n", Di, dormir);
        sleep(dormir);
        printf("Eu sou a Thread DIVISAO %d. Ja se passaram %d segundos, entao terminei!\n", Di, dormir);
    }

    pthread_exit(NULL);

}

int main(void){

    system("clear");

    time_t start, end;
    
    printf("\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n| Inicio da Thread principal. |\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\n");

    srand(time(NULL));

    do
    {
        printf("Digite dois numeros (A e B), sendo (B != 0):\n");
        printf("A = ");
        scanf("%d", &A);
        printf("B = ");
        scanf("%d", &B);
        if (B == 0)
        {
            printf("ERRO -- B nao pode ser igual a 0!\n");
        }
    } while (B == 0);
    
    time(&start);

    pthread_t t[count];

    for (long i = 0; i < count; i++)
    {
        if (pthread_create(&(t[i]), NULL, func, (void *)(i+1)))
            printf("ERRO -- A thread nao pode ser criada.\n");
    }

    for (int i = 0; i < count; i++)
    {
        if (pthread_join(t[i], NULL))
            printf("ERRO -- A thread nao pode ser instanciada.\n");
    }

    time(&end);
    
    printf("\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n| Fim da Thread principal.  |\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");

    int tempo = end - start;

    printf("Tempo de execucao: %d segundos\n", tempo);
    
    return 0;

}