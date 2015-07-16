/**************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++ program  to create a class called COMPLEX and
	implement the following overloading functions ADD that
	return a COMPLEX number.
	i.  ADD (a,s2) - where a is an integer(real part) and S2
	    is a Complex number.
	ii. ADD (s1,s2) - where s1 and s2 are complex numbers.

\**************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <iomanip.h>

///////////////////////////////////////////////////////////////////////////

class complex
// CLASS OF COMPLEX NUMBERS
{
	float real,imag;  // DATA MEMBERS
	public :
	    // MEMBER FUNCTIONS
	    complex ADD(float);   // FUNCTION TO ADD COMPLEX & REAL NUMBER
	    complex ADD(complex); // FUNCTION TO ADD 2 COMPLEX NUMBERS
	    // OPERATOR OVERLOADING TO READ THE COMPLEX NUMBER
	    friend istream & operator >>( istream & is, complex & ob);
	    // OPERATOR OVERLOADING TO PRINT THE DATA
	    friend ostream & operator <<( ostream & os, complex ob);
}; // END OF THE CLASS COMPLEX

///////////////////////////////////////////////////////////////////////////

istream & operator >>(istream & is, complex & ob)
// FUNCTION TO READ THE COMPLEX NUMBER THROUGH OPERATOR OVERLOADING
{
	cout<<endl<<"Enter the Real part : ";
	is>>ob.real;
	cout<<"Enter the Imaginary part : ";
	is>>ob.imag;
	return is;
} // END OF THE OPERATOR OVERLOADING FUNCTION

///////////////////////////////////////////////////////////////////////////

ostream & operator <<( ostream & os, complex ob)
// FUNCTION TO PRINT THE COMPLEX NUMBER THROUGH OPERATOR OVERLOADING
{
	os<<setw(8)<<ob.real;  // PRINTING THE REAL PART
	if(ob.imag < 0)
	{
		os<<" -i ";
		ob.imag = ob.imag*(-1);
	}
	else
		os<<" +i ";
	os<<ob.imag;           // PRINTING THE IMAGINARY PART
	return os;
} // END OF THE OPERATOR OVERLOADING FUNCTION

///////////////////////////////////////////////////////////////////////////

complex complex :: ADD(float real1)
// FUNCTION TO ADD THE REAL NUMBER TO A COMPLEX NUMBER
{
	real = real1 + real; // ADDING THE REAL PART
	return (*this);
} // END OF THE FUNCTION ADD

///////////////////////////////////////////////////////////////////////////

complex complex :: ADD(complex comp)
// FUNCTION TO ADD 2 COMPLEX NUMBERS
{
	real = real + comp.real; // ADDING THE REAL PART
	imag = imag + comp.imag; // ADDING THE IMAGINARY PART

	return (*this);
} // END OF THE FUNCTION ADD

///////////////////////////////////////////////////////////////////////////

int main(void)
// MAIN FUNCTION
{
	complex n1, n2; // OBJECT OF CLASS COMPLEX
	float f1;
	clrscr();

	while(1)
	{
		int choice;
		// PRINTING THE MENU
		cout<<"\n\n\t\t\t     **** MENU ****"
		    <<"\nPlease Enter your Choice : "
		    <<"\n\t1 to ADD 2 COMPLEX NUMBER"
		    <<"\n\t2 to ADD COMPLEX AND A REAL NUMBER"
		    <<"\n\t0 for Exit"
		    <<"\n************************************************************"
		    <<"\nEnter your choice : ";
		cin>>choice;

		switch (choice)
		{
			case 1 :// ADDING THE 2 COMPLEX NUMBERS
				cout<<endl
				    <<endl
				    <<"Please Enter the Following Data"<<endl
				    <<"Enter The Complex Number 1 : ";
				cin>>n1;
				cout<<"\nEnter the Complex Number 2 :";
				cin>>n2;
				cout<<"\nFirst Complex Number is\n"
				    <<n1
				    <<"\nSecond Complex Number is\n"
				    <<n2;
				n2 = n1.ADD(n2); // ADDING THE COMPLEX NUMBERS
				cout<<"\nThe Sum is \n"<<n2;
				break;
			case 2 :// ADDING THE REAL AND COMPLEX NUMBER
				cout<<endl
				    <<"Please Enter the Following Data"<<endl
				    <<"Enter The Complex Number 1 : ";
				cin>>n1;
				cout<<"\nEnter Any Real Number : ";
				cin>>f1;
				cout<<"\nComplex Number is\n"
				    <<n1
				    <<"\nReal Number is\n"
				    <<f1;
				n2 = n1.ADD(f1); // ADDING
				cout<<"\nThe Sum is \n"<<n2;
				break;

			case 0 : return 0; // terminating the program
			default: cout<<"\n\nERROR INVALID INPUT\n";
		} // END OF THE SWITCH
	} // END OF THE WHILE LOOP
}
//			       END OF PROGRAM                            //
///////////////////////////////////////////////////////////////////////////