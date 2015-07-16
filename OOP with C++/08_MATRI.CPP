/**************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++to create a class  called MATRIX using a two-dimensional
	array of integers. Implement the following operations bt overloading
	the operator == which checks the compatibility of two matrices to be
	added or subtracted. Perform the addition and subtraction by
	overloading the operator + and - respectively. Display the results
	by overloading the operator <<.
	if(m1 == m2)
	{
		m3 = m1 + m2;
		m4 = m1 - m2;
	}
	else
		display error;

\**************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <iomanip.h>

// C O N S T A N T S
#define MAX 10 // MAXIMUM NUMBER

///////////////////////////////////////////////////////////////////////////

enum bool
// ENUMERATED DATA TYPE FOR TRUE AND FALSE
{
	false = 0 ,true
};

///////////////////////////////////////////////////////////////////////////

class MATRIX
// CLASS OF THE MATRIX
{
	int **array;	     // 2D ARRAY
	int m, n;            // ROWS AND THE COLUMNS PREENT IN THE MATRIX

	public :
		MATRIX(int, int); // CONSTRUCTOR
		MATRIX() {}	  // EMPTY CONSTRUCTOR
		friend MATRIX operator + (MATRIX, MATRIX); // TO ADD
		friend MATRIX operator - (MATRIX, MATRIX); // TO SUBTRACT
		friend bool operator == (MATRIX, MATRIX);  // FOR CHECKING
		friend istream & operator >> (istream &, MATRIX &); // I/P
		friend ostream & operator << (ostream &, MATRIX); // DISPLAY
}; // END OF THE CONSTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

MATRIX :: MATRIX(int m1, int n1)
// CONSTRUCTOR DEFINATION
{
	m = m1;
	n = n1;
} // END OF THE CONSTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

MATRIX operator + (MATRIX m1, MATRIX m2)
// FRIEND FUNCTION TO ADD TWO MATRICES
{
	MATRIX ob;
	// ADDING THE MATRICES
	ob.m = m1.m;
	ob.n = m1.n;

	ob.array = new int * [ob.m];	// DYNAMIC MEMORY ALLOCATION
	for(int i = 0 ; i < ob.n ; i++)
		ob.array[i] = new int [ob.n];


	for(i = 0 ; i < m1.m ; i++)
		for(int j = 0 ; j < m1.n ; j++)
			ob.array[i][j] = m1.array[i][j] + m2.array[i][j];

	return ob;
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

MATRIX operator - (MATRIX m1, MATRIX m2)
// FRIEND FUNCTION TO SUBTRACT TWO MATRICES
{
	MATRIX ob;
	// SUBTRACTING MATRICES

	ob.m = m1.m;
	ob.n = m1.n;

	ob.array = new int * [ob.m];	// DYNAMIC MEMORY ALLOCATION FOR 2D ARRAY
	for(int i = 0 ; i < ob.n ; i++)
		ob.array[i] = new int [ob.n];

	for(i = 0 ; i < m1.m ; i++)
		for(int j = 0 ; j < m1.n ; j++)
			ob.array[i][j] = m1.array[i][j] - m2.array[i][j];

	return ob;
} // END OF THE FUNCTION

///////////////////////////////////////////////////////////////////////////

bool operator == (MATRIX m1, MATRIX m2)
// FRIEND FUNCTION CHECK WHETHER TWO MATRICES CAN BE ADDED OR NOT
{
	if ((m1.m == m2.m) && (m1.n == m2.n)) // MATRIX IS OF SAME ORDER
		return true;
	else
		return false;
} //END OF THE FUNCTION DEFIANTION

///////////////////////////////////////////////////////////////////////////

istream & operator >> (istream & is, MATRIX & ob)
// FRIEND FUNCTION TO READ THE MATRIX
{
	cout<<"\nPlease Enter the Number of rows in the matix : ";
	is>>ob.m;
	cout<<"\nPlease Enter the Number of columns in the matrix : ";
	is>>ob.n;

	ob.array = new int * [ob.m];	// DYNAMIC MEMORY ALLOCATION
	for(int i = 0 ; i < ob.n ; i++)
		ob.array[i] = new int [ob.n];

	cout<<"\nPlease Enter the Matrix elements :\n";

	// READING THE MATRIX ELEMENTS
	for(i = 0 ; i < ob.m ; i++)
		for(int j = 0 ; j < ob.n ; j++)
			is>>ob.array[i][j];

	return is;
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os, MATRIX ob)
// FRIEND FUNCTION TO DISPLAY THE MATIX
{
	os<<"\nThe matrix is as follows... \n\n";

	// PRINTING THE MATIX ELEMENTS
	for(int i = 0 ; i < ob.m ; i++)
	{
		for(int j = 0 ; j < ob.n ; j++)
			os<<"\t"<<ob.array[i][j];
		cout<<"\n";
	}
	return os;
} // END OF THE FUNCTION

///////////////////////////////////////////////////////////////////////////

int main(void)
// MAIN FUNCTION
{
	clrscr();

	while(1)
	{
		// PRINTING THE MENU
		int choice,number;
		cout<<"\n\n\t\t\t     **** MENU ****";
		cout<<"\nPlease Enter your Choice : ";
		cout<<"\n\t1 for MATRIX operation";
		cout<<"\n\t0 for Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;

		switch (choice)
		{
			case 1 : MATRIX m1, m2, m3, m4;

				 cin>>m1;	// READING MATRIX M1
				 cin>>m2;	// READING MATRIX M2

				 if(m1 == m2)	// MATRIXES ARE OF SAME ORDER
				 {
					m3 = m1 + m2;
					m4 = m1 - m2;
					cout<<"\nFirst matrix is.."<<m1;
					cout<<"\nSecond matrix is.."<<m2;
					cout<<"\nm1 + m2 matrix is.."<<m3;
					cout<<"\nm1 - m2 matrix is.."<<m4;
				 }

				 else
					cout<<"\nERROR : MATRIX are of different orders"
					    <<"\nMATRIX operation FAILED";
				 break;
			case 0 : return 0; // TERMINATING THE PROGRAM
			default: cout<<"\nERROR INVALID INPUT\n";
		}
	}
} // END OF MAIN FUNCTION
//			END OF PROGRAM					 //
///////////////////////////////////////////////////////////////////////////