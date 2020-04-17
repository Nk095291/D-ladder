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
        cout<< ( i + 1) << " :" ;
        for ( int j = 0; j < n; j++ )
            if ( j != i )
            {
                cout << (j + 1) << ", " << d[j] <<" ";
                ans += d[j] * ( d[j] - 1 ) / 2;
            }
            cout << endl;
    }
 
    cout << ans << "\n";
    return 0;
}