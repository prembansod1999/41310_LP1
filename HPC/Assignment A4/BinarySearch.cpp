#include<bits/stdc++.h>
#include<mpi.h>
using namespace std;
int binarySearch(int arr[],int s,int e,int key)
{
	int mid;
	while(s<=e)
	{
		mid = (s+e)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]>key)
		{
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		}
	}
	return -1;
}

int main(int argc,char** argv)
{
	int n = 4000;
	
	int *arr=new int[n];

	for(int i=0;i<n;i++)
	{
		arr[i]=i+1;
	}

	int key= 2;

	int ind;
	
	double start = MPI_Wtime();
	
	ind = binarySearch(arr,0,4000,key);
	
	double end = MPI_Wtime();
	
	cout<<"Execution time of Processor is "<<(end - start)*1000<<endl;
	
	cout<<"Index = "<<ind<<endl;		
	
	return 0;
}
