#include <time.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

// Saving Highscores:
struct player
{
	char name[18];
	long int time;
}score;

void saveHighscore( int diffTime )
{
	FILE *fptr;
	fptr = fopen("scores.su", "ab");

	printf("Enter Player Name - ");
	gets(score.name);  // I need to make name.length <=18

	score.name[18]='\0';
	score.time = diffTime;
	fwrite( (char*)&score, 1, sizeof(score),fptr );

	fclose(fptr);
}


// Printing Highscores:

void paddedName( char name[] )
{
	printf(" %-19s", name);
}

void paddedTime( long int time )
{
	int h = time/3600;
	int m = (time%3600)/60;
	int s = time%60;
	printf("   %02d : %02d : %02d   ",h,m,s);
}

void print(int n,char c)
{
	while(n--)	printf("%c",c);
}

void printHighscores()
{
	system("cls");
	char names[10][18];
	long int times[10];
	FILE *fptr;
	fptr = fopen("scores.su", "rb");

	cout<<"\n\n\n			HIGH SCORES:";
	printf("\n	%c",201); print(20,205); printf("%c",209); print(20,205); printf("%c",187);

	// Printing first alone
	fread( (char*)&score, 1, sizeof(score),fptr );
	printf("\n	%c",186);
	paddedName(score.name);
	printf("%c ",179);
	paddedTime(score.time);
	printf(" %c",186);

	// PRINTING :
	while(fread( (char*)&score, 1, sizeof(score),fptr ))
	{
		printf("\n	%c",199); print(20,196); printf("%c",197); print(20,196); printf("%c",182);
		printf("\n	%c",186);
		// Instead of printing, add it to top10 with insertion
		paddedName(score.name);			// Input from file
		printf("%c ",179);
		// Instead of printing, add it to top10 with insertion
		paddedTime(score.time);			// Input from file
		printf(" %c",186);
	}
	printf("\n	%c",200); print(20,205); printf("%c",207); print(20,205); printf("%c",188);
	//system("pause");
}
