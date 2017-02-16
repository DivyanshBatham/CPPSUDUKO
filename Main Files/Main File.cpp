
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
void mainMenu( int choice );
void resetMenu( int choice);
const char current = 175;

int main()
{
	start:
	system("cls");
	int choice = 1;
	char ch;
	mainMenu(choice);
	while( (ch=getch()) != 13  )
	{
		system("cls");
		switch(ch)
		{
			// Arrow Keys are pressed:
			case 72 : if(choice>1) choice--;	break;
			case 80 : if(choice<2) choice++;	break;
		}	
		mainMenu(choice);
	}
	
	switch(choice)
	{
		case 1 : startGame();
				
		case 2 : score:
				 printHighscores();
				 choice = 1;
				 cout << "	      ";
				 cout << (choice==1 ? current : ' ') << " BACK\t ";
				 cout << (choice==2 ? current : ' ') << " RESET     ";
				 cout << (choice==3 ? current : ' ') << " EXIT";
				 while( (ch=getch()) != 13  )
				{
					//system("cls");
					switch(ch)
					{
						// Arrow Keys are pressed:
						case 75 : if(choice>1) choice--;	break;
						case 77 : if(choice<3) choice++;	break;
					}	
					print(36,'\b');
					cout << "	      ";
					cout << (choice==1 ? current : ' ') << " BACK\t ";
					cout << (choice==2 ? current : ' ') << " RESET     ";
					cout << (choice==3 ? current : ' ') << " EXIT";
				}				 
				 if(choice==1)
				 	goto start;
				 if(choice==3)
				    goto end;
				 if(choice==2)
				 {
				 	system("cls");
				 	choice = 1;
					resetMenu(choice);
					while( (ch=getch()) != 13  )
					{
						system("cls");
						switch(ch)
						{
							// Arrow Keys are pressed:
							case 75 : if(choice>1) choice--;	break;
							case 77 : if(choice<2) choice++;	break;
						}	
						resetMenu(choice);
					}	
					if(choice==1)
					  goto score;
					else
					 resetHighscores();
				 }
				 break;
	}
	
	end:
	return 0;
}

void resetMenu( int choice )
{
	cout << "\n\n\n\n	" << char(201); print(40,205); cout << char(187);
	cout << "\n	" << char(186); print(40,' ');  cout << char(186);
	cout << "\n	" << char(186) << " Are you sure you want to RESET Scores? " << char(186);
	cout << "\n	" << char(186); print(40,' ');  cout << char(186);
	cout << "\n	" << char(186) << "\t  " << (choice==1 ? current : ' ') << " NO\t    ";
	cout << (choice==2 ? current : ' ') << " YES(Exit) " << "         " <<char(186);
	cout << "\n	" << char(186); print(40,' ');  cout << char(186);
	cout <<	"\n	" << char(200); print(40,205); cout << char(188);
}

void mainMenu( int choice )
{
	cout << "\n\n\n\n	" << char(201); print(41,205); cout << char(187);
	cout << "\n	" << char(186); print(41,' ');  cout << char(186);
	cout << "\n	" << char(186); print(15,' '); cout << " CPP SUDUKO "; print(14,' '); cout << char(186) ;
	cout << "\n	" << char(186); print(41,' ');  cout << char(186);
	cout << "\n	" << char(186) << "\t" << (choice==1 ? current : ' ') << " START"; print(27,' '); cout <<char(186);
	cout << "\n	" << char(186) << "\t" << (choice==2 ? current : ' ') << " HIGHSCORE"; print(23,' '); cout <<char(186);
	cout << "\n	" << char(186); print(41,' ');  cout << char(186);
	cout << "\n	" << char(186); print(41,' ');  cout << char(186);
	cout <<	"\n	" << char(200); print(41,205); cout << char(188);
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
		/*
		if(grid[x][y].isEdit == 'F')
			system("COLOR 8 ");
		else
			system("COLOR 8 ");
		*/
		creategrid();
		
	}
}
