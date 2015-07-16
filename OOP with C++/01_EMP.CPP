/**************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Given that an EMPLOYEE class contains following members :

	Data members : Employee_Number,Employee_Name,Basic,DA,IT,Net_Sal

	Member functions : to read the data, to calculate Net_Sal and
	to print data members.

	Write a C++ program to read the data of N employee and compute
	Net_Sal of each employee

	(DA = 52 % of Basic and Income Tax(IT) = 30 % of the gross
	salary)
\**************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <iomanip.h>

// C O N S T A N T S
#define MAX_CHAR 25 // MAXIMUM NUMBER OF CHARACTERS IN A NAME

///////////////////////////////////////////////////////////////////////////

class EMPLOYEE
// BASE CLASS OF EMPLOYEE
{
	// DATA MEMBERS
	int Employee_Number;
	float Basic,DA,IT,Net_Sal,Gross_Sal;
	char Employee_Name[MAX_CHAR]; // NAME OF THE EMPLOYEE

	public : // MEMBER FUNCTIONS
		void getdata(); // FUNCTION TO READ THE DATA
		void calc();    // FUNCTION TO CALCULATE NET SALARY
		void putdata(); // FUNCTION TO PRINT THE DATA
}; // END OF CLASS DEFINATION

///////////////////////////////////////////////////////////////////////////

void EMPLOYEE :: getdata()
// FUNCTION TO READ THE DATA
{
	cout<<"\nEnter the EMPLOYEE Number : ";
	cin>>Employee_Number;
	fflush(stdin); // FLUSHING THE STANDARD INPUT BUFFER

	cout<<endl
	    <<"Enter the Employee Name : ";
	gets(Employee_Name); // READING THE NAME

	cout<<endl<<"Please Enter the Basic Salary : ";
	cin>>Basic;

	calc(); // CALLING CALC FUNCTION TO CALCULATE NET SALARY
} // END OF FUNCTION GETDATA

///////////////////////////////////////////////////////////////////////////

void EMPLOYEE :: calc()
// FUNCTION TO CALCULATE THE NET SALARY
{
	DA = 0.52 * Basic;
	Gross_Sal = DA + Basic;
	IT = 0.30 * Gross_Sal;
	Net_Sal = Gross_Sal - IT; // NET SALARY
} // END OF FUNCTION CALC

///////////////////////////////////////////////////////////////////////////

void EMPLOYEE :: putdata()
// FUNCTION TO OUTPUT THE NET SALARY WITH EMPLOYEE INFORMATION
{
	cout<<endl
	    <<setw(8)<<Employee_Number
	    <<setw(25)<<Employee_Name
	    <<"\t"<<Basic
	    <<"\t\t"<<Net_Sal
	    <<endl;
} // END OF FUNCTION PUTDATA

///////////////////////////////////////////////////////////////////////////

int main(void)
// MAIN FUNCTION
{
	EMPLOYEE * emp; // POINTER FOR OBJECT OF EMPLOYEE CLASS
	int No;

	clrscr();

	cout<<endl
	    <<"***************************************************************************"
	    <<endl
	    <<"Please Enter the Following Data"<<endl
	    <<"Enter the Number of Employee's : ";
	cin>>No;

	if(No == 0) // NO EMPLOYEE PRESENT
	{
		cout<<"No Employee";
		cout<<endl<<"press any key to continue";
		getch();
		return 0;
	}

	emp = new EMPLOYEE [No]; // DYNAMIC ALLOCATION

	for(int i = 0 ; i < No; i++) // READING THE DATA
	{
		cout<<"\n\nEnter the Information of "<<i+1<<" th Employee..";
		emp[i].getdata();
	}

	if(No != 0) // NO EMPLOYEE PRESENT
	cout<<endl
	    <<"***************************************************************************"
	    <<"\nEmp Number      Name                    Basic            Net_Salary"
	    <<"\n***************************************************************************";
	for(i = 0 ; i < No; i++) // PRINTING THE NET SALARY
	{
		emp[i].putdata(); // CALLING PUTDATA FUNCTION TO PRINT
	}

	cout<<endl<<"press any key to continue";
	delete []emp;
	getch();
	return 0;
} // END OF FUNCTION MAIN
//			       END OF PROGRAM				 //
///////////////////////////////////////////////////////////////////////////