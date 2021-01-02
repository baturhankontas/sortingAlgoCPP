#include<iostream>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;
//bucketSort
template <class a> void bucketSort(a data[], long count){
long minValue = data[0];
long maxValue = data[0];
for (long i = 1; i < count; i++)
{
if (data[i] > maxValue)
maxValue = data[i];
if (data[i] < minValue)
minValue = data[i];
}
long bucketLength = maxValue - minValue + 1;
vector<long>* bucket = new vector<long>[bucketLength];
for (long i = 0; i < bucketLength; i++)
{
bucket[i] = vector<long>();
}
for (long i = 0; i < count; i++)
{
bucket[data[i] - minValue].push_back(data[i]);
}
long k = 0;
for (long i = 0; i < bucketLength; i++)
{
long bucketSize = bucket[i].size();
if (bucketSize > 0)
{
for (long j = 0; j < bucketSize; j++)
{
data[k] = bucket[i][j];
k++;
} 	}	}	}
//quicksort 2way
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
//quicksort 3way
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
//SELECTION SORT
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
 int typeSort;
 cout<< "Choose sort type: " << endl;
 cout<< "1. Bucket Sort " << endl;
 cout<< "2. Quick Sort (2 Way) " << endl;
 cout<< "3. Quick Sort (3 Way) " << endl;
 cout<< "4. Selection Sort " << endl;
 cin >> typeSort;
 srand((unsigned)time(0));
if(typeSort==1){
  cout<<"Bucket Sort is working..."<<endl;
 for (long i = 0; i < size ; i++)
                   {
 	arr[i] =(rand()%1000+1);
	}
	auto t1 = chrono::high_resolution_clock::now();
 	bucketSort(arr, size);
  auto t2 = chrono::high_resolution_clock::now();
  chrono::duration<int64_t,nano> elapsed = t2 - t1;
  for (long i = 0; i < size ; i++){
  cout << arr[i] <<  ",";             
  mystack.push(arr[i]);	
  
}


cout<<"*****************************"<<endl;
cout<<endl;
while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  cout<<endl;
   cout << "Algorithm Runtime is: " << elapsed.count() << " nanoseconds."<<endl;
  }
if(typeSort==2){
	cout<<"Quick Sort (2-WAY) is working..."<<endl;
	for (long i = 0; i < size ; i++)
                   {
                    arr[i] = rand()%1000+1;}
                  // cout << arr[i]<< "," ;
                  auto t1 = chrono::high_resolution_clock::now();
                  quickSort(arr,0,size-1);
                  auto t2 = chrono::high_resolution_clock::now();
                  chrono::duration<int64_t,nano> elapsed = t2 - t1;
  for (long i = 0; i < size ; i++){
  cout << arr[i] <<  ",";               
  mystack.push(arr[i]);	
  
}
cout<<endl<<endl;
cout<<"*****************************"<<endl;
cout<<endl;
while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  cout<<endl;
   cout << "Algorithm Runtime is: " << elapsed.count() << " nanoseconds."<<endl;
}
if(typeSort==3){
	cout<<"Quick Sort (3-WAY) is working..."<<endl;
	for (long i = 0; i < size ; i++)
                   {
                    arr[i] = rand()%1000+1;}
                  // cout << arr[i]<< "," ;
                  
                  auto t1 = chrono::high_resolution_clock::now();
                  quicksort(arr,0,size-1);
                  auto t2 = chrono::high_resolution_clock::now();
                  chrono::duration<int64_t,nano> elapsed = t2 - t1;
              
  for (long i = 0; i < size ; i++){
  cout << arr[i] <<  ",";               
  mystack.push(arr[i]);	
  
}
cout<<endl<<endl;
cout<<"*****************************"<<endl;
cout<<endl;
while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  cout<<endl;
   cout << "Algorithm Runtime is: " << elapsed.count() << " nanoseconds."<<endl;
}
if(typeSort==4){
	cout<<"Selection Sort is working..."<<endl;
	for (long i = 0; i < size ; i++)
                   {
 	arr[i] =(rand()%1000+1);
}
                  auto t1 = chrono::high_resolution_clock::now();
                  selectionSort(arr, size);
                  auto t2 = chrono::high_resolution_clock::now();
                  chrono::duration<int64_t,nano> elapsed = t2 - t1;
 
       
  for (long i = 0; i < size ; i++){
  cout << arr[i] <<  ",";               
  mystack.push(arr[i]);	
  
}
cout<<endl<<endl;
cout<<"*****************************"<<endl;
cout<<endl;
while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  cout<<endl;
   cout << "Algorithm Runtime is: " << elapsed.count() << " nanoseconds."<<endl;
}
return 0;

}
