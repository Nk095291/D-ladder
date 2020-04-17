#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x.second) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);


/*
This problem could be solved in this way: 
create new graph where vertices are the colors of the given graph. 
The edge between vertices u and v belongs this new graph if there are two vertices a and 
b in the given graph such that c[a] = u and c[b] = v. So, the answer is such color k with minimum number, that the degree of the vertex k in the new graph is maximum (without multiple edges). Such solution could be written using O(M·log(N)) time.
*/
void solve()
{
	int n , m;
	cin >> n >>m;
	vector<int> color(n+1);
	vector<vector<int> > graph(n +1);
	map<int, vector<int> > mp;
	for(int i= 1;i<= n ; i++)
	{
		cin >> color[i];
		mp[color[i]].push_back(i);
	}
	
	for(int i =0 ; i< m; i++)
	{
		int a , b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int maxx =-1;
	int ans =-1;
	for(auto x : mp)
	{
		set<int> st;
		for(auto y : x.second)
		{
			for(auto z : graph[y])
				if(color[y] != color[z] )
				{
					st.insert(color[z]);
				
				}
		}
		if((int)st.size() > maxx)
		{
			ans = x.first;
			maxx  = st.size();
		
		}
	}
	cout << ans << endl;
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