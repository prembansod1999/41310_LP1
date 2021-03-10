#include<omp.h>
#include<bits/stdc++.h>
using namespace std;
#define n 1000


void bubbleSort(int arr[])
{
	 for (int i = 0; i < n-1; i++) 
	 {
	    int x = i%2;
	    #pragma omp parallel for
            for (int j = x; j < n-1; j++)
            { 
                if (arr[j] > arr[j+1]) 
                { 
                    int temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                }
             }
          } 
}

void init_array(int arr[])
{
	for(int i = 0;i<n;i++)
	{
		arr[i] = rand()%10000;
	}
} 
void print(int arr[])
{
	cout<<endl;
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;	
}


int main()
{
	int *arr = new int[n];
	cout<<"\nInitial Array\n";
	init_array(arr);
	print(arr);
	
	double start,end;
	start = omp_get_wtime();
	
	bubbleSort(arr);
	
	end = omp_get_wtime();
	
	double time_taken = end - start;
	
	cout<<"\nTime Taken = "<<time_taken<<endl;
	
	cout<<"\nSorted Array\n";
	print(arr);
	return 0;
}
