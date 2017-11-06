#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Multiplication(float a, float b){ // Définit la fonction pour multiplier deux nombres
	return(a*b);
}


float Division(float a, float b){ // Définit la fonction pour diviser deux nombres
	return(b/a);
}


float Addition(float a, float b){
	return(a+b);
}


float Soustraction(float a, float b){
	return(b-a);
}


float Power(int a, int b){
	float r;
	int n;
	r = 1;
	for(n=0;n<b;n++){
		r = r * a;
	}
	return r;
}


float Factorielle(float b){
	float r;
	int i;
	r = 1;
		for(i=1;i<=b;i++){
			r = r * i;
		}
	return r;
}


float PiLeibniz(float b){
	float r;
	int i;
	r = 0;
	for(i=0;i<b;i++){
		r = r + (pow(-1,i)/((2*i)+1));
	}
	r = r*4;
	return r;
}

float Racine(float a, float b){
	float r;
	r = pow(b,1.0/a);
	return r;
}

int main(int argc, char *argv[]) {





	char entree; // On crée une chaine de caractères appelée entree, qui correspond au chiffre entré par l'utilisateur
	char operation = '+'; // On crée un caractère operation appelée +, qui permettra de détecter quelle opération l'utilisateur souhaite effectuer (division, multiplication, addition, soustractio)
	int i;
	float r = 0;
	float a = 0; // On définit a en nombre entier et on lui attribue la valeur 0
	float b = 0; // On définit b en nombre entier et on lui attribue la valeur 0

	int etape = 1; // On définit etape en nombre entier et on lui attribue la valeur 1, permettra de gérer nos étapes de calcul
	int isFirst = 1; // On définit isFirst en nombre entier et on lui attribue la valeur 1, permettra de vérifier si c'est notre premier calcul ou non

	printf("ArgV Contient %i Arguments\n", argc);

	int isArg =0;
	if(argc >= 3)
	{
		a = (float)atoi(argv[1]);
		printf("1) %s 2) %s 3) %s 4) %s\n", argv[0], argv[1], argv[2], argv[3]);
		char op = argv[2][0];
		printf("2) %i 4) %i op) %c\n" , atoi(argv[1]), atoi(argv[3]), op);
		b = (float)atoi(argv[3]);


		if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == 'R' || op == 'F' || op == 'P')
		{
			operation = argv[2][0];
		}
		isArg = 1;

	}

	if(isArg == 0)
	{

	do{ // Boucle DO (faire)





		printf("Veuillez entrer un chiffre : ");
		scanf("%c", &entree); // Demande à l'utilisateur d'entrer le caractère qui sera notre chiffre

		char merde = 0; // Permet d'empecher que lorsqu'on appuit sur entrée pour passer à la suite du calcul quand on rentre un chiffre, on ne compte pas entrée avec le chiffre.
		while (merde != '\n'){
			scanf("%c", &merde);
		}

			if (entree == '+' || entree == '-' || entree == '*' || entree == '/' || entree == '^' || entree == 'R' || entree == 'F' || entree == 'P'){ // Si l'entr�e de l'utilisateur est une op�ration, alors :

				if(isFirst == 0) // Si c'est notre premier calcul, alors :
				{


				operation = entree; // Permet de stocker l'opérateur dans notre variable operation qui est une suite de caractères
				b = a; // On stocke le premier chiffre dans b puis on vide a afin de pouvoir écrire un autre chiffre, puis on redemande un chiffre
				a = 0;
				isFirst = 1; // isFirst passe à 1 et notre prochain calcul ne sera alors plus considéré par le premier
				printf("a = %f , b = %f \n", a, b); // On affiche la valeur de a et de b au fur et à mesure du calcul

				}else // Sinon
				{
					printf("Vous ne pouvez pas entrer un operateur avant d'entrer un nombre");
				}


			}else if(entree != '='){ // Sinon si on appuie pas sur = :

				isFirst = 0; // Premier calcul
				a = a*10 + atoi(&entree); // Permet de décaler la valeur du chiffre précédent de 1 vers la gauche (*10) afin de créer un nombre avec un nouveau chiffre
				printf("a : %f\n", a); // On affiche la valeur du nombre qui a qui se forme au fur et à mesure que l'on écrit
			}


	}while(entree != '='); // Tant que notre entree utilisateur est différente de = :

}
	if(operation == '+'){ // Sinon si l'utilisateur tape + on effectue une addition

			r = Addition(a,b);
			printf("Calcul : %f %c %f\n", a, operation, b); // Décrit le calcul qu'on a effectué en éétapes
			printf("Calcul effectue : %f", r); // Affiche le résultat du calcul

		}else if(operation == '-'){ // Sinon si l'utilisateur tape - on effectue une soustraction

			r = Soustraction(a,b);
			printf("Calcul : %f %c %f\n", b, operation, a); // Décrit le calcul qu'on a effectué en étapes
			printf("Calcul effectue : %f", r); // Affiche le résultat du calcul

		}else if(operation == '*'){ // Sinon si l'utilisateur tape * on effectue une multiplication

			r = Multiplication(a,b);
			printf("Calcul : %f %c %f\n", a, operation, b); // Décrit le calcul qu'on a effectué en étapes
			printf("Calcul effectue : %f", r); // Affiche le résultat du calcul

		}else if(operation == 'R'){ // Sinon si l'utilisateur tape - on effectue une soustraction

			r = Racine(a, b);
			printf("Calcul effectue : %f", r); // Affiche le résultat du calcul

		}else if(operation == 'P'){

			r = PiLeibniz(b);
			printf("Calcul effectue : %f", r);

		}else if(operation == 'F'){

			r = Factorielle(b);
			printf("Calcul effectue : %f", r); // Affiche le résultat du calcul

		}else if(operation == '^'){

			r = Power(b,a);
			printf("Calcul : %f %c %f\n", b, operation, a); // Décrit le calcul qu'on a effectué en étapes
			printf("Calcul effectue : %f", r); // Affiche le résultat du calcul

		}else if(a != 0){ // Sinon si l'utilisateur tape / on effectue une division

			r = Division(a, b);
			printf("Calcul : %f %c %f\n", a, operation, b); // Décrit le calcul qu'on a effectu� en �tapes
			printf("Calcul effectue : %f", r); // Affiche le résultat du calcul

		}else{ // Sinon :

			printf("Division par 0 impossible"); // Il est impossible d'effectuer une division par 0 ! On affiche donc une erreur
		}


	return 0; // Fin du programme
}
