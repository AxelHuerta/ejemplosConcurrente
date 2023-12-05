#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void printfLento(void *args)
{
  char *msg;
  int i;
  msg = (char *)args;

  for (int i = 0; i < strlen(msg); i++)
  {
    printf("%c", msg[i]);
    fflush(stdout);
    sleep(1);
  }
}

int main()
{
  pthread_t h1, h2;
  char *hola = "Hola ", *mundo = "mundo";
  pthread_create(&h1, NULL, printfLento, (void *)hola);
  pthread_create(&h2, NULL, printfLento, (void *)mundo);

  pthread_join(h1, NULL);
  pthread_join(h2, NULL);

  printf("\nfin");
}