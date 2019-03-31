#include<stdio.h>
#include"liby.h"
#include"stdlib.h"
#include<string.h>
#include<Windows.h>
void ajouter()
{
	VEHICULE voiture;

	HANDLE  hConsole;
    int f;
  printf("                       ");
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, f=14);

	printf("\nVeuillez saisir le nom de la voiture a ajouter\n");

		/*int j=0;
		char ch;
		ch=getchar();
		ch=' ';
		while(ch!='\n')
			{	ch=getchar();
				voiture.nom[j]=ch;
				j++;
			}
		voiture.nom[j]='\0';*/
	SetConsoleTextAttribute(hConsole, f=7);
	scanf("%s",voiture.nom);

	SetConsoleTextAttribute(hConsole, f=14);
	printf("\nSasie de le matricule ABCD TU EFG \n");
	do{
	SetConsoleTextAttribute(hConsole, f=14);
	printf("\nsaisir les 4 chiffres\n");
	SetConsoleTextAttribute(hConsole, f=7);
	scanf("%d",voiture.matricule);
	if(*(voiture.matricule) <1 || *(voiture.matricule)>9999)
		{	SetConsoleTextAttribute(hConsole, f=12);
			printf("\nError !\n");
		}
	}while(*(voiture.matricule) <1 || *(voiture.matricule)>9999 ); // Les matricules sont encadrees entre 1 et 9999

	do{
		SetConsoleTextAttribute(hConsole, f=14);
	printf("\nsaisir les 3 chiffres\n");
	SetConsoleTextAttribute(hConsole, f=7);
	scanf("%d",voiture.matricule+1);
	if(*(voiture.matricule+1) <150 || *(voiture.matricule+1)>201)
		{	SetConsoleTextAttribute(hConsole, f=12);
			printf("\nError\n");
		}
	}while(*(voiture.matricule+1) <150 || *(voiture.matricule+1)>201); // les voitures de locations ne dépassent pas les 5 ans d'age !
	
	SetConsoleTextAttribute(hConsole, f=14);
	printf("\nSaisir sa categorie\n");
	SetConsoleTextAttribute(hConsole, f=7);
	scanf("%s",voiture.categorie); // Il ya plusieurs de catégories telque la coupee , la berline etc ..

	SetConsoleTextAttribute(hConsole, f=14);
	printf("\nSaisir sa boite \n");
	SetConsoleTextAttribute(hConsole, f=7);
	scanf("%s",voiture.boite); // On distingue maintes types de boites et on laisse le choix a l'utilisateur d'entrer par exp soit "A" soit "Auto"..
	do{
	SetConsoleTextAttribute(hConsole, f=14);
	printf("\nSaisir la tarif\n");
	SetConsoleTextAttribute(hConsole, f=7);
	scanf("%d",&voiture.tarif);
	if(voiture.tarif<100)
		{	SetConsoleTextAttribute(hConsole, f=12);	// le minimum des tarifs est 100 
			printf("\nError !\n");
		}
	}
	while(voiture.tarif<100);	
	do{
	SetConsoleTextAttribute(hConsole, f=14);
	printf("\nSaisir le kilometrage\n");
	SetConsoleTextAttribute(hConsole, f=7);
	scanf("%d",&voiture.km);
	if(voiture.km<0 || voiture.km >999999)
		{	SetConsoleTextAttribute(hConsole, f=12);
			printf("\nError\n"); // le km ne peut pas etre négatif et ne peut pas etre > ou = a 1million.
		}
	}				
	while(voiture.km <0 || voiture.km>999999);

	FILE* fp;
	fp=fopen("agence.txt","a");
	if(fp == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

	fprintf(fp,"%s %d %d %s %s %d %d\n",voiture.nom,voiture.matricule[1],voiture.matricule[0],voiture.categorie,voiture.boite,voiture.tarif,voiture.km);
	//fprintf(fp,"%d",voiture.km);
   
   fclose(fp);

}

void afficher()
{
	char tab[1000];
	FILE *fp1;
	fp1=fopen("agence.txt","r");
	/*if(fp)
	{
		fscanf(fp,"%[^\n]", tab);
    }
	printf("\nvotre text est %s\n ",tab);*/
	
	
	char c;
	printf("\n");
	while((c = getc(fp1)) != EOF) {
    putchar(c);
	
}
	fclose(fp1);
}

