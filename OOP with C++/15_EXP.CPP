/*************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++ Program to create a class called EXPRESSION.
	Using appropriate member functions to convert a given valid Infix
	expression into Postfix form. Display the Infix and Postfix
	expressions.

\*************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

// C O N S T A N T S
#define MAX 50
#define MAX_STACK 50

///////////////////////////////////////////////////////////////////////////

class STACK // CLASS OF THE STACK
{
	char info[MAX_STACK];
	int top;

	public :
		STACK()
		{
			top = -1;
		}

		void push(char item)
		{
			info[++top] = item;
		}

		char pop()
		{
			return info[top--];
		}
		friend class EXPRESSION;
}; // END OF THE CLASS DEFINATION OF STACK

///////////////////////////////////////////////////////////////////////////

class EXPRESSION // CLASS OF EXPRESSIONS
{
	char infix[MAX];
	char postfix[MAX];
	STACK st;

	public :
		EXPRESSION(char *); // CONSTRUCTOR
		EXPRESSION() {}       // EMPTY CONSTRUCTOR

		// MEMBER FUNCTIONS
		void convert(); // FUNCTION TO CONVERT THE INFIX EXP TO POSTFIX
		void display();   // FUNCTION TO DISPLAY THE EXPRESSION
}; // END OF THE CLASS EXPRESSION

///////////////////////////////////////////////////////////////////////////

EXPRESSION :: EXPRESSION(char * str)
// CONSTRUCTOR DEFINATION
{
	strcpy(infix,str);
} // END OF THE CONSTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

void EXPRESSION :: convert()
// MEMBER FUNCTION TO CONVERT A INFIX EXPRESSION INTO A POSTFIX EXPRESSION
{
	int i = 0, p = 0;
	char ch;
	int priority(char); // FUNCTION PROTOTYPE

	while(infix[i] != '\0')
	{
		switch(infix[i])
		{
			case '(' :
				st.push(infix[i++]);
				break;
			case ')' :
				ch = st.pop();

				while(ch != '(')
				{
					postfix[p++] = ch;
					ch = st.pop();
				}
				i++;
				break;
			case '^' :
			case '/' :
			case '*' :
			case '-' :
			case '+' :
				if(st.top == -1)
				{
					st.push(infix[i++]);
					break;
				}

				ch = st.pop();
				while(priority(ch) >= priority(infix[i]))
				{
					postfix[p++] = ch;
					ch = st.pop();
				}

				st.push(ch);
				st.push(infix[i++]);
				break;
			default :
				postfix[p++] = infix[i++];
		} //  END OF THE SWITCH CONDITION
	}

	while(st.top != -1)
	{
		postfix[p++] = st.pop();
	}
	postfix[p] = '\0';
} // END OF MEMBER FUNCTION CONVERT

///////////////////////////////////////////////////////////////////////////

int priority(char ch)
// THIS FUNCTION RETURNS THE PRIORITY OF THE CHARACTER
{
	switch(ch)
	{
	case '^' : return 3;
	case '/' :
	case '*' : return 2;
	case '-' :
	case '+' : return 1;
	default  : return 0;
	}
}

///////////////////////////////////////////////////////////////////////////

void EXPRESSION :: display()
// MEMBER FUNCTION TO DISPLAY THE EXPRESSIONS
{
	cout<<"\n\nThe INFIX Expression is :\n";
	cout<<"\""<<infix<<"\"";
	cout<<"\nThe POSTFIX Expression is :\n";
	cout<<"\""<<postfix<<"\"";
}
// END OF MEMBER FUNCTION DISPLAY
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
		cout<<"\n\t1 for Converting a valid INFIX Exp. to POSTFIX Exp.";
		cout<<"\n\t0 for Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;

		switch (choice)
		{
			case 1 :
				 cout<<"\nEnter a valid Infix Expression\n";
				 char infix[MAX];
				 cin>>infix;

				 EXPRESSION ob(infix); // OBJECT OF CLASS EXPRESSION

				 ob.convert();
				 ob.display();

				 break;
			case 0 : return 0; // TERMINATING THE PROGRAM
			default: cout<<"\nERROR INVALID INPUT\n";
		}
	}
} // END OF MAIN FUNCTION
//			END OF PROGRAM					 //
///////////////////////////////////////////////////////////////////////////