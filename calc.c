#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

// void my_delay(int i)    /*Pause l'application pour i seconds*/
// {
//     clock_t start,end;
//     start=clock();
//     while(((end=clock())-start)<=i *CLOCKS_PER_SEC);
// }

void purger(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
// EOF = End Of File : correspond à la valeur -1
}

int isFullGoodChar(char goodChar)
{
  if(goodChar == '1' || goodChar == '2' || goodChar == '3' || goodChar == '4' || goodChar == '5' || goodChar == '6' || goodChar == '7'
  || goodChar == '8' || goodChar == '9' || goodChar == '0' || goodChar == '+' || goodChar == '*' || goodChar == '-' || goodChar == '/' || goodChar == '=')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isOperator(char goodChar)
{
  if(goodChar == '+' || goodChar == '*' || goodChar == '-' || goodChar == '/')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


// char *char2string(char c)
// {
//   char *str=malloc(2*sizeof(char));
//   if(str==NULL)
//     return NULL;
//   str[0]=c;
//   str[1]='\0';
//   return str;
// }

int charToInt(char d)
{
 char str[2];

 str[0] = d;
 str[1] = '\0';
 return (int) strtol(str, NULL, 10);
 // fonction strtol permet de convertir une chaine en un nombre de type long int
 // premier parametre est la chaine de caractere qu'on souhaite convertir
 // second parametre est adresse ou la conversion s'est arretee
 // troisieme parametre est la base dans laquelle on souhaite convertir la chaine
}


int calculer(int n1, int n2, char op)
{
  int result = 0;
  if(op == '+')
  {
    result = n1 + n2;
  }else if(op == '-')
  {
    result = n1 - n2;
  }else if(op == '*')
  {
    result = n1 * n2;
  }else if(op == '/')
  {
    result = n1 / n2;
  }
}

int calc(int retenue)
{
  int result = 0;
  int nb1 = 0;
  int nb2 = 0;
  char op;
  int error = 0;
  int isFirst = 1;
  int i = 1;
  char entree;
  do {


      scanf("%c", &entree);
      purger();



      if(isFullGoodChar(entree) == 1)
      {

        //printf("La valeur est : %c \n\n", entree); //debug
            if(isOperator(entree) == 1)
            {
                if(i == 1 && isFirst == 0) //si on en est au nb1 et si on a deja écrit dedans
                {
                  op = entree;
                  //printf("Operateur = %c\n" , op);
                  i++; //alors on passe au deuxième chiffre
                  isFirst = 1;

                }else{
                  if(retenue != 0)   // SI RETENUE
                  {
                    nb1 = retenue;
                    op = entree;
                    i++; // i= i+1;
                  }else //Sinon ça veut dire que c'est un signe et pas de retenue
                  {
                    printf("Vous ne pouvez pas utiliser un signe maintenant (pas de retenue), continuez votre calcul! \n");
                    //error = 1;
                  }

                }
            }else if(entree == '=' && (isFirst == 1 || i != 2)) // si on en est pas au deuxième chiffre ou qu'on a pas encore ecrit dans le chiffre et qu'on entre =
            { //(en gros si on en est pas au deuxième chiffre déjà écrit)

              printf("Vous ne pouvez pas entrer ' = ' ici, continuez votre calcul! \n");
              entree = ' '; //on réinitialise l'entrée pour ne pas sortir du do While

            }else if(entree != '=') // c'est un nombre
            {

                if(i == 1) //si on en est au premier chiffre
                {
                  isFirst = 0;
                  nb1 = nb1 * 10 + charToInt(entree);
                }else if(i == 2) //si on en est au deuxième chiffre
                {
                  isFirst = 0;
                  nb2 = nb2 * 10 + charToInt(entree);
                }
                else
                {
                  printf("Error ?");
                  error = 1; //erreur inconnue, ne devrait normalement pas arriver (debug ?)
                }

               //printf("nb1 = %i , nb2 = %i , op = %c, i = %i\n" , nb1, nb2 , op, i);

            }else
            {
              //c'est =, on sort de la boucle do While
            }

        }
        else
        {
          if(entree == 's')
          {
            error = -1; //on quitte le programme
          }else
          {
            printf("La valeur %c n'est pas une bonne valeur, continuez \n\n", entree);
            //error = 1;
          }
        }
    //  my_delay(2);
    /* code */
  } while(entree != '=' && error == 0);

  if(error == 0)
  {
    result = calculer(nb1, nb2, op);
    //printf("nb1 = %i , nb2 = %i , op = %c, i = %i\n" , nb1, nb2 , op, i);
    printf("Le resultat de l'operation %i %c %i est : %i\n\n", nb1, op, nb2, result);
  }else if(error == -1)
  {
    printf("Arret du programme \n\n");
    result = error;
  }else
  {
    printf(", Recommencez ! \n\n");
    result = retenue;
  }



  return result;


}

int main(int argc, char *argv[])
{

    int retenue = 0;

    do {
        if(retenue == 0)
        {
          printf("Entrez votre calcul ('s' pour QUITTER) : \n\n");
        }else
        {
          printf("Entrez votre calcul ('s' pour QUITTER, commencez par un signe pour utiliser la retenue) : \n\n");
        }
        retenue = calc(retenue);
    } while(retenue != -1);


    return 0;
}