void modifier()

{
FILE *old,*newfile;
		char nom1[20];
	
		HANDLE  hConsole;
		int f;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		old=fopen("agence.txt","r");
		newfile=fopen("agence1.txt","w");
		int km1;
		SetConsoleTextAttribute(hConsole, f=14);
		printf("\nEntrer le nom correspondant a la voiture a modifer\n");
		SetConsoleTextAttribute(hConsole, f=7);
		scanf("%s",nom1);
		do{
		SetConsoleTextAttribute(hConsole, f=14);
		printf("entrer le nv km ");
		SetConsoleTextAttribute(hConsole, f=7);
		scanf("%d",&km1);
		if(km1<0 || km1>999999)
			{SetConsoleTextAttribute(hConsole, f=12);
			printf("Error\n");
			}
		}while(km1<0 || km1>999999);
	
		char nom[20];
		int mat3,mat4;	
		char categorie[10];
			char boite[10];
			int tarif;
			int km;
			int chif3,chif4;
			char t1[100];
			
		while(fscanf(old,"%s %d %d %s %s %d %d\n",nom,&mat3,&mat4,categorie,boite,&tarif,&km)!=EOF)
			{
			
		
			
			if(strcmp(nom1,nom)==0)
				{
					fprintf(newfile,"%s %d %d %s %s %d %d\n",nom1,mat3,mat4,categorie,boite,tarif,km1);
				}
			
			else
				{
					fprintf(newfile,"%s %d %d %s %s %d %d\n",nom,mat3,mat4,categorie,boite,tarif,km);
				}
		}
		fclose(newfile);	
		fclose(old);

}

void rename_et_remove()
{
	FILE *fp,*fp1;
		fp=fopen("agence.txt","r");
		fp1=fopen("agence1.txt","r");
		fclose(fp);
		fclose(fp1);
		remove("agence.txt");
		rename("agence1.txt","agence.txt");
}

void rename_et_remove_2()
{
	FILE *fp,*fp1;
		fp=fopen("agence.txt","r");
		fp1=fopen("agence2.txt","r");
		fclose(fp);
		fclose(fp1);
		remove("agence.txt");
		rename("agence2.txt","agence.txt");
}

void rename_et_remove_3()
{
	FILE *fp,*fp1;
		fp=fopen("agence.txt","r");
		fp1=fopen("agence3.txt","r");
		fclose(fp);
		fclose(fp1);
		remove("agence.txt");
		rename("agence3.txt","agence.txt");
}

void rename_et_remove_4()
{
	FILE *fp,*fp1;
		fp=fopen("agence.txt","r");
		fp1=fopen("agence4.txt","r");
		fclose(fp);
		fclose(fp1);
		remove("agence.txt");
		rename("agence4.txt","agence.txt");
}

void supprimer()
{
		FILE *old,*newfile;
		char nom1[20];

		HANDLE  hConsole;
		int f;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		old=fopen("agence.txt","r");
		newfile=fopen("agence2.txt","w");
		int km1;
		SetConsoleTextAttribute(hConsole, f=14);
		printf("\nEntrer le nom correspondant a la voiture a supprimer\n");
		SetConsoleTextAttribute(hConsole, f=7);
		scanf("%s",nom1);
	
		char nom[20];
		int mat3,mat4;	
		char categorie[10];
			char boite[10];
			int tarif;
			int km;
			int chif3,chif4;
			char t1[100];
			
		while(fscanf(old,"%s %d %d %s %s %d %d\n",nom,&mat3,&mat4,categorie,boite,&tarif,&km)!=EOF)
			{
						
			if(strcmp(nom1,nom)!=0)
				{
					fprintf(newfile,"%s %d %d %s %s %d %d\n",nom,mat3,mat4,categorie,boite,tarif,km);
				}
			
		}
		fclose(newfile);	
		fclose(old);
}

