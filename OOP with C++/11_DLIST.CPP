/*************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++ Program to create a class called DLIST (Doubly Linked
	List) with member functions to insert a node at a specified position
	and delete a node from a specified position of the list.

	Demonstrate the operations by displaying the contents of the list
	after every operation.

\*************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>

// G L O B A L    V A R I A B L E S
int error; // THIS IS USED WHEN ERROR OCCURED WHILE DELETING ITEM FROM LIST

///////////////////////////////////////////////////////////////////////////

typedef struct NODE // STRUCTURE OF NODE
{
	int info;			// STORES THE INFORMATION
	NODE *prev, * next; // POINTER TO PREVIOUS NODE & NEXT NODE
} * NODEPTR;

///////////////////////////////////////////////////////////////////////////

class DLIST // CLASS OF DOUBLY LINKED LIST
{
	NODEPTR link; // HEADER NODE

	public :
		DLIST() // CONSTRUCTOR
		{
			link = new NODE;		// CREATE THE HEADER NODE

			link->info = 0;	// HEADER NODE'S INFO CONTAINS NUMBER OF
							// NODES PRESENT IN DOUBLE LINKED LIST

			// MAKING THE HEADER NODE TO POINT TO NULL
			link->next = NULL; // NO NODES PRESENT AT THE STARTING
			link->prev = link; // SELF POINTER
		}

		// MEMBER FUNCTIONS
		int insert(int, int); // FUNCTION TO INSERT NEW NODES
		int del(int);        // FUNCTION TO DELETE THE NODES
		void display();   // FUNCTION TO DISPLAY LINKED LIST
}; // END OF THE CLASS LIST

///////////////////////////////////////////////////////////////////////////

int DLIST :: insert(int item, int pos)
// MEMBER FUNCTION TO INSERT ITEM AT THE POSITION POS
{
	NODEPTR ptr = link, temp = NULL, new_node; // POINTERS
	int count = 0;

	new_node = new NODE ; // CREATING NEW NODE
	new_node->info = item; // INSERTING THE INFORMATION

	if(pos < 1) // INVALID POSITION ENTERED
		return 0;	// INSERTION FAILED BECAUSE OF INVALID POSITION

	while(count != pos && ptr != NULL)
	{
		temp = ptr;
		count++;
		ptr = ptr->next;
	}

	if(count == pos) // POSITION EXISTS
	{
		if(ptr != NULL) // ITEM IS TO BE INSERTED BETWEEN 2 NODES
		{
			(ptr->prev)->next = new_node;
			new_node->prev = ptr->prev;
			new_node->next = ptr;
			ptr->prev = new_node;
		}
		else // ptr == NULL, ITEM IS TO BE INSERTED BETWWEN 1 NODE & NULL
		{
			new_node->next = temp->next;
			temp->next = new_node;
			new_node->prev = temp;
		}
		link->info++; // TOTAL NUMBER OF NODES
		return 1; // ITEM IS SUCCESFULLY INSERTED

	}
	return 0; // INSERTION FAILED BECAUSE OF INVALID POSITION
}
// END OF MEMBER FUNCTION INSERT
///////////////////////////////////////////////////////////////////////////

int DLIST :: del(int pos)
// MEMBER FUNCTION TO DELETE THE ITEM FROM FRONT OF THE LIST
{
	NODEPTR ptr = link, temp = NULL, new_node; // POINTERS
	int count = 0, item;

	if(pos < 1) // INVALID POSITION ENTERED
	{
		cout<<"\n\nERROR\nInvalid Position Entered\n";
		error = 1;	// ERROR OCCURED
		return -1;
	}

	while(count != pos && ptr->next != NULL)
	{
		temp = ptr;
		count++;
		ptr = ptr->next;
	}

	if(count == pos) // POSITION IS VALID
	{
		if(ptr->next != NULL)
		{
			(ptr->prev)->next = ptr->next;
			(ptr->next)->prev = ptr->prev;
		}
		else // ptr->next == NULL
		{
			temp->next = NULL;
		}
		link->info--;
		item = ptr->info;
		delete ptr;		// DE ALLOCATING THE MEMORY
		error = 0;		// ITEM IS SUCCESFULLY DELETED
		return item;
	}
	cout<<"\n\nERROR\nInvalid Position Entered\n";
	error = 1; // ERROR OCCURED
	return -1; // INSERTION FAILED BECAUSE OF INVALID POSITION
}
// END OF MEMBER FUNCTION DEL

///////////////////////////////////////////////////////////////////////////

void DLIST :: display()
// MEMBER FUNCTION TO DISPLAY THE LINKED LIST
{

	NODE * ptr = link->next; // LINK POINTS TO HEADER NODE

	if(ptr == NULL) // THE LIST IS EMPTY  NO ITEM TO DISPLAY
	{
		cout<<"\n\nLIST is EMPTY\n";
		return;
	}

	cout<<"\nThe list is as follows :    ";
	cout<<"\n\n\nNULL";
	while(ptr != NULL) // PRINTING THE LIST ITEMS
	{
		cout<<" <- "<<ptr->info<<" -> ";
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

	DLIST ob; // OBJECT OF CLASS DLIST
	int pos, num, go, choice;

	while(1)
	{
		// PRINTING THE MENU
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
				 cin>>num;
				 cout<<"\n\nEnter the Position : ";
				 cin>>pos;
				 // CALLING MEMBER FUNCTION INSERT()
				 go = ob.insert(num,pos);

				 if(go)
					cout<<"\nThe item "<<num<<" is succesfully "
					    <<"inserted at the Position "<<pos
					    <<" of the list";
				 else
					cout<<"\n\nERROR\nInvalid Position Entered\n";
				 break;
			case 2 : cout<<"\nDeleting the item\n";
				 cout<<"\n\nPlease Enter the Position : ";
				 cin>>pos;
				 go = ob.del(pos); // DELETING THE NODE

				 if(!error) // NO ERRORS
					cout<<"\nThe no "<<go
					    <<" removed from the LIST from "
					    <<" position "<<pos;
				 break;
			case 3 : ob.display(); // TO DISPLAY LIST
				 break;
			case 0 : return 0; // TERMINATING THE PROGRAM
			default: cout<<"\nERROR INVALID INPUT\n";
		}
	}
} // END OF MAIN FUNCTION
//			END OF PROGRAM					 //
///////////////////////////////////////////////////////////////////////////