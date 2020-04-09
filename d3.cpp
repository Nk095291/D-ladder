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
Firstly, let's notice that for the fixed value of 𝑧 our problem is reduced to the following: 

we are given 𝑛 numbers 𝑎1,𝑎2,…,𝑎𝑛. We need to choose such values 𝑘1,𝑘2,…,𝑘𝑛 that 𝑎1+𝑘1⋅𝑧=𝑎2+𝑘2⋅𝑧=⋯=𝑎𝑛+𝑘𝑛⋅𝑧.
And among all such values 𝑘1,𝑘2,…,𝑘𝑛 we need to choose values in a way to minimize ∑𝑖=1𝑛𝑘𝑖. 
And the sum of 𝑘𝑖 is 𝑦! Of course, for the fixed value 𝑧 the minimum sum of 𝑘𝑖 can be only one.

Let's start with 𝑧=1. It is obvious that if the maximum value in the array 𝑎 is 𝑚𝑥 the value 𝑘𝑖 equals 𝑚𝑥−𝑎𝑖 (for 𝑧=1).
Assume that each 𝑘𝑖 from 1 to 𝑛 has some divisor 𝑑. Then if we multiply 𝑧 by 𝑑 and divide each 𝑘𝑖 by 𝑑 the answer will only become better.
How to calculate this value of 𝑧 fast? We can see that this value equals to 𝑔𝑐𝑑(𝑘1,𝑘2,…,𝑘𝑛)! And it can be proven that this value of 𝑧 is always optimal and we can easily determine 𝑦 for such 𝑧.

Time complexity: 𝑂(𝑛+log𝑚𝑎𝑥(𝑎𝑖)).

*/
void solve()
{
	int n ;
	cin >> n;
	vector<int> ar(n);
	for(int i=0 ; i<n; i++)
	{
		cin >> ar[i];
	}
	int maxx = *(max_element(ar.begin(), ar.end()));
	int g =0;
	int sum =0;
	for(int  i =0 ; i<n; i++)
	{
		g = __gcd(g, maxx - ar[i]);		// finding common divisor of all ki
		sum += ar[i];
	}
	int y = (n * maxx - sum);   				// worst case scenario in which z = 1, then y will simply be the (n * maxx - sum) or (k1 + k2 + k3 + .. + kn) or ( (max - ar[1]) + (maxx - ar[2]) + (maxx - ar[3]) + ... + (maxx - ar[n]) )
	y = y /g; 						//but we can reduce z by dividing it with the "a common divisor" in all ki and as we want the to minimize the y we want this common divisor to be as larger as posible (this GCD of all ki)
	cout << y << " " << g << endl;
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