/*************************************************************************\

	Name   : G Raghavendra Nayak,
	Class  : IV th Sem CS,
	Reg No : 4CB02CS018.

	Write a C++ program to create a template function for QUICK sort
	and demonstrate sorting of integers and doubles.

\*************************************************************************/

// I N C L U D E S
#include <iostream.h>
#include <conio.h>

///////////////////////////////////////////////////////////////////////////

template <class T>
class QSORT
// CLASS OF QSORT
{
   private:   T *Array;
	      int len;
   public:    QSORT(int);	// CONSTRUCTOR
	      ~QSORT();		// DISTRUCTOR
	      void quickSort(int,int); // FUNCTION FOR QUICKSORT
	      int partition(int, int); // FUNCTION FOR PARTITION
	      friend istream & operator >> (istream &, QSORT <int> &);
	      friend istream & operator >> (istream &, QSORT <double>&);
	      friend ostream & operator << (ostream &, QSORT <int>);
	      friend ostream & operator << (ostream &, QSORT <double>)
};	//End of QSORT class

///////////////////////////////////////////////////////////////////////////

template <class T>
QSORT <T> :: QSORT(int length)
// CONSTRUCTOR DEFINATION
{
    len = length;

    Array = new T [length-1];

    //Initialize all array elements to 0
    for (int k = 0; k < len; k++)
    {
	 Array[k] = 0;
    }
} // END OF THE CONSTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

template <class T>
QSORT <T> :: ~QSORT()
// DISTRUCTOR DEFINATION
{
	delete []Array;
} // END OF THE DISTRUCTOR DEFINATION

///////////////////////////////////////////////////////////////////////////

istream & operator >> (istream & is, QSORT <int> & ob)
// OPEARTOR OVERLOADING TO READ THE INTEGER ARRAY
{
    cout<<"Enter the elements of an array"<<endl;
    for (int k = 0; k < ob.len; k++) // READING THE ARRAY ELEMENTS
    {
	 is>>ob.Array[k];
    }

    return is;
} // END OF THE OPERATOR OVERLOADING

///////////////////////////////////////////////////////////////////////////

istream & operator >> (istream & is, QSORT <double> & ob)
// OPERATOR OVERLAODING TO READ THE DOUBLE ARRAY
{
    cout<<"Enter the elements of an array"<<endl;
    for (int k = 0; k < ob.len; k++) // READING THE ARRAY ELEMENTS
    {
	 is>>ob.Array[k];
    }

    return is;
} // END OF THE OPERATOR OVERLOADING

///////////////////////////////////////////////////////////////////////////

template <class T>
void QSORT <T> :: quickSort(int low, int high)
// FUNCTION FOR PERFORMING THE QUICK SORT
{
    int pos;
    if(low < high)
    {
	 pos = partition(low,high);
	 quickSort(low, pos-1);
	 quickSort(pos+1,high);
    }
} // END OF QUICKSORT FUNCTION

///////////////////////////////////////////////////////////////////////////

template <class T>
int QSORT <T> :: partition(int low, int high)
// FUNCTION TO CREATE THE PARTITIONS
{
    T key, temp;
    int left,right, TRU = 1;

    left = low;
    right= high;
    key = Array[low];  // Assume that the first element
		       // is a pivot value

    while(TRU) // WHILE TRUE
    {
	while(left <high && (key >= Array[left]))
	{
	  left++;
	}

	while(key < Array[right])
	{
	   right--;
	}

	if (left < right)
	{
	   temp = Array[left];
	   Array[left] = Array[right];
	   Array[right]=temp;
	}
	else
	{
	   temp = Array[low];
	   Array[low] = Array[right];
	   Array[right]=temp;
	   return (right);
	}
    }   //End of while
} // END OF THE FUNCTION

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os, QSORT <int> ob)
// FUNCTION TO PRINT THE INTEGER ARRAY USING OPERATOR OVERLOADING
{
    os<<"\nSorted array is "<<endl;
    for (int k = 0; k < ob.len; k++) // PRINTING THE ARRAY
    {
	 os<<ob.Array[k]<<endl;
    }
    return os;
} // END OF FUNCTION DEFINATION

///////////////////////////////////////////////////////////////////////////

ostream & operator << (ostream & os, QSORT <double> ob)
// FUNCTION TO PRINT THE DOUBLE ARRAY USING THE OPERATOR OVERLOADING
{
    os<<"\nSorted array is "<<endl;
    for (int k = 0; k < ob.len; k++) // PRINTING THE ARRAY
    {
	 os<<ob.Array[k]<<endl;
    }
    return os;
} // END OF OPERATOR OVERLOADING

///////////////////////////////////////////////////////////////////////////

int main(void)
// MAIN FUNCTION
{
   int choice, size, low, high;

   clrscr();
   while(1)
   {    // PRINTING THE MENU
	cout<<"\n\t\t\t      **** MENU ****";
	cout<<"\nPlease Enter your choice.. ";
	cout<<"\n\t1 for Sorting Integer Array";
	cout<<"\n\t2 for Sorting Double Precision Array";
	cout<<"\n\t0 for EXIT";
	cout<<"\nEnter your option : ";
	cin>>choice;

	switch(choice)
	{
	case 1 :// INTEGER ARRAY
		cout<<"\nINTEGER ARRAY "<<endl;
		cout<<"\nPlease Enter the size of array"<<endl;
		cin>>size;

		low = 0;
		high = size - 1;
		QSORT<int> IA(size);
		cin>>IA;

		IA.quickSort(low, high);
		cout<<IA;
		break;
	   case 2 :// DOUBLE ARRAY
		cout<<"\nDOUBLR-PRECISION ARRAY "<<endl;
		cout<<"\nPlease Enter the size of array"<<endl;
		cin>>size;

		low = 0;
		high = size - 1;
		QSORT<double> DA(size);
		cin>>DA;

		DA.quickSort(low, high);
		cout<<DA;
		break;
	   case 0 :
		return 0;
	   default :
		cout<<"\nERROR\nINVALID INPUT";
	} // END OF THE SWITCH CONDITION
   }      // END OF WHILE LOOP
}
//			     END OF PROGRAM							 //
///////////////////////////////////////////////////////////////////////////