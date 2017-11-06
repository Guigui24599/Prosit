#include <stdio.h>
#include <stdlib.h>

// On insère ici cette fonction pour permettre au programme de ne pas tomber en erreur plus bas
void purger(void) {
  int c;
  while ((c=getchar()) != '\n' && c != EOF); // EOF = End Of File : correspond a la valeur -1
}

// L'int isFullGoodChar nous permet de déterminer TOUS les caractères qui vont pouvoir etre utilisés : correspond au gros losange dans l'algorigramme
int isFullGoodChar(char goodChar) {
  if (goodChar == '1' || goodChar == '2' || goodChar == '3' || goodChar == '4' || goodChar == '5' || goodChar == '6' || goodChar == '7'
  || goodChar == '8' || goodChar == '9' || goodChar == '+' || goodChar == '-' || goodChar == '*' || goodChar == '/' || goodChar == '=')
  // ne pas oublier les apsotrophes qui déterminent un caractère.
  {
    return 1; // permet si jamais return 1, de continuer l'avancée du programme
  } else {
    return 0; // permet, en cas de mauvaise tape, de mettre le programme en erreur
  }
}

// L'int isOperator permet de définir que certains des bons caractères définis précédemment sont assignés à une opération de calcul
int isOperator(char goodChar) {
  if(goodChar == '+' || goodChar == '-' || goodChar == '*' || goodChar == '/')
  {
    return 1; // permet de pouvoir continuer le programme si aucun mauvais signe est entré
  } else {
    return 0; // permet de mettre le programme en erreur si un mauvais caractère est entré
  }
}

// L'int chartoInt va nous permettre de mettre, comme son nom l'indique, un caractère en un entier
int charToInt(char d) {
  char str[2];

  str[0] = d;
  str[1] = '\0';
  // La fonction strtol permet de convertir une chaine en un nombre de type long int
  return (int) strtol(str, NULL, 10);
  // le premier parametre est la chaine de caractère qui va etre convertie (notre char str avec ses deux valeurs)
  // le second parametre est l'adresse d'arret de la conversion (ici pas d'arret)
  // le troisieme parametre est la base dans laquelle la chaine sera convertie (ici, base 10)
}

// L'int calculer nous permet de definir l'action a effectuer en fonction de ce que va taper l'utilisateur comme signe de calcul
int calculer(int a1, int a2, char ope) { // on ajoute deux entiers et une opération
  int result = 0; // on commence par result = 0 car on n'a pas encore fait de calcul donc le résultat est forcément de 0
  if (ope == '+') {
    result = a1 + a2;
  } else if (ope == '-') {
    result = a1 - a2;
  } else if (ope == '*') {
    result == a1 * a2;
  } else if (ope == '/') {
    result = a1 / a2;
  }
}

