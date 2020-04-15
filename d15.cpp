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
A much easier to solution D is to simply check for each dimension whether 
the observer's position for that dimension is less than 0,
 more than x1/y1/z1, or in between.

For example, if observer's x is less than 0, the a5 side will be visible no matter the observer's y and z, 
if the observer's x is more than x1 (where the cube ends) then the a6 side will be visible no matter the observer's y and z. 
Do the same for the other 2 dimensions and you get the sum. No angle calculations necessary.

*/
void solve()
{
	int a, b, c, x, y, z;
	cin >> a >> b >> c >> x >> y >> z;
	vector<int> ar(6);
	for(int i =0 ; i<6; i++)
		cin >> ar[i];
	int sum =0;
	if(a <0)
		sum += ar[4];
	else if( a > x)
		sum += ar[5];
	if(b < 0)
		sum += ar[0];
	else if( b > y)
		sum += ar[1];
	if(c < 0)
		sum += ar[2];
	else if(c > z)
		sum += ar[3];
	cout << sum <<endl;
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
	#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
//    testcase();           
   solve();              
}