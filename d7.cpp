#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
void solve()
{
	int n , a, b ;
	cin >> n >> a >> b;
	int maxx = b;
	vector<int> ar(n);
	for(int i=0 ; i<n ;i++)
		cin >> ar[i];
	int i;
	for( i = 0 ; i < n; i++)
	{
		if(b)						
		{
			if(!ar[i] || b == maxx || !a)
			{
				b--;						// if we cannot use batter or if its not exposed to sun or b is at it's peak
											// in the above cases if we choose to use acc. battery it is guarantee that the solution cannot get any worse.
			}
			else					// if the segment is exposed to sun then we will use battery because we can increase additional storage in acc. which we can use later
			{						// inshort if use acc. = -1power + (-1power gain) 	
				a--;				// if use battery = -1power + (1 power gain in acc. which we can use later)
				b++;
			}
		}
		else
		{
			if(!a)
				break;
			a--;
			b += ar[i];
		}
	}
	cout<< i << endl;
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