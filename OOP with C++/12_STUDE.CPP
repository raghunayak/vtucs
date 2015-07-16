/*************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++ program to create a class STUDENT with data members
	USN, Name and Age. using inheritance, create the classes
	UGSTUDENT and PGSTUDENT having fields as Semester, Fees and Stipend.
	Enter the dta for at least 5 students. Find the semester wise
	average age for all UG and PG students separately.

\*************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <iomanip.h>

// C O N S T A N T S
#define MAX_CHAR 20 // MAXIMUM NUMBER OF CHARACTERS IN A NAME

float avg_age[8]; // TO STORE THE TOTAL AGE PER SEMESTER
float std_no[8];  // TO STORE THE NUMBER OF STUDENTS PER SEMESTER

///////////////////////////////////////////////////////////////////////////

class STUDENT // BASE CLASS
// CLASS OF STUDENT
{
	public :
		int USN,Age;         // DATA MEMEBERS
		char Name[MAX_CHAR];
}; // END OF CLASS DEFINATION OF STUDENT

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

class UGSTUDENT : public STUDENT // DERIVED CLASS FROM STUDENT
// CLASS OF UGSTUDENT
{
	int Semester;        // DATA MEMBERS
	float Fees,Stipend;

	public :
		// THIS FUNCTION READS THE DATA THROUGH OPERATOR OVERLOADING
		friend istream & operator >> (istream &, UGSTUDENT &);
		// THIS FUNCTION PRINTS THE STUDENTS INFORMATION
		friend ostream & operator << (ostream &, UGSTUDENT);
		void print_avg(); // THIS FUNCTION PRINTS THE SEMESTERWISE AVERAGE
};
// END OF CLASS UGSTUDENT

///////////////////////////////////////////////////////////////////////////

istream & operator >> (istream & is, UGSTUDENT & ob)
// THIS FUNCTION READS THE DATA FROM KEYBOARD THROUGH OPERATOR OVERLOADING
{
	cout<<"\nEnter the USN of the Student : ";
	is>>ob.USN;
	cout<<"\nEnter the Name of student : ";
	istream & flush(); // FLUSHING THE ISTREAM BUFFER
	gets(ob.Name);
	cout<<"\nEnter the Semester : ";
	is>>ob.Semester;
	cout<<"\nEnter the Age of the Student : ";
	is>>ob.Age;
	cout<<"\nEnter the Fees Paid : ";
	is>> ob.Fees;
	cout<<"\nEnter the Amount of Stipend : ";
	is>>ob.Stipend;

	std_no[ob.Semester-1]++;
	if(ob.Semester > 0 && ob.Semester < 9)
		avg_age[ob.Semester-1] = avg_age[ob.Semester-1] + ob.Age;

	return is;
} // END OF OPERATOR OVERLOADING

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os, UGSTUDENT ob)
// THIS FUNCTION PRINTS THE STUDENTS INFO THROUGH OPERATOR OVERLOADING
{
	os<<setw(7)<<ob.USN<<"\t"
	  <<setw(22)<<ob.Name<<"\t   "
	  <<setw(8)<<ob.Semester
	  <<setw(8)<<ob.Age
	  <<setw(8)<<ob.Fees
	  <<setw(8)<<ob.Stipend<<endl;

	return os;
} // END OF FUNCTION PUTDATA

///////////////////////////////////////////////////////////////////////////

void UGSTUDENT :: print_avg()
// THIS FUNCTION PRINTS THE SEMESTERWISE AVERAGE AGE
{
	cout<<"\nAverage Age are as follows : \n";

	for(int i = 0 ; i < 8 ; i++)
	   if(std_no[i] != 0)
		 cout<<"Semester : "<<(i+1)<<"   "<<avg_age[i]/std_no[i]<<endl;
	   else
		cout<<"Semester : "<<(i+1)<<"   "<<0<<endl;
} // END OF FUNCTION PRINT_AVG

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

class PGSTUDENT : public STUDENT
// CLASS OF PGSTUDENT DERIVED FROM THE CLASS STUDENT
{
	int Semester;
	float Fees,Stipend;

	public :

		// OPERATOR OVERLOADING TO READ THE STUDENTS INFORMATION
		friend istream & operator >> (istream & is, PGSTUDENT & ob);
		// FUNCTION TO PRINT THE DATA THROUGH OPERATOR OVERLOADING
		friend ostream & operator << (ostream &, PGSTUDENT);
		void print_avg(); // FUNCTION TO PRINT THE SEMESTERWISE AVERAGE AGE
}; // END OF THE FUNCTION PGSTUDENT

///////////////////////////////////////////////////////////////////////////

istream & operator >> (istream & is, PGSTUDENT & ob)
// OPERATOR OVERLOADING TO READ THE PGSTUDENTS INFORMATION
{
	cout<<"\nEnter the USN of the Student : ";
	is>>ob.USN;
	cout<<"\nEnter the Name of student : ";
	istream & flush(); // FLUSHING THE ISTREAM BUFFER
	gets(ob.Name);
	cout<<"\nEnter the Semester : ";
	cin>>ob.Semester;
	cout<<"\nEnter the Age of the Student : ";
	cin>>ob.Age;
	cout<<"\nEnter the Fees Paid : ";
	cin>> ob.Fees;
	cout<<"\nEnter the Amount of Stipend : ";
	cin>>ob.Stipend;

	std_no[ob.Semester-1]++;
	if(ob.Semester > 0 && ob.Semester < 5)
		avg_age[ob.Semester-1] = avg_age[ob.Semester-1] + ob.Age;

		return is;
} // END OF THE OPERATOR OVERLOADING

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os, PGSTUDENT ob)
// THIS FUNCTION PRINTS THE DATA THROUGH OPERATOR OVERLOADING
{
	os<<setw(7)<<ob.USN<<"\t"
	  <<setw(22)<<ob.Name<<"\t   "
	  <<setw(8)<<ob.Semester
	  <<setw(8)<<ob.Age
	  <<setw(8)<<ob.Fees
	  <<setw(8)<<ob.Stipend<<endl;

	  return os;
} // END OF OPERATOR OVERLOADING FUNCTION

///////////////////////////////////////////////////////////////////////////

void PGSTUDENT :: print_avg()
// THIS FUNCTION PRINTS THE AVERAGE AGE
{
	cout<<"\nAverage Age are as follows : \n";

	for(int i = 0 ; i < 4 ; i++)
	   if(std_no[i] != 0)
		 cout<<"Semester : "<<(i+1)<<"   "<<avg_age[i]/std_no[i]<<endl;
	   else
		cout<<"Semester : "<<(i+1)<<"   "<<0<<endl;
} // END OF THE FUNCTION PRINT_AVG()

///////////////////////////////////////////////////////////////////////////

int main(void)
// MAIN FUNCTION
{
	clrscr();
	int num;

	while(1) // MENU DRIVEN PROGRAM
	{
		// printing the menu
		int choice,number;
		cout<<"\n\n\t\t\t**** MENU ****\n";
		cout<<"Please Enter your Choice : \n";
		cout<<"\t1 for UG Student\n";
		cout<<"\t2 for PG Student\n";
		cout<<"\t0 for Exit\n";
		cout<<"Enter your choice : ";
		cin>>choice;

		switch (choice)
		{
			case 1 :// UGSTUDENT
				 cout<<"\nPlease Enter the Number of students : ";
				 cin>>num;
				 UGSTUDENT *ob1; // POINTER

				 ob1 = new UGSTUDENT [num]; // ALLOCATION

				 for(int i = 0 ; i < 8 ; i++)
				 {
					avg_age[i] = 0;
					std_no[i] = 0;
				 }

				 for(i = 0 ; i < num ; i++)
				 {
					cout<<"\n\n\nPlease Enter the Information for "<<i+1<<" th Student\n";
					cin>>ob1[i];
				 }
				 cout<<"\nThe information Entered are as follows ";
				 cout<<"\n\n"
				     <<"   USN\t\tName\t\t\tSem\tAge\tFees\tStipend"
				     <<"\n==========================================="
				     <<"===================================\n";
				 int j = 0;
				 for(i = 0 ; i < num ; i++)
				 {
					cout<<ob1[i];
					j++;
					if(j == 10)
					{
						cout<<"\npress any key";
						getch();
						cout<<endl;
						j = 0;
					}
				 }
				 cout<<"\n\npress any key for average age information";
				 getch();
				 cout<<"\n\n";
				 ob1[i].print_avg();

				 delete []ob1;
				 break;
			case 2 :// PGSTUDENT
				cout<<"\nPlease Enter the Number of students : ";
				cin>>num;
				PGSTUDENT *ob2; // POINTER

				ob2 = new PGSTUDENT [num]; // ALLOCATION

				for(i = 0 ; i < 8 ; i++)
				{
					avg_age[i] = 0;
					std_no[i] = 0;
				}

				for(i = 0 ; i < num ; i++)
				{
					cout<<"\nPlease Enter the Information for "<<i+1<<" th Student\n";
					cin>>ob2[i];
				}
				cout<<"\nThe information Entered are as follows ";
				cout<<"\n\n"
				    <<"   USN\t\tName\t\t\tSem\tAge\tFees\tStipend"
				    <<"\n==========================================="
				    <<"===================================\n";

				j = 0;
				for(i = 0 ; i < num ; i++)
				{
					cout<<ob2[i];
					j++;
					if(j == 10)
					{
						cout<<"\npress any key";
						getch();
						cout<<endl;
						j = 0;
					}
				}
				cout<<"\n\npress any key for average age information";
				getch();
				cout<<"\n\n";
				ob2[i].print_avg(); // PRINTING

				delete []ob2; // DELETING THE ARRAY
				break;
			case 0 : return 0; // terminating the program
			default: cout<<"\n\nERROR INVALID INPUT\n";
		}
	}
} // End of main function
///////////////////////////////////////////////////////////////////////////
/*			END OF PROGRAM					 */