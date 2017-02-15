
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>

#include "Movement.h"
#include "Highscores.h"
using namespace std;

void creategrid();
void fillDigits();
bool isValidSuduko();
void startGame();

int main()
{
	int choice = 1;
	char current = 175;
	char ch;
	cout << "CPP SUDUKO!\n"; 
	cout << (choice==1 ? current : ' ') << " START\n";
	cout << (choice==2 ? current : ' ') << " HIGHSCORE";
	while( (ch=getch()) != 13  )
	{
		system("cls");
		switch(ch)
		{
			// Arrow Keys are pressed:
			case 72 : if(choice>1) choice--;	break;
			case 80 : if(choice<2) choice++;	break;
		}	
	
		cout << "CPP SUDUKO!\n";
		cout << (choice==1 ? current : ' ') << " START\n";
		cout << (choice==2 ? current : ' ') << " HIGHSCORE";
	}
	
	switch(choice)
	{
		case 1 : startGame(); break;
		case 2 : printHighscores(); break;
	}
	
	
	return 0;
}


void startGame()
{
	time_t startTime, endTime, diffTime;
	startTime = time (NULL);
	
	// Choosing an array ?
	fillDigits();
	
	grid[x][y].bOpen = '[';
	grid[x][y].bClose = ']';
	
	system("cls");
	creategrid();
	
	char ch;
	while( (ch=getch()) != 27  )
	{
		system("cls");
		
		switch(ch)
		{
			// Arrow Keys are pressed:
			case 75 : moveLeft();	break;
			case 77 : moveRight();	break;
			case 72 : moveUp();	break;
			case 80 : moveDown();	break;
			
			// Number Keys are pressed:
			case '0' : if(grid[x][y].isEdit == 'T')
						grid[x][y].digit = ' ';
					   break;
			case '1' : if(grid[x][y].isEdit == 'T')
						grid[x][y].digit = '1';
					   break;
			case '2' : if(grid[x][y].isEdit == 'T')
						grid[x][y].digit = '2';
					   break;
			case '3' : if(grid[x][y].isEdit == 'T')
						grid[x][y].digit = '3';
					   break;
			case '4' : if(grid[x][y].isEdit == 'T')
						grid[x][y].digit = '4';
					   break;
			case '5' : if(grid[x][y].isEdit == 'T')
						grid[x][y].digit = '5';
					   break;
			case '6' : if(grid[x][y].isEdit == 'T')
						grid[x][y].digit = '6';
					   break;
			case '7' : if(grid[x][y].isEdit == 'T')
						grid[x][y].digit = '7';
					   break;
			case '8' : if(grid[x][y].isEdit == 'T')
						grid[x][y].digit = '8';
					   break;
			case '9' : if(grid[x][y].isEdit == 'T')
						grid[x][y].digit = '9';
					   break;
			
			// Backspace:
			case 8 :  if(grid[x][y].isEdit == 'T')
						grid[x][y].digit = ' ';
					   break;
			
			// Submit:
			case 13 : if(!isValidSuduko())
					  {
					  	endTime = time (NULL);
					  	diffTime = endTime - startTime;
					  	cout <<"Correct and you took "<<diffTime;
					  	// Entering the data to the file
					  	
					  		saveHighscore( diffTime );
						return;	  	
					  }	 
					  else
					  	cout <<"Wrong";
					  break;	
		}
		
		creategrid();
		
	}
}
