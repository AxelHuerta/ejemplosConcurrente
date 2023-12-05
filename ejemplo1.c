#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// crea el método hola
void *hola(void *arg)
{
  // crea un string(?)
  char *msg = "Hola";

  for (int i = 0; i < strlen(msg); i++)
  {
    // imprime msg[i]
    printf("%c", msg[i]);
    fflush(stdout);
    // sleep 1 para un segundo
    usleep(1000000);
  }

  return NULL;
}

void *mundo(void *arg)
{
  char *msg = " mundo";

  for (int i = 0; i < strlen(msg); i++)
  {
    printf("%c", msg[i]);
    fflush(stdout);
    usleep(1000000);
  }

  return NULL;
}

int main()
{
  // declara los hilos
  pthread_t h1, h2;

  // crea los hilos
  pthread_create(&h1, NULL, hola, NULL);
  pthread_create(&h2, NULL, mundo, NULL);

  // espera a que los hilos terminen (si no se pone esto no se va a ver la ejecución de los hilos dado que el hilo principal main, termina antes que los otros 2)
  pthread_join(h1, NULL);
  pthread_join(h2, NULL);
  printf("\nFin");
}