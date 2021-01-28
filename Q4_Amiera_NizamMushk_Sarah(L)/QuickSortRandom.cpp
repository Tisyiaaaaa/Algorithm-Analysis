#include <iostream>
#include <vector>
#include <ctime> 
#include<cstdlib>
#include<chrono>
using namespace std;
int partition(int S[], int p,int r)
{
	
	
    int x= S[p];
    int i=p;
    int j;

    for(j=p+1; j<r; j++)
    {
        if(S[j]<=x)
        {
            i=i+1;
            swap(S[i],S[j]);
        }

    }

    swap(S[i],S[p]);
    return i;
}
int randomPivot(int S[],int p, int r)
{
	int pivot,n;
	n=rand();
	pivot=p+n%(r-p);

	swap(S[p],S[pivot]);
	return partition(S,p,r);
}

void quickSort(int S[], int p,int r)
{
    int m;
    if(p<r)
    {
        m=randomPivot(S, p,r);
        quickSort(S,p,m);  
        quickSort(S,m+1,r);
    }
}

int main()
{
	//const int size = 10;
	//const int size = 100;
	//const int size = 1000;
	//const int size = 10000
	const int size=250000;
	 int *array = new int[size];
	
	
	int p=0;
    int r=size;
	//int S[size];
	srand((unsigned)time(0)); 
    for(int i=0; i<size; i++){ 
        array[i] = (rand()%RAND_MAX)+1; 
         
	} 
	
    cout<<"Original Array"<<endl;
    for(int i=0;i<size;i++)
        cout<< array[i] <<" ";
    cout<< endl;    
	auto start = chrono::system_clock::now();
    quickSort(array,p,r);
	
	auto end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;
    cout<<"Sorted Array "<<endl;
     for(int i=0;i<size;i++)
        cout<< array[i] <<" ";
    cout<< endl;

   cout << "Duration: " << duration.count() << "s\n";
// cout<< array[size] <<" Size of array"<<endl;
 
 
 delete[] array;
}






