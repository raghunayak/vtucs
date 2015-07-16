/*************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C+++ program to create a class called QUEUE with member
	functions to add an element and to delete an element from the QUEUE.
	Using these member functions, implement a queue of integers and double.
	Demonstrate the operations by displaying the content of the queue
	after every operation.

\*************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>

// C O N S T A N T S
#define MAX 10
///////////////////////////////////////////////////////////////////////////

template <class T>
class QUEUE
// CLASS OF QUEUE FOR INTEGER AND DOUBLE
{
	      T info[MAX];
	      int front, rear;

   public:    QUEUE(); // CONSTRUCTOR
	      friend void operator + (QUEUE <int> &, int);
	      friend void operator + (QUEUE <double> &, double);
	      friend void operator -- (QUEUE <int> &);
	      friend void operator -- (QUEUE <double> &);
	      friend ostream & operator << (ostream &, QUEUE <int>);
	      friend ostream & operator << (ostream &, QUEUE <double>);
}; // END OF QUEUE CLASS

///////////////////////////////////////////////////////////////////////////

template <class T>
QUEUE <T> :: QUEUE()
// CONSTRUCTOR DEFINATION
{
	front = 0;
	rear = -1;
} // END OF THE CONSTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

void operator + (QUEUE <int> & ob, int item)
// OPERATOR OVERLOADING FOR INSERTING THE ITEM FOR INTEGER QUEUE
{
	if(ob.rear == MAX-1) // OVERFLOW
	{
		cout<<"\nERROR\nQUEUE OVER-FLOW CONDITION\n";
		return;
	}

	ob.rear++;
	ob.info[ob.rear] = item;  // INSERTING THE ITEM

	cout<<"\nThe item "<<item<<" is succesfully inserted into the QUEUE\n";
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

void operator + (QUEUE <double> & ob, double item)
// OPERATOR OVERLOADING FOR INSERTING THE ITEM FOR DOUBLE QUEUE
{
	if(ob.rear == MAX-1) // OVERFLOW
	{
		cout<<"\nERROR\nQUEUE OVER-FLOW CONDITION\n";
		return;
	}

	ob.rear++;
	ob.info[ob.rear] = item;  // INSERTING THE ITEM

	cout<<"\nThe item "<<item<<" is succesfully inserted into the QUEUE\n";
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

void operator -- (QUEUE <int> & ob)
// OPERATOR OVERLOADING FOR DELETING FOR INTEGER QUEUE
{
	if(ob.rear < ob.front) // QUEUE UNDERFLOW
	{
		cout<<"\nERROR\nQUEUE UNDER-FLOW CONDITION\n";
		return;
	}

	cout<<"\nThe item "<<ob.info[ob.front]<<" is succesfully "
	    <<"Deleted from the QUEUE\n";

	ob.front++;
	return;
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

void operator -- (QUEUE <double> & ob)
// OPERATOR OVERLOADING FOR DELETING FOR DOUBLE QUEUE
{
	if(ob.rear < ob.front) // QUEUE UNDERFLOW
	{
		cout<<"\nERROR\nQUEUE UNDER-FLOW CONDITION\n";
		return;
	}

	cout<<"\nThe item "<<ob.info[ob.front]<<" is succesfully "
	    <<"Deleted from the QUEUE\n";

	ob.front++;
	return;
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os, QUEUE <int> ob)
// OPERATOR OVERLOADING TO DISPLAY THE INTEGER QUEUE
{
	if(ob.rear < ob.front)
	{
		os<<"\nThe QUEUE IS EMPTY";
		return os;
	}

	os<<"\nThe contents of the QUEUE are as follows : \n\n";

	os<<"\nFRONT ->   ";
	for(int i = ob.front ; i <= ob.rear ; i++)
		  os<<ob.info[i]<<"   ";
	os<<"<- REAR\n";
	return os;
} // END OF THE FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os, QUEUE <double> ob)
// OPERATOR OVERLOADING TO DISPLAY THE DOUBLE QUEUE
{
	if(ob.rear < ob.front)
	{
		os<<"\nThe QUEUE IS EMPTY";
		return os;
	}

	os<<"\nThe contents of the QUEUE are as follows : \n\n";
	os<<"\nFRONT ->   ";
	for(int i = ob.front ; i <= ob.rear ; i++)
		  os<<ob.info[i]<<"   ";
	os<<"<- REAR\n";

	return os;
} // END OF THE FUNCTION DEFINATION
///////////////////////////////////////////////////////////////////////////

int main(void)
// MAIN FUNCTION
{
	double item, queue_no;
	QUEUE<int> iq;		// INTEGER QUEUE
	QUEUE<double> dq;	// DOUBLE QUEUE
	clrscr();

	while(1)
	{
		int choice;
		// PRINTING THE MENU
		cout<<"\n\n\t\t\t     **** MENU ****"
		    <<"\nPlease Enter your Choice : "
		    <<"\n\t1 for Integer"
		    <<"\n\t2 for Double"
		    <<"\n\t0 for EXIT"
		    <<"\nPlease Enter your choice : ";

		cin>>choice;

		switch(choice)
		{
			case 1 : // INTEGER QUEUE
				queue_no = 1;
				break;
			case 0 : return 0;	// terminating the program

			default: // DOUBLE QUEUE
				queue_no = 2;
		}

		int go = 1;
		while(go)
		{
			cout<<"\n\n\t\t\t     **** MENU ****"
				<<"\nPlease Enter your Choice : "
				<<"\n\t1 for INSERTION operation"
				<<"\n\t2 for DELETE operation"
				<<"\n\t3 for DISPLAY"
				<<"\n\t0 for Exit"
				<<"\n************************************************************"
				<<"\nEnter your choice : ";
			cin>>choice;

			switch (choice)
			{
			case 1 : // INSERTING THE ELEMENT
				cout<<"\n\nPlease Enter the item to be inserted : ";
				cin>>item;
				if(queue_no == 1)
				{
					// INSERTING THE ITEM
					iq + (int) item;
					cout<<iq;	// DISPALY
				}
				else
				{
					dq + item; // INSERTING THE ITEM
					cout<<dq;
				}
				break;
			case 2 : // DELETING THE ELEMENT
				if(queue_no == 1)
				{
					iq--;	// DELETING THE ITEM
					cout<<iq;	// DISPLAY
				}
				else
				{
					dq--;	// DELETING THE ITEM
					cout<<dq;
				}
				break;
			case 3 : // DISPLAY OF THE QUEUE
				if(queue_no == 1)
				{
					cout<<iq;
					break;
				}
				cout<<dq;	// DISPLAY
				break;
			case 0 : go = 0;
				break;
			default: cout<<"\n\nERROR INVALID INPUT\n";
			} // END OF THE SWITCH
		} // END OF THE WHILE LOOP
	} // END OF THE WHILE LOOP
}
//			       END OF PROGRAM                            //
///////////////////////////////////////////////////////////////////////////