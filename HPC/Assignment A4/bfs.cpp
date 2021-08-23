#include <bits/stdc++.h>
#include<omp.h>
using namespace std;
typedef pair<int, int> pi;

vector<vector<pi>> graph;

// Function For Implementing Best First Search
// Gives output path having lowest cost
void best_first_search(int source, int target, int n)
{
	vector<bool> visited(n, false);
	// MIN HEAP priority queue
	priority_queue<pi, vector<pi>,greater<pi>> pq;
	// sorting in pq gets done by first value of pair
	pq.push(make_pair(0, source));
	visited[source] = true;

	while (!pq.empty()) {
		int x = pq.top().second;
		// Displaying the path having lowest cost
		cout << x << " ";
		pq.pop();
		if (x == target)
			break;
		#pragma omp parallel for
		for (int i = 0; i < graph[x].size(); i++) {
		#pragma omp critical
		{
			if (!visited[graph[x][i].second]) {
				visited[graph[x][i].second] = true;
				pq.push(graph[x][i]);
			}
		}
		}
	}
	cout<<endl;
}

// Driver code to test above methods
int main()
{
	int v,inp,x,y,cost;
	cout<<"Enter number of vertices\n";
	cin>>v;
	graph.resize(v);
	do
	{
		cout<<"1.Add Edge\n2.Exit\n";
		cin>>inp;
		if(inp == 2)
		{
			break;
		}
		else
		{
		  cout<<"Enter start vertex, destination vertex,cost of the path\n";
		  cin>>x>>y>>cost;
		  graph[x].push_back(make_pair(cost, y));
		  graph[y].push_back(make_pair(cost, x));
		}
		
	}while(inp==1);
	
	int source = 0;
	int target = 4;

	// Function call
	best_first_search(source, target, v);

	return 0;
}

