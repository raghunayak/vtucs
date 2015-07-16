/**************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Define a STUDENT class with USN, Name, and Marks in 3
	tests of a subject. Declare an array of 10 STUDENT objects.
	Using appropriate functions, find the average of two better
	mark for each student. Print the USN, Name and the average
	marks of all students.

\**************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <iomanip.h>

// C O N S T A N T S
#define MAX_CHAR 20 // MAXIMUM NUMBER OF CHARACTERS

class STUDENT
// CLASS OF STUDENTS
{
	int USN;  // DATA MEMBERS
	char Name[MAX_CHAR]; // NAME OF THE STUDENT
	float m1,m2,m3,avg;  // MARKS AND THE AVERAGE

	public :  // MEMBER FUNCTIONS
		// OPERATOR OVERLOADING TO READ THE STUDENTS INFO.
		friend istream & operator >> (istream & is, STUDENT &);
		void calc();    // FUNCTION TO CALCULATE THE BEST AVERAGE
		// OPERATOR OVERLOADING TO PRINT THE STUDENTS INFO.
		friend ostream & operator << (ostream & os, STUDENT);
}; // END OF THE CLASS STUDENTS

///////////////////////////////////////////////////////////////////////////

istream & operator >> (istream & is, STUDENT & ob)
// THIS FUNCTION READS THE DATA FROM THE KEYBOARD
{
	cout<<endl<<"Enter the USN : ";
	is>>ob.USN;
	cout<<"Enter the Name : ";
	gets(ob.Name);
	cout<<"Enter Marks 1 : ";
	is>>ob.m1;
	cout<<"Enter Marks 2 : ";
	is>>ob.m2;
	cout<<"Enter Marks 3 : ";
	is>>ob.m3;
	cout<<endl;

	ob.calc(); // CALLING THE FUNCTION CALC() TO CALCULATE THE BEST AVERAGE

	return is;
} // END OF THE FUNCTION GETDATA

///////////////////////////////////////////////////////////////////////////

void STUDENT :: calc()
// THIS FUNCTION CALCULATE THE BEST AVERAGE OF THE STUDENTS
{
	avg = 0 ;
	if(m1 >= m2 || m1 >= m3)
		avg = m1;       // M1 IS THE ONE OF THE BIGGEST MARKS
	if(m2 >= m3 || m2 > m1)
	{
	      if(avg == 0)
			avg = m2; // M2 IS THE ONE OF THE BIGGEST MARKS
	      else
			avg = (avg+m2)/2.0; // AVG = (M1+M2)/2.0
	}
	if(m3 > m1 || m3 > m2)
	      avg = (avg+m3)/2; // M3 IS THE ONE OF THE BIGGEST MARKS
} // END OF THE FUNCTION CALC

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os, STUDENT ob)
// THIS FUNCTION PRINTS THE STUDENTS INFORMATION
{
	os<<endl
	    <<setw(7)<<ob.USN<<"\t"
	    <<setw(22)<<ob.Name<<"\t"
	    <<setw(8)<<ob.avg<<endl;

	return os;
} // END OF THE FUNCTION

///////////////////////////////////////////////////////////////////////////

int main(void)
// MAIN FUNCTION
{
	STUDENT *std; // POINTER TO OBJECT OF CLASS STUDENT
	int num, choice;

	clrscr();

       cout<<endl
	   <<"*********************************************************"
	   <<endl
	   <<"Please Enter the Number of students : ";
       cin>>num;

       if(num > 100) // LARGE NUMBER ENTERED
       {
		cout<<endl<<"LARGE number "<<num<<" Entered";
		cout<<"\n\tPress 1 to continue\n\tPress 0 to abort\n";
		cout<<"Enter your Choice : ";
		cin>>choice;

		if(choice == 0) // USER WANT TO EXIT
		{
			cout<<endl<<"press any key to continue";
			getch();
			return 0; // STOPING THE PROGRAM
		}
       }

       std = new STUDENT [num]; // DYNAMIC ALLOCATION OF MEMORY

       cout<<endl<<endl<<"Please Enter the Following Data...\n"<<endl;
       for(int i = 0 ; i < num ; i++)
       {
	   cout<<"Enter the information of "<<i+1<<" th Student\n";
	   cin>>std[i]; // READING THE DATA
       }

       cout<<"\n The Out put is ";

       cout<<endl
	   <<"********************************************************"
	   <<"\n    USN             Name             Avg"
	   <<"\n********************************************************";

       for(i = 0 ; i < num ; i++)
       {
	    cout<<std[i]; // PRINTING THE DATA
       }

       delete []std; // DEALLOCATING THE MEMORY

       cout<<endl<<"press any key to continue";
       getch();
       return 0 ;
}
//				END OF PROGRAM				 //
///////////////////////////////////////////////////////////////////////////