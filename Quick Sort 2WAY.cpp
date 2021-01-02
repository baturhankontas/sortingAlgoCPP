#include <stack>
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdlib.h>
using namespace std;
// two way partition
template <class T>  T partition(T arr[], long start, long end)
{
 T pivotValue = arr[start];
    long pivotPosition = start;
    for (long pos = start + 1; pos <= end; pos++)
    {
        if (arr[pos] < pivotValue)
        {  
            swap(arr[pivotPosition + 1], arr[pos]);
            swap(arr[pivotPosition], arr[pivotPosition + 1]);
            pivotPosition ++;
        }
}
    return pivotPosition;
}
template <class T> void quickSort(T arr[], long start, long end)
{
 if (start < end)       
    {
        long p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
}
return; 
}
 int main()
{
  stack<int> mystack;
 long size;
 cout<< "Write the size of the Array" << endl;
 cin >> size;
 double arr[size];
srand((unsigned)time(0));
          for (long i = 0; i < size ; i++)
                   {
                    arr[i] = rand()%1000+1;}
                  // cout << arr[i]<< "," ;
                  quickSort(arr,0,size-1);
              
  for (long i = 0; i < size ; i++){
  cout << arr[i] <<  ",";               
  mystack.push(arr[i]);	
  
}
cout<<"*****************************"<<endl;
while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
return 0;

}


