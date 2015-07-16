/*************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++ program to create a class called BIN_TREE
	(Binary tree) with member functions to perform inorder, preorder
	and postorder traversals. Create a BIN_TREE object and demonstrate
	the traversals.

\*************************************************************************/

// I N C L U D E S

#include <iostream.h>
#include <conio.h>

// C O N S T A N T S
typedef class node * nodeptr;

///////////////////////////////////////////////////////////////////////////

class node  // CLASS OF NODE
{
	public :
		int info;
		nodeptr left,right;
};

///////////////////////////////////////////////////////////////////////////

class BIN_TREE // CLASS OF BINARY TREE
{
		nodeptr head_link; // HEADER NODE

	public :
		BIN_TREE();       // CONSTRUCTOR
		void build();     // FUNCTION TO CONSTRUCT THE BINARY TREE
		void inorder(nodeptr);   // FUNCTION FOR INORDER TRAVERSAL
		void preorder(nodeptr);  // FUNCTION FOR PREORDER TRAVERSAL
		void postorder(nodeptr); // FUNCTION FOR POSTORDER TRAVERSAL
		void display(nodeptr);   // FUNCTION TO DISPLAY THE BINARY TREE
		void traversal(int);
};

///////////////////////////////////////////////////////////////////////////

BIN_TREE :: BIN_TREE()
// DEFINATION OF THE CONSTRUCTOR
{
	head_link = NULL; // NO NODES AT THE STARTING
}
// END OF CONSTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

void BIN_TREE :: build()
// THIS FUNCTION CONSTRUCTS THE BINARY TREE
{
	int item;
	nodeptr ptr, q = head_link, r = NULL;
	cout<<"\nPlease Enter the item to be inserted : ";
	cin>>item;

	ptr = new node; // CREATING THE NODE

	ptr->info = item; // INSERTING THE ITEM
	ptr->left = ptr->right = NULL; // NO NODES IN LEFT AND RIGHT SIDE

	if(head_link == NULL) // TREE IS EMPTY
	{
		head_link = ptr; // NOW PTR IS THE ROOT
		cout<<"\nThe Node with Info "
		    <<item
		    <<" is made as the Root of the Binary Tree";
		return;
	}

	while( q != NULL && q->info != item)
	{
		r = q;

		if(item > q->info)
			q = q->right;
		else
			q = q->left;
	} // END OF THE WHILE LOOP

	if(q->info == item) // ITEM ALLREADY EXISTS
	{
		cout<<"\nThe item "<<item
		    <<" Allready exists in the Binary Tree ";
		return;
	}

	if(item > r->info)
		r->right = ptr;
	else
		r->left = ptr;

	cout<<"\nThe item "<<item<<" is Succesfully inserted into "
	    <<"the Binary Tree\n";
	return;
}

///////////////////////////////////////////////////////////////////////////

void BIN_TREE :: display(nodeptr link)
// THIS FUNCTION PRINTS THE BINARY TREE IN INORDER
{
	if(link != NULL)
	{
		display(link->left);
		cout<<"  "<<link->info;
		display(link->right);
	}
}
// END OF THE FUNCTION DISPLAY

///////////////////////////////////////////////////////////////////////////

void BIN_TREE :: traversal(int code)
// THIS FUNCTION CALLS THE TRAVERSAL FUNCTION
{
	switch(code)
	{
	case 1 :// PREORDER
		if(head_link == NULL)
		{
			cout<<"\nBinary Tree is EMPTY";
			break;
		}
		cout<<"\nThe Preorder Traversal of the Binary Tree "
		    <<"is as follows \n";
		preorder(head_link);
		break;
	case 2 :// INORDER
		if(head_link == NULL)
		{
			cout<<"\nBinary Tree is EMPTY";
			break;
		}
		cout<<"\nThe Inorder Traversal of the Binary Tree "
		    <<"is as follows \n";
		inorder(head_link);
		break;
	case 3 :// POSTORDER
		if(head_link == NULL)
		{
			cout<<"\nBinary Tree is EMPTY";
			break;
		}
		cout<<"\nThe Postorder Traversal of the Binary Tree "
		    <<"is as follows \n";
		postorder(head_link);
		break;
	default:// DISPLAY
		if(head_link == NULL)
		{
			cout<<"\nBinary Tree is EMPTY";
			break;
		}
		cout<<"\n\nThe Binary Tree is as follows : ";
		display(head_link);
	}
}
// END OF THE FUNCTION TRAVERSAL

///////////////////////////////////////////////////////////////////////////

void BIN_TREE :: inorder(nodeptr link)
// THIS FUNCTION TRAVERSES THE BINARY TREE IN INORDER
{
	if(link != NULL)
	{
		inorder(link->left);
		cout<<"  "<<link->info;
		inorder(link->right);
	}
}
// END OF THE FUNCTION INORDER

///////////////////////////////////////////////////////////////////////////

void BIN_TREE :: postorder(nodeptr link)
// THIS FUNCTION TRAVERSES THE BINARY TREE IN POSTORDER
{
	if(link != NULL)
	{
		postorder(link->left);
		postorder(link->right);
		cout<<"  "<<link->info;
	}
}
// END OF THE FUNCTION POSTORDER

///////////////////////////////////////////////////////////////////////////

void BIN_TREE :: preorder(nodeptr link)
// THIS FUNCTION TRAVERSES THE BINARY TREE IN PREORDER
{
	if(link != NULL)
	{
		cout<<"  "<<link->info;
		preorder(link->left);
		preorder(link->right);
	}
}
// END OF THE FUNCTION PREORDER

///////////////////////////////////////////////////////////////////////////

int main(void)
// MAIN FUNCTION
{
	int choice;
	BIN_TREE tree; // OBJECT OF THE CLASS BIN_TREE

	clrscr();
	while(1)
	{       // PRINTING THE MENU
		cout<<"\n\n\t\t\t     **** MENU ****"
		    <<"\nPlease Enter your Choice"
		    <<"\n\t1 for Insertion of a element to Binary Tree"
		    <<"\n\t2 for Preorder Traversal"
		    <<"\n\t3 for Inorder Traversal"
		    <<"\n\t4 for Postorder Traversal"
		    <<"\n\t5 for Display"
		    <<"\n\t0 for EXIT"
		    <<"\nPlease Enter the your choice : ";
		cin>>choice;

		switch(choice)
		{
		case 1 :// CONSTRUCTING THE TREE
			tree.build();
			break;
		case 2 :// PREORDER TRAVERSAL OF THE BINARY TREE
			tree.traversal(1);
			break;
		case 3 :// INORDER TRAVERSAL OF THE BINARY TREE
			tree.traversal(2);
			break;
		case 4 :// POSTORDER TRAVERSAL OF THE BINARY TREE
			tree.traversal(3);
			break;
		case 5 :// CALLING THE DISPLAY FUNCTION TO DISPLAY BIN_TREE
			tree.traversal(4);
			break;
		case 0 :// TERMINATING THE PROGRAM
			return 0;
		default:// ERROR
			cout<<"\nERROR\nInvalid Input Given";
		} // END OF SWITCH CASE
	} // END OF THE WHILE LOOP
} // END OF THE MAIN FUNCTION
//			      END OF THE PROGRAM			 //
///////////////////////////////////////////////////////////////////////////