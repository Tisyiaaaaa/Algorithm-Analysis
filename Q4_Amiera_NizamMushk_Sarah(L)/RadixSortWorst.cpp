#include<iostream> 
#include <ctime> 
#include <chrono>

using namespace std; 
  

 int getMin(int arr[], int n) 
{ 
    int mn = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] < mn) 
            mn = arr[i]; 
    return mn; 
} 
  
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; 
    int i, count[10] = {0}; 
  
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  

    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
void radixsort(int arr[], int n) 
{ 
    int m = getMin(arr, n); 
   
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 
  
void print(int arr[], int n) 
{   
   
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 


int show(int random)
{
	cout << random << " ";
	return 0;
}
	
 int main() 
{ 	
  
  srand (time(0));
  
	int i = 1;
	int size;
	cout << "Input the size of the Array : ";
	cin>>size;
	int arr[size];
	srand((unsigned)time(NULL));
	cout << "Before Radix Sort : " << endl;
	for (int i = 0; i < size; i++){
		arr[i] = 1+ rand() % 1000001;
		show (arr[i]);
	}
	auto start = chrono::system_clock::now();
	cout << endl;
	cout << "After Radix Sort" << endl;
	
    int n = sizeof(arr)/sizeof(arr[0]); 
    radixsort(arr, n); 
	auto end = chrono::system_clock::now();
    print(arr, n); 
	chrono::duration<double> duration = end - start;
	
	cout<<endl;
	cout << "Duration: " << duration.count() << "s\n";
	
    
    return 0; 
} 

