#include<iostream>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
template <class Item>
void selectionSort( Item arr[], int n) {
  for (int i = 0; i < n-1; i++) {
    int min = i;
    for (int j = i+1; j < n; j++)
       if (arr[j] < arr[min]) min = j;
    swap(arr[i], arr[min]);
  }
}

template < class Object>
void swap( Object &lhs, Object &rhs )
{
	Object tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

int main()
{  stack<int> mystack;
 long size;
 cout<< "Write the size of the Array" << endl;
 cin >> size;
 long arr[size];
 srand((unsigned)time(0));
 for (long i = 0; i < size ; i++)
                   {
 	arr[i] =(rand()%1000+1);
}
 selectionSort(arr, size);
       
  for (long i = 0; i < size ; i++){
  cout << arr[i] <<  ",";               
  mystack.push(arr[i]);	
  
}
cout<<"*****************************";
while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
return 0;

}
