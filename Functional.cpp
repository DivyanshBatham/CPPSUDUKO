#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

void creategrid();
void fillDigits();
bool isValidSuduko();

//GLOBAL VARIABLES:
const int rank = 9;
// Position of Current Block (or Artificial Caret) i.e. [ ]
int x=0;
int y=0;
// Basic Structure of Suduko Game:
struct suduko
{
	char bOpen = ' ';// = '['; 	// Bracket Open '['
	char digit = ' ';	// Digit: 1-9 or '' if empty
	char bClose = ' '; //= ']'; 	// Bracket Close ']'
	char isEdit = 'T';	// Editable digit or not: 'T' for True i.e Editable, 'F' otherwise.
};
struct suduko grid[rank][rank];


void moveRight( )
{
	// Basic:
	if( y<rank-1 )
	{
		grid[x][y].bOpen = ' ';
		grid[x][y].bClose = ' ';
		y++;
		grid[x][y].bOpen = '[';
		grid[x][y].bClose = ']';
	}
}

void moveRightAdvanced( )
{
	grid[x][y].bOpen = ' ';
	grid[x][y].bClose = ' ';
	if( grid[x][y+1].isEdit=='T' && y<rank-1 )
	{
		y++;
		grid[x][y].bOpen = '[';
		grid[x][y].bClose = ']';
	}
	else
	{
		int t = y;
		while( grid[x][y+1].isEdit == 'F' && y<rank-1 )
			y++;
		if( grid[x][y+1].isEdit == 'T' && y<rank-1 )
		{	
			y++;
			grid[x][y].bOpen = '[';
			grid[x][y].bClose = ']';	
		}
		else
		{
			y = t;
			grid[x][y].bOpen = '[';
			grid[x][y].bClose = ']';
		}		
	}
}

void moveLeft( )
{
	// Basic:
	if( y>=1 )
	{
		grid[x][y].bOpen = ' ';
		grid[x][y].bClose = ' ';
		y--;
		grid[x][y].bOpen = '[';
		grid[x][y].bClose = ']';
	}
}

void moveLeftAdvanced( )
{
	grid[x][y].bOpen = ' ';
	grid[x][y].bClose = ' ';
	if( grid[x][y-1].isEdit=='T' && y>=1 )
	{
		y--;
		grid[x][y].bOpen = '[';
		grid[x][y].bClose = ']';
	}
	else
	{
		int t = y;
		while( grid[x][y-1].isEdit == 'F' && y>=1 )
			y--;
		if( grid[x][y-1].isEdit == 'T' && y>=1 )
		{	
			y--;
			grid[x][y].bOpen = '[';
			grid[x][y].bClose = ']';	
		}
		else
		{
			y = t;
			grid[x][y].bOpen = '[';
			grid[x][y].bClose = ']';
		}		
	}
}

void moveUp( )
{
	// Basic:
	if( x>=1 )
	{
		grid[x][y].bOpen = ' ';
		grid[x][y].bClose = ' ';
		x--;
		grid[x][y].bOpen = '[';
		grid[x][y].bClose = ']';
	}
}

void moveUpAdvanced( )
{
	grid[x][y].bOpen = ' ';
	grid[x][y].bClose = ' ';
	if( grid[x-1][y].isEdit=='T' && x>=1 )
	{
		x--;
		grid[x][y].bOpen = '[';
		grid[x][y].bClose = ']';
	}
	else
	{
		int t = x;
		while( grid[x-1][y].isEdit == 'F' && x>=1 )
			x--;
		if( grid[x-1][y].isEdit == 'T' && x>=1 )
		{	
			x--;
			grid[x][y].bOpen = '[';
			grid[x][y].bClose = ']';	
		}
		else
		{
			x = t;
			grid[x][y].bOpen = '[';
			grid[x][y].bClose = ']';
		}		
	}
}

void moveDown( )
{
	// Basic:
	if( x<rank-1 )
	{
		grid[x][y].bOpen = ' ';
		grid[x][y].bClose = ' ';
		x++;
		grid[x][y].bOpen = '[';
		grid[x][y].bClose = ']';
	}
}

void moveDownAdvanced( )
{
	grid[x][y].bOpen = ' ';
	grid[x][y].bClose = ' ';
	if( grid[x+1][y].isEdit=='T' && x<rank-1 )
	{
		x++;
		grid[x][y].bOpen = '[';
		grid[x][y].bClose = ']';
	}
	else
	{
		int t = x;
		while( grid[x+1][y].isEdit == 'F' && x<rank-1 )
			x++;
		if( grid[x+1][y].isEdit == 'T' && x<rank-1 )
		{	
			x++;
			grid[x][y].bOpen = '[';
			grid[x][y].bClose = ']';	
		}
		else
		{
			x = t;
			grid[x][y].bOpen = '[';
			grid[x][y].bClose = ']';
		}		
	}
}


