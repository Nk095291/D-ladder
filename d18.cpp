#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
map<int, int> mp;
/*
Suppose the given list of divisors is a list of almost all divisors of some 𝑥 (in other words, suppose that the answer exists). 
Then the minimum divisor multiplied by maximum divisor should be 𝑥. 
This is true because if we have a divisor 𝑖 we also have a divisor 𝑛𝑖. 
Let's sort all divisors and let 𝑥=𝑑1⋅𝑑𝑛.

Now we need to check if all divisors of 𝑥 except 1 and 𝑥 are the permutation of the array 𝑑 (check that our answer is really correct). 
We can find all divisors of 𝑥 in 𝑂(𝑥‾‾√), sort them and compare with the array 𝑑. 
If arrays are equal then the answer is 𝑥 otherwise the answer is -1.




*/




bool check(vector<int>&ar, int st, int end ,int x)
{
	while(st <= end)
	{
		if(ar[st]*ar[end] != x)
			return false;
		st++;
		end--;
	}
	return true;
}
bool check2(int x)
{
	for(int i =2 ; i*i <= x; i++)
	{
		if(x%i ==0 && (!mp[i] || !mp[x/i]))
		{
			return false;
		}
	}
	return true;
}

void solve()
{
	int  n;
	cin >> n;
	vector<int> ar(n);
	mp.clear();
	for(int i =0 ; i< n ; i++)
	{
		cin >> ar[i];
		mp[ar[i]]++;
	}
	if(n == 0)
	{
		cout<< 2 << endl;
		return ;
	}
	sort(ar.begin(), ar.end());
	int x = ar[0]*ar.back();
	if(check(ar,0, n-1,x) && check2(x))
	{

		cout<< x << endl;
	}
	else
	{
		cout<< -1 <<endl;
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
   testcase();           
//    solve();              
}

/*
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {

		int n;
		cin >> n;
		vector<long long> d(n);
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}
		sort(d.begin(), d.end());
		long long x = d[0] * d[n - 1];
		
		vector<long long> dd;
		for (int i = 2; i * 1ll * i <= x; ++i) {
			if (x % i == 0) {
				dd.push_back(i);
				if (i != x / i) {
					dd.push_back(x / i);
				}
			}
		}
		sort(dd.begin(), dd.end());
		
		if (dd == d) {
			cout << x << endl;
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}

*/