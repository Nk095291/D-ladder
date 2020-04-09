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
The first case is when this block has odd length. Then it seems like "XXXXXXX".
 So, what is the minimum number of recolors we need to make this block correct? 
 It is ⌊𝑙𝑒𝑛2⌋. Why can we always make this block correct for such number of recolors?
  Because we can recolor all 'X' at even positions to any 'Y' which differs from 'X'. 
  So our block will be look like "XYXYXYX".

The second case is when this block has even length. 
Then it seems like "XXXXYYY ... YYY" where 'Y' is the next block letter (if the next block exists, because the last block doesn't have the next one). 
What is the minimum number of recolors in this case? It is 𝑙𝑒𝑛2. 
How can we recolor this block to make it correct? 
Let's recolor all 'X' at even positions (again) to any 'Z' which differs from 'X' and differs from 'Y'. 
So our block will be look like "XZXZYYY ... YYY".
*/
void solve()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int count =0;
	for(int i =0 ; i< n  -1 ; i++)
	{
		if( str[i] != str[i +1])	 continue;

			count ++;
		if( i + 2 >= n || str[i + 2] == str[i])
			str[i + 1] = str[i] == 'R' ? 'B': 'R';
		else 
		{
			if( str[i] == 'R')
			{
				str[i + 1] = str[i + 2] == 'G' ? 'B' : 'G';
			}

			else if( str[i] == 'G')
			{
				str[i + 1] = str[i + 2] == 'R' ? 'B' : 'R';
			}

			else
			{
				str[i + 1] = str[i + 2] == 'R' ? 'G' : 'R';
			}
		}

	}
	cout<< count << endl;
	cout << str << endl;
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

// editorial code beautiful af.
/* 
#include <bits/stdc++.h>

using namespace std;

int main() {	
	int n;
	string s;
	cin >> n >> s;
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int j = i;
		while (j < n && s[i] == s[j]) {
			++j;
		}
		string q = "RGB";
		q.erase(q.find(s[i]), 1);					// deleting 'X' int from the q
		if (j < n) q.erase(q.find(s[j]), 1);			// deleting 'Y' from the q
		for (int k = i + 1; k < j; k += 2) {
			++ans;
			s[k] = q[0];							// coloring every second element with 'Z'
		}
		i = j - 1;							// shifting i from *XXXXXYYY to XXX*YYYY		(* = i)
	}
	
	cout << ans << endl << s << endl;
	
	return 0;
}
*/