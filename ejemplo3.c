#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

struct Parametro
{
  /* data */
  int id;
  float escalar;
  float matriz[3][3];
};

void init(float matriz[3][3])
{
  int i, j;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      matriz[i][j] = rand() * 100;
    }
  }
}

void *matrizPorEscalar(void *arg)
{
  struct Parametro *p;
  int i, j;
  p = (struct Parametro *)arg;

  for (i = 0; i < 3; i++)
  {
    printf("Hilo %d, multiplicando fila %d\n", p->id, i);
    for (j = 0; j < 3; j++)
    {
      p->matriz[i][j] = p->matriz[i][j] * p->escalar;
      usleep(1000000);
    }
  }
}

int main()
{
  pthread_t h1, h2;
  struct Parametro p1, p2;

  p1.id = 1;
  p1.escalar = 5.0;
  init(p1.matriz);

  p2.id = 2;
  p2.escalar = 10.0;
  init(p2.matriz);

  pthread_create(&h1, NULL, matrizPorEscalar, (void *)&p1);
  pthread_create(&h2, NULL, matrizPorEscalar, (void *)&p2);

  pthread_join(h1, NULL);
  pthread_join(h2, NULL);

  printf("\nfin");
}