void permuter(int*a,int*b)
{
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;

}
void trier_tarif()
{	
	FILE* old,*newfile,*old1;
	int tab1[100];
	old=fopen("agence.txt","r");
	int i=0;
	char nom[20];
		int mat3,mat;	
		char categorie[10];
			char boite[10];
			int tarif;
			int km;
			int chif3,chif4;
	while(fscanf(old,"%s %d %d %s %s %d %d\n",nom,&mat3,&mat,categorie,boite,&tarif,&km)!=EOF)
			{
						
			tab1[i]=tarif;
			i++;
			
		}
	rewind(old);
	fclose(old);
	/*printf("\naffichage tableau avant trie\n");
	for(int j=0;j<i;j++)
	{
		printf("tab1[%d]=%d\n",j,tab1[j]);
	}
	printf("i=%d",i);*/
	
	int indicetemp;
	for(int j1=0;j1<i;j1++)
	{
		indicetemp=j1;
		for(int k1=j1+1;k1<i;k1++)
		{
			if(tab1[k1]<tab1[indicetemp])
				indicetemp=k1;
		}
		permuter(&tab1[j1],&tab1[indicetemp]);
	}		

		
	/*printf("\naffichage tableau apres trie \n");
	for(int j=0;j<i;j++)
	{
		printf("tab1[%d]=%d\n",j,tab1[j]);
	}*/
	
	

	
	old1=fopen("agence.txt","r");
	rewind(old1);

	newfile=fopen("agence3.txt","w");

	for(int j=0;j<i;j++)
		{
			while(fscanf(old1,"%s %d %d %s %s %d %d\n",nom,&mat3,&mat,categorie,boite,&tarif,&km)!=EOF)
			{
				if(tab1[j]==tarif)
					{	//printf("tarif %d du %s lu\n",tarif,nom);
						fprintf(newfile,"%s %d %d %s %s %d %d\n",nom,mat3,mat,categorie,boite,tarif,km);
						break;

					}
			}
			rewind(old1);
		}
	fclose(old1);
	fclose(newfile);
}

void trier_age()
{	
	FILE* old,*newfile,*old1;
	int tab1[100][2];
	old=fopen("agence.txt","r");
	int i=0;
	char nom[20];
		int mat3,mat;	
		char categorie[10];
			char boite[10];
			int tarif;
			int km;
			int chif3,chif4;
	while(fscanf(old,"%s %d %d %s %s %d %d\n",nom,&mat3,&mat,categorie,boite,&tarif,&km)!=EOF)
			{
						
			tab1[i][0]=mat3;
			tab1[i][1]=mat;
			i++;
			
		}
	rewind(old);
	fclose(old);
	/*printf("\naffichage tableau avant trie\n");
	for(int j=0;j<i;j++)
	{
		printf("tab1[%d][0]=%d et tab1[%d][1]=%d\n",j,tab1[j][0],j,tab1[j][1]);
	}
	printf("i=%d",i);*/
	
	int indtemp;
	for (int j=0;j<i;j++)
	{
		indtemp=j;
		for(int k=j+1;k<i;k++)
		{
			if((tab1[k][0]>tab1[indtemp][0]) || ( tab1[k][0]==tab1[indtemp][0] && tab1[k][1]>tab1[indtemp][1] ))
				indtemp=k;
		}
		permuter(&tab1[j][0],&tab1[indtemp][0]);
		permuter(&tab1[j][1],&tab1[indtemp][1]);
	}



	/*printf("\naffichage tableau apres trie \n");
	for(int j=0;j<i;j++)
	{
		printf("tab1[%d][0]=%d et tab1[%d][1]=%d\n",j,tab1[j][0],j,tab1[j][1]);
	}
	printf("i=%d",i);*/

	
	old1=fopen("agence.txt","r");
	
	newfile=fopen("agence4.txt","w");
	fseek(old1, 0, SEEK_SET);

	for(int j=0;j<i;j++)
		{
			//while(fscanf(old1,"%s %d %d %s %s %d %d\n",nom,&mat3,&mat,categorie,boite,&tarif,&km)!=EOF)
			for(int j1=0;j1<i;j1++) 
			{
				fscanf(old1,"%s %d %d %s %s %d %d\n",nom,&mat3,&mat,categorie,boite,&tarif,&km);
				if(tab1[j][0]==mat3 && tab1[j][1]==mat)
					{
						fprintf(newfile,"%s %d %d %s %s %d %d\n",nom,mat3,mat,categorie,boite,tarif,km);
						

					}
				
			}
			rewind(old1);
		}
	
	fclose(old1);
	fclose(newfile);
}