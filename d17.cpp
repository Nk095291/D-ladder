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
We can solve the problem for each connected component of the graph independently and multiply the answers. Let's analyze a painting of some connected component. 
If some vertex has an odd number written on it, then we should write even numbers on all adjacent vertices, 
and vice versa. So in fact we need to check if the component is bipartite, 
and if it is, divide it into two parts. The number of good paintings is 2𝑎+2𝑏, 
where 𝑎 is the size of the first part, and 𝑏 is the size of the second part, 
because we write 2's into all vertices of one part, and 1's or 3's into all vertices of another part.

*/




int odd;
int even;
int mod = 998244353;
bool isbipartable(vector<vector<int>> &graph, int start, vector<int>&visited)
{
	queue<pair<int, pair<int, int> > > st;
	st.push({start,{0, 0}});
	int n = graph.size();
	
	while(st.size())
	{
		pair<int, pair<int,int>> rem = st.front(); st.pop();
		if(visited[rem.first] != -1 )
		{
			if( visited[rem.first]%2 == rem.second.first%2)
				continue;
			return false;
		}
		if(rem.second.first%2)
		{
			odd  = (odd * 2)%mod;
		}
		else
		{
			even = (even * 2)%mod;
		}
		
		visited[rem.first] = rem.second.first;
		for(auto x: graph[rem.first])
		{
			if(x != rem.second.second)
			{
				st.push({x, {rem.second.first +1, rem.first}});
			}
		}

	}
	return true;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n+1);
	for(int i=0 ; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> visited(n +1, -1);
	int res =1;
	for(int i = 1; i<= n ;i++)
	{
		if(visited[i] == -1)
		{
			odd = 1;
			even = 1;
			bool cur = isbipartable(graph, i, visited);
			if(!cur)
			{
				cout << 0 << endl;
				return ;
			} 
			res = (res * (odd + even)%mod)%mod;
		}
	}
	cout<< res << endl;
	

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
   testcase();           
//    solve();              
}


/*

code for bipartable



int cnt[2];
int col[N];
bool bad;

void dfs(int v, int c){
	col[v] = c;
	++cnt[c];
	for(auto to : g[v]){
		if(col[to] == -1) dfs(to, 1 - c);
		if((col[v] ^ col[to]) == 0)
			bad = true;
	}
}

*/