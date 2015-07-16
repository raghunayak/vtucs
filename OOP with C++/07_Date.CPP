/*************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++ Program to create a class called DATE. Accept two valid
	dates in the form dd/mm/yy. Implement the following operations by
	overloading the operator + and -.
	After every operation display the results by overloading the
	operator <<.

	i.	no_of_days = d1 - d2 ; where d1 and d2 are DATE
		objects, d1 >= d2 and no_of_days is an integer.
	ii.	d2 = d1 + no_of_days ; where d1 is a Date object and
		no_of_days is an integer.

\*************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>

///////////////////////////////////////////////////////////////////////////

class DATE
// CLASS OF DATE
{
	int dd, mm, yy;

	public :
		DATE(int, int, int); // CONSTRUCTOR TO READ THE DATE
		DATE() {}  // EMPTY CONSTRUCTOR
		// OPERATOR OVERLOADING TO READ THE DATE
		friend istream & operator >> (istream &, DATE &);
		// OPERATOR OVERLOADING TO PRINT THE DATE
		friend ostream & operator << (ostream &,DATE);
		// OPERATOR OVERLOADING TO SUBTRACT TWO DATES
		friend int operator - (DATE &, DATE &); // RETURNS THE NO. OF DAYS
		friend DATE operator +(DATE , int); // ADDS DATE WITH NO. OF DAYS
}; // END OF THE CLASS DEFINATION OF CLASS DATE

///////////////////////////////////////////////////////////////////////////

DATE :: DATE(int date, int month, int year)
// CONSTRUCTOR OF THE CLASS DATE TO COPY THE DATE FROM ANOTHER FUNCTION
{
	dd = date;
	mm = month;
	yy = year;
} // END OF THE CONSTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

istream & operator >> (istream & is, DATE & ob)
// THIS FUNCTION READS THE DATE FROM KEYBOARD
{
	char temp;
	int valid = 0; // STORES THE VALUE 1 IF THE ENTERED DATE IS VALID DATE

	while(!valid) // WHILE LOOP CONTINUES WHILE ENTERED DATE IS INVALID
	{
		cout<<"\nPlease Enter the valid date in the format dd/mm/yyyy   : ";
		cin>>ob.dd>>temp>>ob.mm>>temp>>ob.yy;

		if(ob.dd < 1) // INVALID DAY ENTERED
		{
			cout<<"\nWrong i/p\nDay can not be less than 1\n";
			continue;
		}

		int year = ob.yy, i = 0;
		while(year != 0) // CHECKING FOR THE FORMAT YYYY
		{
			year = year / 10;
			i++;
		}

		if(i!=4) // YEAR IS NOT ENTERED IN THE FORMAT YYYY
		{
			cout<<"\nError\nPlease Enter the year in the format YYYY\nEg : 20/04/2004\n";
			continue;
		}

		switch(ob.mm) // CHECKING WHETHER THE MONTH ENTERED IS VALID
		{
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10:
		case 12:
			if(ob.dd > 31) // ENVALID DAY
			{
				cout<<"\nWrong i/p\nDay can not be greater than 31\n";
				continue;
			}
			break;
		case 2 :
			if((ob.yy % 400) && !(ob.yy % 100) && (ob.dd > 28))
			{
				cout<<"\nWrong i/p\nThis year Feb contains only 28 Days\n";
				continue;
			}

			else if(!(ob.yy % 4) && (ob.dd > 29))
			{
				cout<<"\nWrong i/p\nThis year Feb contains only 29 Days\n";
				continue;
			}
			
			else if(ob.dd > 28) // FEB HAS 28 DAYS ONLY
			{
				cout<<"\nWrong i/p\nThis year Feb contains only 28 Days\n";
				continue;
			}
			break;
		case 4 :
		case 6 :
		case 9 :
		case 11:
			if(ob.dd > 30 ) // INVALID DATE
			{
				cout<<"\nWrong i/p\nDay can not be greater than 30\n";
				continue;
			}
			break;
		default: // MONTH ENTERED IS INVALID
			cout<<"\nWrong i/p\nCheck your Month\n";
			continue;
		} // END OF THE SWITCH

		if(ob.yy < 0 ) // YEAR ENTERED IS INVALID
		{
			cout<<"\nWrong i/p\n";
			continue;
		}

		valid = 1; // ACCEPT THE DATE
	} // END OF THE WHILE LOOP
	
	return is; // ENTERED DATE IS O.K.

} // END OF THE FUNCTION TO READ THE DATE

///////////////////////////////////////////////////////////////////////////

int operator -(DATE & d1, DATE & d2)
// THIS FUNCTION SUBTRACTS THE 2 DATES AND RETURNS THE NUMBER OF DAYS
{
	int i, no_d1, no_d2, no_dy, lc, no_of_days;

	no_d1 = no_d2 = lc = 0; // INITIALIZE ALL TO ZERO

	for(i = 1 ; i < d1.mm ; i++)
	{
		if(i == 1 || i == 3 || i == 5 ||i == 7 || i == 8 || i == 10 || i == 12)
		{
			no_d1 = no_d1 + 31;
		} // END IF
		else if(i == 2)
		{
			if((d1.yy % 400) && !(d1.yy % 100))
				no_d1  = no_d1 + 28;
			else if(!(d1.yy % 4))
				no_d1  = no_d1 + 29;
			else
				no_d1  = no_d1 + 28;
		}
		else
			no_d1  = no_d1 + 30;
	} // END OF THE FOR LOOP

	no_d1 = no_d1 + d1.dd; // NUMBER OF DAYS IN DATE 1

	for(i = 1 ; i < d2.mm ; i++)
	{
		if(i == 1 || i == 3 ||i == 5 ||i == 7 ||i == 8 ||i == 10 ||i == 12)
		{
			no_d2  = no_d2 + 31;
		}
		else if(i == 2)
		{
			if((d2.yy % 400) && !(d2.yy % 100))
				no_d2  = no_d2 + 28;
			else if(!(d2.yy % 4))
				no_d2  = no_d2 + 29;
			else
				no_d2  = no_d2 + 28;
		}
		else
			no_d2  = no_d2 + 30;
	} // END OF THE FOR LOOP

	no_d2 = no_d2 + d2.dd; // NUMBER OF DAYS IN DATE 2

	no_dy = (d1.yy - d2.yy) * 365; // NUMBER OF DAYS FROM YEARS

	for(i = d2.yy ; i < d1.yy ; i++)
	{
		if( !(!((i % 400) && !(i % 100)) && (i % 4)))
			lc = lc +1;
	}

	no_of_days = no_dy + no_d1 - no_d2 + lc;

	return no_of_days;

}  // END OF THE OPERATOR - FUNCTION

///////////////////////////////////////////////////////////////////////////

DATE operator + (DATE ob, int no_of_days)
// THIS FUNCTION ADDS THE NOD WITH A VALID DATE AND RETURN THE RESULTANT DATE
{
	DATE d; // OBJECT OF CLASS DATE

	d = ob;

// STEP 1) ADDING YEARS
	while(no_of_days > 365) // 1 YEAR HAS 365 DAYS
	{
		d.yy = d.yy + 1;
		no_of_days = no_of_days - 365;
	}

// STEP 2) ADDING MONTHS
	while(no_of_days >= 31)
	{
		switch(d.mm)
		{
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10:
		case 12:
			no_of_days = no_of_days - 31;
			d.mm = d.mm + 1;
			break;
		case 2 :
			if(((d.yy % 400 ) != 0) && ((ob.yy % 100) == 0))
			{
				no_of_days = no_of_days - 28 ;
				d.mm = d.mm + 1;
				break;
			}
			if((ob.yy % 4) == 0)
			{
				no_of_days = no_of_days - 28 ;
				d.mm = d.mm + 1;
				break;
			}
			no_of_days = no_of_days - 28 ;
			d.mm = d.mm + 1;
			break;
		default :
			no_of_days = no_of_days - 30;
			d.mm = d.mm + 1;
		} // END OF THE SWITCH CONDITION

		if(d.mm > 12) // IF MONTH > 12 INCREASE YEAR BY 1 & MAKE MONTH = 1
		{
			d.yy = d.yy + 1;
			d.mm = 1;
		}
	} // END OF THE WHILE LOOP

// STEP 3) ADD THE NUMBER OF DAYS TO DAY

	d.dd = d.dd + no_of_days; // ADD THE DAYS TO DAY

	if(d.dd >= 28) // INCREASING THE MONTH
	{
		if(d.mm == 4 || d.mm == 6 || d.mm == 9 || d.mm == 11 && d.dd >= 30)
		{
			d.mm = d.mm + 1;
			d.dd = d.dd - 30;
	    }
	    else if(d.mm == 2) // MONTH IS FEB
	    {
			if(((d.yy % 400 ) != 0) && ((ob.yy % 100) == 0))
			{
				d.dd = d.dd - 28 ;
				d.mm = d.mm + 1;
			}
			else if((ob.yy % 4) == 0)
			{
				d.dd = d.dd - 29 ;
				d.mm = d.mm + 1;
			}
			else
			{
				d.mm = d.mm + 1;
				d.dd = d.dd - 28;
			}
		}
		else if(d.dd >= 31)
		{
			d.mm = d.mm + 1;
			d.dd = d.dd - 31;
		}
	}

	return d; // RETURN THE NEW DATE
} // END OF THE OPERATOR + FUNCTION

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os , DATE ob)
// OPERATOR OVERLOADING TO OUTPUT THE DATE
{
	os<<"\t"<<ob.dd<<" / "<<ob.mm<<" / "<<ob.yy;
	return os;
} // END OF THE FUNCTION

///////////////////////////////////////////////////////////////////////////

int main(void)
// THE MAIN FUNCTION BEGINS
{
	DATE d1, d2; // OBJECT OF THE DATE CLASS
	int choice, no_of_days;

	clrscr();

	while(1)
	{
		// PRINTING THE MENU
		cout<<"\n\n\t\t\t     **** MENU ****";
		cout<<"\nPlease Enter your Choice : ";
		cout<<"\n\t1 to Subtract two DATES";
		cout<<"\n\t2 to ADD Number of Days with a valid DATE";
		cout<<"\n\t0 for Exit";
		cout<<"\nEnter your choice : ";
		istream & flush();
		cin>>choice;

		switch (choice)
		{
			case 1 :
				cout<<"\nEnter the FIRST date\n";
				cin>>d1;
				cout<<"\nEnter the SECOND date\n";
				cin>>d2;

				no_of_days = d1 - d2;
				if(no_of_days < 0)
				{
	    cout<<"\nThe first date should be greater than second date\n";
				break;
				}
				cout<<"\nDate D1 = "<<d1;
				cout<<"\nDate D2 = "<<d2;
				cout<<"\nD1 - D2 = \t"<<no_of_days;
				break;
			case 2 :
				cout<<"\nEnter the FIRST Date\n";
				cin>>d1;
	cout<<"\nEnter the number of days to be added to the FIRST date : ";
				cin>>no_of_days;
				d2 = d1 + no_of_days;
				cout<<"\nDate D1 = "<<d1;
				cout<<"\n\nNo_of_Days = "<<no_of_days;
				cout<<"\n\nD2 <- D1 + No_of_Days";
				cout<<"\n\nDate D2 = "<<d2;
				break;
			case 0 : return 0; // TERMINATING THE PROGRAM
			default: cout<<"\nERROR INVALID INPUT\n";
		}
	}
} // END OF MAIN FUNCTION
//			END OF PROGRAM					 //
///////////////////////////////////////////////////////////////////////////