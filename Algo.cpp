#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cmath>
#include <stack>
#include <string>
#include <time.h>
#include <stdlib.h>


using namespace std;
int makeRandom(long arr[],long n);
template <class T>
void InsertionSort (T arr[],long n);
template <class T>
void RadixSort(T arr[],long n);
void swap( int lhs, int rhs );
template<class T>
void quick_sort(T arr[], int first, int last,long n);
template<class T>
int pivot(T a[], int first, int last);
template <class T>
void loadStack(T a[], long n);
void partition(long arr[], int l, int r, int &i, int &j);
void quickSort3(long arr[], int l, int r, long n);
template <class T>
int getMax(T arr[], long n);
template <class T>
void countSort(T arr[], long n, int exp);

struct Node {
    int data;
    Node* next;
};
    Node* head;
    
void Insert(int data) { //Insert an integer at the end of list
    Node* temp1 = new Node;
    temp1->data = data;
    temp1->next = head;
    head = temp1;
}
void Print() { //Print all elements in the list
	cout << "linked list printing................"<<endl;
    Node* temp1 = head;
    while (temp1 != NULL) {
        cout << " " << temp1->data;
        temp1 = temp1->next;
    }
    cout << endl;
}


int main() {
	cout<<"Enter an array size:" ;
	long n;
	cin>>n;
	long array[n];
	makeRandom(array,n);
	

		
	int select;
	
	cout<<"\n\nWhich of the Sorting Algorithms below you want to use? \n\n1. Insertion Sort \n2.Radix Sort \n3.Quick Sort 2 \n4.Quick Sort 3\n" ;
	cin>>select;
	
	
	
	if(select==1)
 	InsertionSort(array,n);
 	
 	else if(select==2)
    RadixSort(array,n);
    
 	else if(select==3){
 	
	clock_t start=clock();
	quick_sort(array,0,n-1,n);
	clock_t end=clock();
    double time=end-start;
	 cout <<"\n\n";        
 	cout<<"quickSorted2 Array is: \n\n"; 
		for(int i=0;i<n;i++)
	{
		cout << array[i]<<" ";
		Insert(array[i]);
	}
	
	Print();
	
	

  	
  		cout <<"\n\n"; 
	
		cout <<"\n\n";
        cout<<"Compilation Time Elapsed: "<<time;
		
	
	}
 	else if(select==4){
 	clock_t start=clock();
	quickSort3(array,0,n-1,n);
	clock_t end=clock();
    double time=end-start;
	 cout <<"\n\n";        
 	cout<<"quickSorted3 Array is: \n\n"; 
		for(int i=0;i<n;i++)
	{
		cout << array[i]<<" ";
	}
  	
  		cout <<"\n\n";
	
		cout <<"\n\n";
        cout<<"Compilation Time Elapsed: "<<time;
	 }
    
 	else
 	cout<<"Invalid State";
	

}
	
	
	
	int makeRandom(long arr[],long n){
	srand(time(NULL));
	long i;
	cout <<"\n\n";
	cout<< "Random Array is: \n";
	cout <<"\n\n";
	for(i=0;i<n;i++){
		arr[i]=rand() % 1000 + 1;
		cout << arr[i]<<" ";
		}
		return arr[i] ;
		
	}
	
	
	
	
	////
	/////
	/////////
	/////////////// INSERTION SORT
	
	
	
	template <class T>
	
	void InsertionSort(T arr [], long n ) {
		
		clock_t start=clock();
         T temp=arr[0];
 for(int i = 1; i <= n; i++)
    {
        temp = arr[i];
        int j = 0;
        for(j = i; j > 0; j--)
            if(temp < arr[j - 1])
               arr[j] = arr[j - 1];
            else break;
        arr[j] =  temp;
    }
cout <<"\n\n";
	cout<<"InsertionSorted Array is: \n\n"; 
	for(int i=0;i<n;i++)
	{
		cout << arr[i]<<" ";
	}
	
		cout <<"\n\n";
	
		cout <<"\n\n";
	 clock_t end=clock();
    double time=end-start;
	cout<<"Best Case: \n";
        cout<<"Time Elapsed:\n" << time;
	cout<<"Average Case: \n";
        cout<<"Time Elapsed:\n" <<time;
	cout<<"Worst Case: \n";
        cout<<"Time Elapsed:\n" <<time;
	
	}
	
//////
////////
/////////////  RADIX SORT
//  
		template <class T>
	int getMax(T arr[], long n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}





	template <class T>
	void countSort(T arr[], long n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

	template <class T> 
    void RadixSort(T arr[] ,long n) {

    clock_t start=clock();

    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
       countSort(arr, n, exp);
        
        
cout <<"\n\n";        
	cout<<"RadixSorted Array is: \n\n"; 
		for(int i=0;i<n;i++)
	{
		cout << arr[i]<<" ";
	}
  	
  		cout <<"\n\n";
	
		cout <<"\n\n";
		
            clock_t end=clock();
    double time=end-start;
    cout <<"\n\n";
    cout<<"Compilation Time Elapsed: "<<time;
	

}
	
	
	
	
	
	
	
	
	
	
	
	
	/////
	//////
	////////
	//////////////// QUICK SORT 
	
	
	
	
	
	
	template <class T>
	void quick_sort(T arr[], int first, int last, long n) {
    clock_t start=clock();

    int pivotIndex;
    if (first < last) {
      pivotIndex = pivot(arr, first, last);
      
      quick_sort(arr,first, pivotIndex-1,n);
      quick_sort(arr,pivotIndex+1, last,n);
      
}
}

    template <class T>
int pivot(T arr[], int first, int last) 
{
    int  p = first;
    int pivotElement = arr[first];
 
    for(int i = first+1 ; i <= last ; i++)
    {
        if(arr[i] <= pivotElement)
        {
            p++;
            swap(arr[i], arr[p]);
        }
    }
 
    swap(arr[p], arr[first]);
 
    return p;
}

void swap( int lhs, int rhs )
{
	int tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

void partition(long a[], int l, int r, int &i, int &j){
    i = l-1, j = r;
    int p = l-1, q = r;
    int v = a[r];
 
    while (true)
    {
        
        while (a[++i] < v);
        while (v < a[--j])
            if (j == l)
                break;
 
        
        if (i >= j) break;
        swap(a[i], a[j]);
        if (a[i] == v)
        {
            p++;
            swap(a[p], a[i]);
        }
          if (a[j] == v)
        {
            q--;
            swap(a[j], a[q]);
        }
    }
 
    swap(a[i], a[r]);
 
    j = i-1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);
 
    
    i = i+1;
    for (int k = r-1; k > q; k--, i++)
        swap(a[i], a[k]);
}





//////
////////////
//////////////// QUICK SORT3




void quickSort3(long array[], int l, int r,long n)
{

    if (r <= l) return;
 
    int i, j;
 
    
    partition(array, l, r, i, j);
 
    
    quickSort3(array, l, j, n);
    quickSort3(array, i, r, n);
    
  
 quick_sort(array,0,n-1,n);
	
	
    }

	
		

	

	
	
	
