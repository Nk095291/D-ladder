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

tutorial-
Let's calculate the minimum number of secret technique uses we need to kill each of the monsters. 
Let the current monster has ℎ hp. Firstly, it is obvious that we can take ℎ modulo 𝑎+𝑏 (except one case). 
If it becomes zero, let's "rollback" it by one pair of turns. 
Then the number of uses of the secret technique we need is ⌈ℎ𝑎⌉−1.

Let's sort all 𝑛 monsters by this value and take the "cheapest" set of monsters (prefix of the sorted array) with the sum of values less than or equal to 𝑘.

Time complexity: 𝑂(𝑛log𝑛).


*/
void solve()
{
	int n , a , b, k;
	cin >> n >> a >> b >>k;
	int x = a+ b;
	int y ;
	int count =0;
	priority_queue<int, vector<int> , greater<int>>pq;
	for(int i =0 ;i<n; i++)
	{
		cin >> y;
		y = y%x;
		if(!y) y = x;

		y = ceil(y*1.0/a*1.0) - 1;
		if(y)
			pq.push(y);
		else
			count++;
	}
	while(pq.size())
	{
		int rem = pq.top();
		pq.pop();
		k -= rem;
		if( k < 0)
			break;
		count ++;
	}
	cout << count << endl;
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