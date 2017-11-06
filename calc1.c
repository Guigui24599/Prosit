#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char ope[4];
  char* erreur;
  int result = 0;

  ope[0] = '+';
  ope[1] = '-';
  ope[2] = '*';
  ope[3] = '/';

  int a[3];
  do {
    printf("Choisir son operateur : + (1) - (2) * (3) / (4) : Quitter (0)\n");
    scanf("%d", &a[0]);
    if (a[0] > 0 && a[0] <= 4){

      printf("Premier chiffre : \n");
      scanf("%d", &a[1]);
      printf("Deuxieme chiffre : \n");
      scanf("%d", &a[2]);

      if (a[0] == 1){
        result = a[1] + a[2];
      } else if (a[0] == 2) {
        result = a[1] - a[2];
      } else if (a[0] == 3){
        result = a[1] * a[2];
      } else if (a[0] == 4) {
        result = a[1] / a[2];
      }

      printf("Resultat : %d %c %d = %d\n", a[1], ope[a[0]-1], a[2], result);
    }
    else {
       if (a[0] !=0) {
         printf("erreur\n");

       }
    }
  }
  while (a[0] != 0);

  return 0;

}
