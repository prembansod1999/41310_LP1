#include<omp.h>
#include<iostream> 
using namespace std; 
#define n 1000


void merge(int arr[],int l,int m,int r)
{
	int ls = m-l+1;
	int rs = r-m;
	int L[ls],R[rs];
	
	//Left Array consist of left elements as well as middle also
	for(int i = 0;i<ls;i++)
	{
		L[i] = arr[l+i];
	}
	for(int i = 0;i<rs;i++)
	{
		R[i] = arr[m+1+i];
	}
	int i = 0,j = 0;
	int k = l;
	while(i<ls&&j<rs)
	{
		if(L[i]<=R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<ls)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<rs)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		#pragma omp parallel sections
		{
			#pragma omp section
			{
				mergeSort(arr,l,m);
			}
			#pragma omp section
			{
				mergeSort(arr,m+1,r);
			}
		}
		merge(arr,l,m,r);
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

void init_array(int arr[])
{
	for(int i = 0;i<n;i++)
	{
		arr[i] = rand()%10000;
	}
} 
   
int main() 
{	int *arr = new int[n];
	clock_t t;
	init_array(arr);
	
	cout<<"\nInitial Array\n";
	
	print(arr);
	
	t = clock();
	mergeSort(arr,0,n-1);
	t = clock() - t;
    	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds	

	cout<<"\nTime Taken = "<<time_taken<<endl;
	
	cout<<"\nSorted Array\n";
	
	print(arr);
	return 0; 
} 
