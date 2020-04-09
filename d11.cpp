#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
/*
In fact, you don't really need to consider the path Bob wanders. 
A priority queue is enough for this problem. When Bob visits a node, 
add its adjacent nodes into the priority queue. Every time he visits a new node, 
it will be one with the smallest index in the priority queue.

Time complexity: (𝑚log𝑛)
*/

vector<int> bfs(vector<vector<int>> &graph)
{
	int n = graph.size();
	vector<int> visited(n);
	priority_queue<int, vector<int> , greater<int>> pq;
	pq.push(1);
	vector<int> res;
	while(pq.size())
	{
		int rem = pq.top(); pq.pop();
		if(visited[rem])
			continue;
		visited[rem] = 1;
		res.push_back(rem);
		for(auto x: graph[rem])
			if(!visited[x])
				pq.push(x);
	}
	return res;
}
void solve()
{
	int n , m;
	cin >> n >> m;
	vector< vector< int > > graph(n + 1);
	for(int i =0 ; i< m ; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> res = bfs(graph);
	for(auto x: res)
		cout<< x << " ";
	cout << endl;
}

void testcase()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
int32_t main(){
	fast;
//    testcase();           
   solve();              
}