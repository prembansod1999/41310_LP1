#include<bits/stdc++.h>
#include<mpi.h>
using namespace std;
int main(int argc,char** argv)
{
   int node;
   
   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &node);
     
   printf("Hello World from Node %d\n",node);
            
   MPI_Finalize();
	return 0;
}
