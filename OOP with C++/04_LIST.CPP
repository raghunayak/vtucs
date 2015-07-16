/*************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++ program to create a class called list(linked list)
	with member functions to insert an element at the front as well as
	to delete an element from the front of the list.
	Demonstrate all the functions after creating a list object.

\*************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>

///////////////////////////////////////////////////////////////////////////

class LIST // CLASS OF LINKED LIST
{
	public :
		class NODE // CLASS OF NODE
		{
		   public :
				int info;
				NODE * next; // POINTER TO NODE
		}* front;                    // HEADER NODE LINK

		// MEMBER FUNCTIONS
		void insert(int); // FUNCTION TO INSERT NEW NODES
		int del();        // FUNCTION TO DELETE THE NODES
		void display();   // FUNCTION TO DISPLAY LINKED LIST
}; // END OF THE CLASS LIST

///////////////////////////////////////////////////////////////////////////

void LIST :: insert(int num)
// MEMBER FUNCTION TO INSERT ITEM AT THE FRONT
{
	NODE * ptr;

	ptr = new NODE ; // CREATING NEW NODE
	ptr->info = num; // INSERTING THE INFO

	if(front == NULL) // NO NODES PRESENT IN THE LIST
	{
		ptr->next = NULL;
		front = ptr;      // MAKING THE PTR AS THE FIRST ELEMENT
		cout<<"\nThe item "<<num<<" is succesfully inserted at "
		    <<"the front of the list";
		return;
	}

	ptr->next = front;
	front = ptr;

	cout<<"\nThe item "<<num<<" is succesfully inserted at the "
	    <<"front of the list";
	return;
}
// END OF MEMBER FUNCTION INSERT
///////////////////////////////////////////////////////////////////////////

int LIST :: del()
// MEMBER FUNCTION TO DELETE THE ITEM FROM FRONT OF THE LIST
{

	int temp;
	 NODE * ptr;

	if(front == NULL) // LIST IS EMPTY
	{
		cout<<"\n\nERROR\nLINKED LIST UNDERFLOW\n";
		return -1;
	}
	ptr = front;

	temp = ptr->info;
	front = ptr->next;
	delete ptr;        // DELETING THE NODE
	return temp;       // RETURNING THE DELETED NODE INFORMATION
}
// END OF MEMBER FUNCTION INSERT

///////////////////////////////////////////////////////////////////////////

void LIST :: display()
// MEMBER FUNCTION TO DISPLAY THE LINKED LIST
{

	NODE * ptr = front;

	if(ptr == NULL) // THE LIST IS EMPTY  NO ITEM TO DISPLAY
	{
		cout<<"\n\nLIST is EMPTY\n";
		return;
	}

	cout<<"\nThe list is as follows :    ";
	while(ptr != NULL) // PRINTING THE LIST ITEMS
	{
		cout<<ptr->info<<" -> ";
		ptr = ptr->next;
	}
	cout<<"NULL";

	return;
}
// END OF MEMBER FUNCTION DISPLAY
///////////////////////////////////////////////////////////////////////////

int main(void)
// MAIN FUNCTION
{
	clrscr();

	LIST ob; // OBJECT OF CLASS LIST
	ob.front = NULL; // MAKING THE HEADER NODE LINK TO NULL

	while(1)
	{
		// PRINTING THE MENU
		int choice,number;
		cout<<"\n\n\t\t\t     **** MENU ****\n";
		cout<<"Please Enter your Choice : \n";
		cout<<"\t1 for Insertion\n";
		cout<<"\t2 for Delete\n";
		cout<<"\t3 for Display\n";
		cout<<"\t0 for Exit\n";
		cout<<"Enter your choice : ";
		cin>>choice;

		switch (choice)
		{
			case 1 : cout<<"\n\nEnter the number to be inserted : ";
				 cin>>number;
				 // CALLING MEMBER FUNCTION INSERT()
				 ob.insert(number);
				 break;
			case 2 : cout<<"\nDeleting the item\n";
				 int temp = ob.del(); // DELETING THE NODE

				 if(temp != -1)
					cout<<"\nThe no "<<temp<<" removed from the LIST\n";
				 break;
			case 3 : ob.display(); // TO DISPLAY LIST
				 break;
			case 0 : return 0; // TERMINATING THE PROGRAM
			default: cout<<"\nERROR INVALID INPUT\n";
		} // END OF THE SWITCH CASE
	} // END OF THE WHILE LOOP
} // END OF MAIN FUNCTION
//			END OF PROGRAM					 //
///////////////////////////////////////////////////////////////////////////