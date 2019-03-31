#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"liby.h"
#include<string.h>
#include"fonc.h"
#include<Windows.h>

void main()

{   //VEHICULE* voiture;
	
	char c,c1;
	
	 HANDLE  hConsole;
    int f;
  //printf("                       ");
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, f=121);

	printf("                        W  A  S  S  I  M : H  A  J  J  I : R  E  N  T : A : C  A  R                           \n\n\n");
	SetConsoleTextAttribute(hConsole, f=48);
	printf("                                                   MENU                                                       \n");
	SetConsoleTextAttribute(hConsole, f=11);
	printf("A:Ajouter\tS:Supprimer\tM:Modifier\tP:Afficher\tT:Trie par tarif\tG:Trie par age\tE:exit\n");
	while(1>0){
	SetConsoleTextAttribute(hConsole, f=10);
	scanf("%c",&c);
	//scanf("%c",&c);
	
	if(c=='A'){
		ajouter();
		SetConsoleTextAttribute(hConsole, f=9);
		printf("Liste apres ajout");
		SetConsoleTextAttribute(hConsole, f=8);
		afficher();
		SetConsoleTextAttribute(hConsole, f=9);
		printf("***A:Ajouter\tS:Supprimer\tM:Modifier\tP:Afficher\tT:Trie par tarif\tG:Trie par age\tE:exit\n");
		}
	if(c=='P')
		{	SetConsoleTextAttribute(hConsole, f=9);
			printf("Liste des voitures");
			SetConsoleTextAttribute(hConsole, f=8);
		afficher();
		SetConsoleTextAttribute(hConsole, f=9);
		printf("***A:Ajouter\tS:Supprimer\tM:Modifier\tP:Afficher\tT:Trie par tarif\tG:Trie par age\tE:exit\n");
		}
	if(c=='M')
	 {  SetConsoleTextAttribute(hConsole, f=9);
		 printf("Liste Avant Modification");
		 SetConsoleTextAttribute(hConsole, f=8);
		afficher();
		modifier();
		rename_et_remove();
		SetConsoleTextAttribute(hConsole, f=9);
		printf("Liste apres Modification");
		SetConsoleTextAttribute(hConsole, f=8);
		afficher();
		SetConsoleTextAttribute(hConsole, f=9);
		printf("***A:Ajouter\tS:Supprimer\tM:Modifier\tP:Afficher\tT:Trie par tarif\tG:Trie par age\tE:exit\n");
	 }
	if(c=='S')
	{	SetConsoleTextAttribute(hConsole, f=9);
		printf("Liste avant suppression");
		SetConsoleTextAttribute(hConsole, f=8);
		afficher();
		supprimer();
		rename_et_remove_2();
		SetConsoleTextAttribute(hConsole, f=9);
		printf("Liste apres suppression");
		SetConsoleTextAttribute(hConsole, f=8);
		afficher();
		SetConsoleTextAttribute(hConsole, f=9);
		printf("***A:Ajouter\tS:Supprimer\tM:Modifier\tP:Afficher\tT:Trie par tarif\tG:Trie par age\tE:exit\n");
	}
	
	if(c=='E') 
	{
	exit(0);
	}

	if(c=='T')
	{	
		SetConsoleTextAttribute(hConsole, f=9);
	printf("Liste avant trie");
	SetConsoleTextAttribute(hConsole, f=8);
	afficher();
	trier_tarif();
	SetConsoleTextAttribute(hConsole, f=9);
	printf("Liste apres trie");
	rename_et_remove_3();
	SetConsoleTextAttribute(hConsole, f=8);
	afficher();
	SetConsoleTextAttribute(hConsole, f=9);
	printf("***A:Ajouter\tS:Supprimer\tM:Modifier\tP:Afficher\tT:Trie par tarif\tG:Trie par age\tE:exit\n");
	}

	if(c=='G')
	{	
	SetConsoleTextAttribute(hConsole, f=9);
		printf("Liste avant trie");
		SetConsoleTextAttribute(hConsole, f=8);
	afficher();
	trier_age();
	SetConsoleTextAttribute(hConsole, f=9);
	printf("Liste apres trie");
	rename_et_remove_4();
	SetConsoleTextAttribute(hConsole, f=8);
	afficher();
	SetConsoleTextAttribute(hConsole, f=9);
	printf("***A:Ajouter\tS:Supprimer\tM:Modifier\tP:Afficher\tT:Trie par tarif\tG:Trie par age\tE:exit\n");
	}

	}
	
}