// On s'attaque maintenant au programme qui permettra de pouvoir faire les calculs
int calc(int retenue) { // on entre un int calc qui recoit la valeur de l'int retenue
  int result = 0; // on introduit notre programme aux différentes valeurs auxquelles il aura affaire : ici le résultat. De base, il vaut 0 pour eviter une erreur
  int nombre1 = 0; // idem que pour au dessus, on introduit un des 2 nombres pour le clacul et il vaut 0 au début car l'utilisateur n'a pas entré de valeur
  int nombre2 = 0; // idem, vaut 0 car l'utilisateur n'a pas entré de valeur, nécessaire pour le fonctionnement du programme
  char ope;
  int error = 0; // notre int qui va mettre le programme en erreur si jamais il vaut 1, du coup il vaut 0
  int isFirst = 1; // représente si c'est la première fois qu'on fait un calcul ou pas (utile pour la retenue) donc vaut 1 au début car notre retenue vaut 0 (c'est notre premier calcul)
  int i = 1;
  char (entree);

  do { // permet de lancer les instructions que le programme doit suivre pour exécuter le ou les calculs
    scanf("%c", &entree ); // permet de débuter le calcul, correpond au premier Output dans l'algorigramme
    purger(); // renvoie à la fonction au début du fichier, permet donc d'éviter une erreur si l'utilisateur rentre un mauvais caractère

    if (isFullGoodChar(entree) == 1) { // si le return de la fonction plus haut est à 1
      if (isOperator(entree) == 1) { // idem que pour le isFullGoodChar
        if (i == 1 && isFirst == 0) { // si on en est au premier nombre et si on a déjà entré une valeur dedans
          ope = entree;
          i++; // on passe alors au 2ème nombre
          isFirst = 1;
      } else {
        if (retenue != 0) { // si retenue
          nombre1 = retenue;
          ope = entree;
          i++; // i prend la valeur i+1
        } else { // Sinon ca veut dire que c'est un signe et pas une retenue
          printf("Vous ne pouvez pas utiliser un signe maintenant, il n'y a pas de retenue : continuez le calcul ! \n");
        } // on a une erreur : error = 1;
      }
    } else if (entree == '=' && (isFirst == 1 || i != 2)) { // si on cherche a savoir le résultat sans avoir entré la 2ème valeur
      printf("Vous ne pouvez pas entrer '=' ici, continuez le calcul ! \n");
      entree = ' '; // il faut réinitialiser l'entrée pour ne pas remettre le programme à zéro (on essaye de ne pas sortir de la boucle do)

    } else if (entree != '=') { // c'est alors un nombre
       if (i == 1) { // si on est au premier nombre
         isFirst = 0; // prend la valeur 0 car ce ne sera plus la première fois qu'on entre une valeur
         nombre1 = nombre1 * 10 + charToInt(entree); // permet au nombre d'avoir une valeur en base 10 comprise par le système
       } else if (i == 2) { // si on est au 2ème nombre
         isFirst = 0; // prend la valeur 0 car ce ne sera plus la première fois qu'on entre une valeur
         nombre2 = nombre2 * 10 + charToInt(entree); // permet au nombre d'avoir une valeur en base 10 comprise par le système
       } else {
         printf("Erreur ???");
         error = 1; // error prend la valeur 1 : erreur inconnue qui ne devrait normalement pas arriver
       }

    } else {
      // si c'est =, alors on sort de la boucle while
    }
  } else {
    if (entree == 's') { // permet à l'utilisateur de pouvoir quitter le programme s'il le souhaite
      error = -1; // le -1 renvoie a notre EOF qui permet de terminer le programme
    } else { // saut de 2 lignes pour avoir une interface plus claire
      printf("La valeur %c n'est pas une bonne valeur, continuez ! \n\n", entree); //la valeur entrée par l'utilisateur est mauvaise et ne permet pas de contiuer
      // error prend la valeur 1
    }
  }
} while (entree != '=' && error == 0); // tant que la valeur d'entree n'est pas =, et qu'il n'y a pas d'erreur

if (error == 0) { // s'il n'y a pas d'erreur avec tout ce qui a été fait précédemment, alors on peut afficher le résultat du calcul
  result = calculer(nombre1, nombre2, ope);
  printf("Le resultat de l'operation %i %c %i est : %i\n\n", nombre1, ope, nombre2, result); //détermine à quel int chaque % va être relié : %i-nombre1, %c-ope, %i-nombre2...
} else if (error == -1) { // si une erreur est apparue, alors le programme s'arrete et le résultat ne peut etre affiché
  printf("Arret du programme \n\n");
  result = error; //le résultat prend la "valeur error"
} else {
  printf("Recommencez !\n\n");
  result = retenue;
}
return result; //permet de retourner le résultat
}
// toutes nos applications premières pour effectuer des opérations sont maintenant entrées dans notre programme
// il nous reste juste à tout intégrer dans le programme main pour que toutes les étpaes de calcul établies précédemment puissent se faire

int main(int argc, char *argv[]) {

  int retenue = 0; // la retenue vaut toujours 0 lors du premier calcul

  do {
    if (retenue == 0) { // si on commence bien notre calcul pour la première fois
      printf("Entrez le calcul que vous souhaitez effectuer,\nou entrez 's' pour quitter le programme : \n\n");
      // 2 sauts à la ligne pour une interface plus aérée
    } else { //si on n'en est pas à notre premier calcul et qu'on veut réutiliser ou pas le résultat du précédent
      printf("Entrez le calcul que vous souhaitez effectuer ou commencez par un signe pour utiliser la retenue\n Sinon, entrez 's' pour quiiter le programme :\n\n");
    }
    retenue = calc(retenue); //renvoie à notre fonction int calc(int retenue) qu'on a rentré plus haut
  } while (retenue != -1); // permet au programme de continuer tant que la fin du fichier n'est pas atteinte (NE PAS OUBLIER EOF = -1)

  return 0;
}