int main()
{
	// Feeding Temp Digits:
	fillDigits();
	
	grid[x][y].bOpen = '[';
	grid[x][y].bClose = ']';
	
	char ch;
	while( (ch=getch()) != 27  )
	{
		system("cls");
		//creategrid();
		
		switch(ch)
		{
			// Submit:
			case 13 : if(isValidSuduko())
						cout <<"Correct";
					  else
					    cout <<"Wrong";
			
			// Arrow Keys are pressed:
			case 75 : moveLeftAdvanced();	break;
			case 77 : moveRightAdvanced();	break;
			case 72 : moveUpAdvanced();	break;
			case 80 : moveDownAdvanced();	break;
			
			// Number Keys are pressed:
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
			
		}
		isValidSuduko( );
		creategrid();
		
	}
	return 0;
}

// DON'T TOUCH THIS :
void creategrid()
{
	printf("\n\n");
	int rank = 9, mod = 3;
	// Top Line:
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,209,205,205,205,209,205,205,205,203,205,205,205,209,205,205,205,209,205,205,205,203,205,205,205,209,205,205,205,209,205,205,205,187);
	
	for(int i=0; i<rank; i++)	
	{
			printf("%c",186);
			for(int j=0; j<rank; j++)
			{
				if((j+1)%mod==0) // Special
					printf("%c%c%c%c",grid[i][j].bOpen,grid[i][j].digit,grid[i][j].bClose,186);
				else
					printf("%c%c%c%c",grid[i][j].bOpen,grid[i][j].digit,grid[i][j].bClose,179);	
			}	
		if((i+1)%mod==0 && i!=rank-1) //Bottom Line (Thick):
			printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,216,205,205,205,216,205,205,205,206,205,205,205,216,205,205,205,216,205,205,205,206,205,205,205,216,205,205,205,216,205,205,205,185);
		else if(i==rank-1) //Bottom Line (Thin):
			printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,207,205,205,205,207,205,205,205,202,205,205,205,207,205,205,205,207,205,205,205,202,205,205,205,207,205,205,205,207,205,205,205,188);
		else
			printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,196,196,197,196,196,196,197,196,196,196,215,196,196,196,197,196,196,196,197,196,196,196,215,196,196,196,197,196,196,196,197,196,196,196,182);
	
	}
	
	printf(" For Debugging Only:\n x=%d y=%d editable=%c",x,y,grid[x][y].isEdit);
}


void fillDigits()
{
	char digits[82]=" 87    9  6     1 2   8 7  89 3 62 5 2 9 8 4 1 64 7 89  9 4   1 1     5  4    92 ";
	//char digits[82]="732  4    1  6   494  5 8  89 42  16 7     2 62  37 59  4 1  722   7  4    3  689";
	for(int i=0,p=0; i<rank; i++)	
		for(int j=0; j<rank; j++,p++)
		{
			// Setting Digit:
			grid[i][j].digit = digits[p];	
			// Setting Editable or Not:
			if(digits[p]!=' ')
				grid[i][j].isEdit = 'F';
		}
}


bool isValidSuduko()
{
	int sum = 0;
	
	// Checking Rows:
	for( int i=0; i<rank; i++, sum=0 )
	{
		for( int j=0; j<rank; j++ )
		{
			if(grid[i][j].digit==' ')
				return false;					// Print Incomplete?	
			sum += grid[i][j].digit - '0';
		}
		if(sum!=45)  return false;
	}
	
	// Checking Columns:
	for( int j=0; j<rank; j++, sum=0 )
	{
		for( int i=0; i<rank; i++ )
		{
			if(grid[i][j].digit==' ')
				return false;					// Print Incomplete?
			sum += grid[i][j].digit - '0';
		}
		if(sum!=45)  return false;
	}

	// Checking Subcubes:
	/*
			1 | 2 | 3
			4 | 5 | 6
			7 | 8 | 9
			
	*/
	int s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0,s9=0;
	for( int i=0; i<rank; i++ )
	{
		for( int j=0; j<rank; j++ )
		{
			if(grid[i][j].digit==' ')
				return false;					// Print Incomplete?
			else
			{
				// Top Three:
				if( (i>=0 && i<=2) && (j>=0 && j<=2) )	s1 += grid[i][j].digit - '0';
				if( (i>=0 && i<=2) && (j>=3 && j<=5) )	s2 += grid[i][j].digit - '0';
				if( (i>=0 && i<=2) && (j>=6 && j<=8) )	s3 += grid[i][j].digit - '0';

				// Middle Three:
				if( (i>=3 && i<=5) && (j>=0 && j<=2) )	s4 += grid[i][j].digit - '0';
				if( (i>=3 && i<=5) && (j>=3 && j<=5) )	s5 += grid[i][j].digit - '0';
				if( (i>=3 && i<=5) && (j>=6 && j<=8) )	s6 += grid[i][j].digit - '0';									
				
				// Bottom Three:
				if( (i>=6 && i<=8) && (j>=0 && j<=2) )	s7 += grid[i][j].digit - '0';
				if( (i>=6 && i<=8) && (j>=3 && j<=5) )	s8 += grid[i][j].digit - '0';
				if( (i>=6 && i<=8) && (j>=6 && j<=8) )	s9 += grid[i][j].digit - '0';		
			}
		}
	}	
	if( s1!=45 || s2!=45 || s3!=45 || s4!=45 || s5!=45 || s6!=45 || s7!=45 || s8!=45 || s9!=45 )
		return false;
		
	return true;
}



