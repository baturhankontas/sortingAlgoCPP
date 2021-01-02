#include <iostream>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <stack>
using namespace std;
// three way partition5
template <class Tmp> void partition(Tmp a[], long l, long r, long &i, long &j)
{
    i = l-1, j = r;
    long p = l-1, q = r;
    Tmp v = a[r];
 
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
    for (long k = l; k < p; k++, j--)
        swap(a[k], a[j]);
    i = i+1;
    for (long k = r-1; k > q; k--, i++)
        swap(a[i], a[k]);
}
template <class Tmp> void quicksort(Tmp a[], long l, long r)
{
    if (r <= l) return;
 
    long i, j;
    partition(a, l, r, i, j);
    quicksort(a, l, j);
    quicksort(a, i, r);
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
                  quicksort(arr,0,size-1);
              
              
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
