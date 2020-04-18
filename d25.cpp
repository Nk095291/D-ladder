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
If n is odd, then black can win white doing all the moves symetric by the central line. Else white can win putting his queen on (1,2) (which is the lexicographicly smallest place) and play symetricly — never using the first row.
*/
void solve()
{
    int n ;
    cin >> n;
    if(n %2)
    {
        cout<< "black\n";
    }
    else
    {
        cout<< "white\n";
        cout<< 1 << " " << 2 <<endl;
    }
    
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