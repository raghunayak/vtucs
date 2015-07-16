/*************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++ program to create a class called STRING and implement
	the following operations.
	Display the results after every operation by overloading the
	operator <<.
	i.	STRING s1 = "VTU"
	ii.	STRING s2 = "BELGAUM"
	iii.	STRING s3 = s1 + s2 ; (Use copy constructor)

\*************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>
#include <string.h>

// C O N S T A N T S
#define MAX 20 // MAXIMUM NUMBER OF CHARACTERS

///////////////////////////////////////////////////////////////////////////

class string
// CLASS OF THE STRING
{
	char str[MAX];

	public :
		string() {} // EMPTY CONSTRUCTOR
		string(const char *); // PARAMETERIZED CONSTRUCTOR
		string operator + (string ob); // OPERATOR OVERLOADING
		// OPERATOR OVERLOADING TO DISPLAY THE STRING
		friend ostream & operator << (ostream &, string);
}; // END OF THE CLASS STRING

///////////////////////////////////////////////////////////////////////////

string :: string(const char *str1)
// PARAMETERIZED CONSTRUCTOR DEFINATION
{
	strcpy(str,str1);
} // END OF THE CONSTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

string string :: operator + (string ob)
// OPERATOR OVERLOADING TO ADD 2 STRINGS
{
	string temp;

	strcpy(temp.str,str);
	strcat(temp.str,ob.str);

	return temp;
} // END OF THE OPERATOR OVERLOADING OF '+'

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os, string ob)
// OPERATOR OVERLOADING TO DISPLAY THE STRING
{
	os<<ob.str; // PRINTING THE STRING

	return os;
} // END OF THE OPERATOR OVERLOADING

///////////////////////////////////////////////////////////////////////////

int main(void)
// MAIN FUNCTION
{
	string s1 = "VTU";       // FIRST OBJECT
	string s2 = "BELGAUM";   // SECOND OBJECT

	clrscr();

	cout<<"\nFirst STRING is \""<<s1<<"\"";
	cout<<"\n\nSecond STRING is \""<<s2<<"\"";

	// THIRD OBJECT
	string s3 = s1 + s2;           // CONCATENATING S1 AND S2

	cout<<"\n\nAfter Concatenation,\n\nThird STRING is \""<<s3<<"\"";
	return 0;

} // END OF FUNCTION MAIN
//			     END OF PROGRAM				 //
///////////////////////////////////////////////////////////////////////////