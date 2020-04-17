#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
int mp[30003];
vector<int> graph[30003];
/*
Start a small ( just 2 steps ) dfs ( or bfs ) from each graph vertex, count the number of ways to get from current vertex in some other ( let it be cnt[v] ). Then add cnt[v] * ( cnt[v] - 1 ) / 2 to the answer.
*/



int dsf(int start, int n)
{
   memset(mp, 0 , sizeof(mp));
   queue<int > st;
   st.push(start);
   int count =0;
   while(st.size() && count < 3)
   {
       int len = st.size();
       while(len--)
       {
           int rem = st.front(); st.pop();
            if( count == 2)
            {
                mp[rem] ++ ;
                continue;                          // no need to add node further
            }
           for(int x: graph[rem])
           {
             st.push(x);
           }
       }
       count++;
   }
   int res = 0;
    for(int i =1 ;i <= n ;i++)
    {
        if( i == start ) continue;
        res += (mp[i] *(mp[i]-1))/2;
    }
   return res;
}
void solve()
{
    int n , m;
    cin >> n >>m ;
    for(int i = 0 ; i< m ; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    int res =0;
    for(int i =1 ; i<= n; i++)
    {
        int cur = dsf( i, n);
        res += cur;
    }
    cout << res << endl;
}

int32_t main(){
	fast;          
   solve();              
}

// another good solution
/*
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
 
using namespace std;
 
int n, m;
vector < int > gr[3000];
bool used[3001];
int d[3001];
 
void dfs ( int v, int len )
{
    if ( len == 2 )
    {
        d[v]++;
        return;
    }
 
    for ( int i = 0; i < gr[v].size(); i++ )
        if ( !used[ gr[v][i] ] )
            dfs ( gr[v][i] , len + 1 );
}
 
int main()
{
    cin >> n >> m;
 
    for ( int i = 0; i < m; i++ )
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        gr[a].push_back ( b );
    }
 
    long long ans = 0;
 
    for ( int i = 0; i < n; i++ )
    {
        for ( int i = 0; i < n; i++ )
            d[i] = 0;
 
        dfs(i , 0);
 
        for ( int j = 0; j < n; j++ )
            if ( j != i )
            ans += d[j] * ( d[j] - 1 ) / 2;
    }
 
    cout << ans << "\n";
    return 0;
}
*/