%%cu
#include<bits/stdc++.h>
#define n 1000
using namespace std;

__global__ void vectorAdd(int *a, int *b, int *result) 
{
    int tid = threadIdx.x;
    if(tid <= n) 
    {
        result[tid] = a[tid] + b[tid];
    }
}

void print_array(int *a) 
{
    for(int i=0; i<n; i++) {
        cout<<"  "<<a[i];
    }
    cout<<endl;
}

void init_array(int *a) 
{
    for(int i=0;i<n;i++) 
    {
        a[i] = rand()%100 + 1;
    }
}

int main() 
{
    int *d, *e, *res;
    int *d_par, *e_par, *res_par;
 
    d = new int[n];
    e = new int[n];
    res = new int[n];
    int size = n * sizeof(int);
    
    cudaMalloc(&d_par, size);
    cudaMalloc(&e_par, size);
    cudaMalloc(&res_par, size);
    
    init_array(d);
    init_array(e);
    
    print_array(d);
    print_array(e);
            
    cudaMemcpy(d_par, d, size, cudaMemcpyHostToDevice);
    cudaMemcpy(e_par, e, size, cudaMemcpyHostToDevice);
    
    vectorAdd<<<1,n>>>(d_par, e_par, res_par);
    
    cudaMemcpy(res, res_par, size, cudaMemcpyDeviceToHost);
    
    cout<<"Results : "<<endl;
    print_array(res);
         
    cudaFree(d_par);
    cudaFree(e_par);
    cudaFree(res_par);
        
    return 0;
}
