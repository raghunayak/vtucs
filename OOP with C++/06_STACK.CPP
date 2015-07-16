/*************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++ Program to create a class called STACK using an array
	of integers. Implement the following operations by overloading the
	operator + and -.
		i. s1 = s1 + element;
		where s1 is an object of the class STACK and element is an
		integer to be pushed on the top of the stack.

		ii. s1 = s1 - ;
		where s1 is an object of the class STACK. - operator pops
		the element.
		Handle the STACK empty and STACK full conditions. Also
		display the contents of the stack after each operation, by
		overloading the operator <<.

\*************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>

// C O N S T A N T S
#define MAX 2 // MAXIMUM NUMBER OF ELEMENTS IN THE STACK

///////////////////////////////////////////////////////////////////////////

class STACK
// CLASS OF STACK
{
	int info[MAX];	// INTEGER ARRAY
	int top;	// STORES THE VALUE OF THE TOP

	public :
		STACK(); // CONSTRUCTOR
		friend STACK operator + (STACK, int);	// FUNCTION TO PUSH
		friend STACK operator --(STACK);	// FUNCTION TO POP
		friend ostream & operator << (ostream &, STACK); // TO DISPLAY
};
// END OF THE CLASS DEFINATION OF STACK CLASS
///////////////////////////////////////////////////////////////////////////

STACK :: STACK()
// CONSTRUCTOR DEFINATION
{
	top = -1; // AT THE START TOP VALUE IS -1
} // END OF THE CONSTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

STACK operator + (STACK ob, int item)
// OPERATOR OVERLOADING FOR PUSHING THE ITEM
{
	if(ob.top == MAX-1) // OVERFLOW
	{
		cout<<"\nERROR\nSTACK OVER-FLOW CONDITION\n";
		return ob;
	}

	ob.top++;
	ob.info[ob.top] = item;  // INSERTING THE ITEM

	cout<<"\nThe item "<<item<<" is succesfully pushed into the STACK\n";

	return ob;
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

STACK operator -- (STACK ob)
// OPERATOR OVERLOADING FOR POPING
{
	if(ob.top == -1) // STACK UNDERFLOW
	{
		cout<<"\nERROR\nSTACK UNDER-FLOW CONDITION\n";
		return ob;
	}

	cout<<"\nThe item "<<ob.info[ob.top]<<" is succesfully "
	    <<"removed the STACK\n";

	ob.top--;	// OPERATOR OVERLOADING

	return ob;
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os, STACK ob)
// OPERATOR OVERLOADING FOR DISPLAY OF THE STACK
{
	if(ob.top == -1) // STACK IS EMPTY
	{
		os<<"\nThe STACK IS EMPTY";
		return os;
	}

	os<<"\nThe contents of the STACK are as follows : \n\n";

	cout<<"\n TOP\n";
	for(int i = ob.top ; i >= 0 ; i--) // PRINTING THE STACK
		os<<"-----"<<endl<<"| "
		  <<ob.info[i]<<" |"<<endl<<"-----"<<endl;

	return os;
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

int main(void)
// MAIN FUNCTION
{
	STACK s1; // OBJECT OF CLASS STACK
	int item;

	clrscr();

	while(1)
	{
		int choice;
		// PRINTING THE MENU
		cout<<"\n\n\t\t\t     **** MENU ****"
		    <<"\nPlease Enter your Choice : "
		    <<"\n\t1 for PUSH operation"
		    <<"\n\t2 for POP operation"
		    <<"\n\t3 for DISPLAY"
		    <<"\n\t0 for Exit"
		    <<"\n************************************************************"
		    <<"\nEnter your choice : ";
		cin>>choice;

		switch (choice)
		{
			case 1 :// PUSHING THE ELEMENT
				cout<<endl
				    <<endl
				    <<"Please Enter the item to be inserted : ";
				cin>>item;
				s1 = s1 + item;	// PUSHING THE ITEM
				cout<<s1;	// DISPALY
				break;
			case 2 :// POPING THE ELEMENT
				s1 = s1--;	// POPING THE ITEM
				cout<<s1;	// DISPLAY
				break;
			case 3 :// DISPLAY OF THE STACK
				cout<<s1;	// DISPLAY
				break;
			case 0 : return 0; // terminating the program
			default: cout<<"\n\nERROR INVALID INPUT\n";
		} // END OF THE SWITCH
	} // END OF THE WHILE LOOP
}
//			       END OF PROGRAM                            //
///////////////////////////////////////////////////////////////////////////