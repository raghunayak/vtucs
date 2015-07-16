/**************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++to create a class  called OCTAL which has the
	characteristics of an octal number. Implement the following operations
	by writing an appropriate constructor and an overloaded operator +.

	i.  OCTAL h = x; where x is an integer.
	ii. int y = h+k; where h is an OCTAL object and k is an integer.

\**************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>
#include <math.h>

///////////////////////////////////////////////////////////////////////////

class OCTAL
// CLASS OF THE OCTAL NUMBER
{
	int number;

	public :
		OCTAL(int); // CONSTRUCTOR
		OCTAL() {}	  // EMPTY CONSTRUCTOR
		// OPERATOR OVERLOADING TO DECIMAL NO AND OCTAL NO
		friend int operator + (OCTAL, int);
		// OPERATOR OVERLOADING TO READ THE OCTAL NUMBER
		friend istream & operator >> (istream &, OCTAL &);
		// OPERATOR OVERLOADING TO PRINT THE OCTAL NUMBER
		friend ostream & operator << (ostream &, OCTAL);
}; // END OF THE CONSTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

OCTAL:: OCTAL(int n)
// CONSTRUCTOR DEFINATION
{
	int i = 0 , s = 0;

	while(n > 0) // CONVERTING TO OCTAL NUMBER
	{
		if((n % 10) == 9) // WRONG INPUT
		{
			cout<<"\nERROR\nWrong input\n";
			return;
		}
		s = ( n % 8) * pow (10,i++) + s;
		n = n / 8;
	}
	number = s;
} // END OF THE CONSTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

int operator + (OCTAL ob, int n)
// FRIEND FUNCTION TO ADD OCTAL NUMBER WITH A INTEGER NUMBER
{
	int i = 0 , s = 0;

	while(ob.number > 0) // OCTAL TO DECIMAL
	{
		if((ob.number % 10) == 9) // WRONG INPUT
		{
			cout<<"\nERROR\nWrong input\n";
			return -1;
		}
		s = ( ob.number % 10) * pow (8,i++) + s;
		ob.number = ob.number / 10;
	}

	s = s + n;
	return s;
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

istream & operator >> (istream & is, OCTAL & ob)
// FRIEND FUNCTION TO READ THE OCTAL NUMBER
{
	cout<<"\nPlease Enter the OCTAL Number : ";
	is>>ob.number;

	return is;
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os, OCTAL ob)
// FRIEND FUNCTION TO DISPLAY THE OCTAL NUMBER
{
	os<<"\nThe OCTAL number is : "<<ob.number;

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
		cout<<"\n\t1 to Convert integer to OCTAL number using constructor";
		cout<<"\n\t2 to ADD integer to OCTAL number using function";
		cout<<"\n\t0 for Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;

		switch (choice)
		{
			case 1 : int x = 0;

				 cout<<"\nENter the integer number : ";
				 cin>>x;
				 cout<<"\nInteger x = "<<x;

				 OCTAL h = x; // CREATING THE OBJECT
				 cout<<h;
				 break;
			case 2 :
				 int k;
				 OCTAL h1;
				 cout<<"\nPlease Enter an integer : ";
				 cin>>k;
				 cin>>h1;
				 cout<<"\nInteger k = "<<k<<endl;

				 int y = h1 + k;

				 cout<<"\nSum of decimal "<<k<<" and "<<h1
				     <<" is decimal "<<y;
				 break;
			case 0 : return 0; // TERMINATING THE PROGRAM
			default: cout<<"\nERROR INVALID INPUT\n";
		} // END OF THE SWITCH CONDITION
	} // END OF THE WHILE
} // END OF MAIN FUNCTION
//			END OF PROGRAM					 //
///////////////////////////////////////////////////////////////////////////