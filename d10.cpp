#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);

int toInt(string &str, int i )
{
	if(i == -1) return 0;
	return (str[i] - '0') + toInt(str, i -1)* 10;
}


pair<int , pair<int, int >> getcab (string &str)
{
	int n = str.size();
	int plus = find( str.begin() , str.end(), '+') - str.begin();
	int secondparenthesis = find(str.begin()+1, str.end(), ')') - str.begin();
	int slash  = find(str.begin(), str.end(), '/') - str. begin();

	string a = str.substr(1, plus -1);
	string b = str.substr(plus +  1, secondparenthesis - plus - 1);
	string c = str.substr(slash +1, n - slash -1);
	// cout<< a <<  "  " << b << " " << c << endl;
	int p  =1;
	return {toInt(c,c.size() -1), {toInt(a, a.size() -1), toInt(b, b.size() -1)}};
}
void solve()
{
	int n ;
	cin >>n;
	map<float, int>mp;
	vector<float> ar(n);
	for(int i =0 ; i< n ;i++)
	{
		string str;
		cin >> str ;
		pair<int, pair<int , int > > cab = getcab(str);
		ar[i] = (cab.second.first*1.0 + cab.second.second*1.0) / cab.first*1.0;
		mp[ar[i]]++;
		// cout << ar[i] <<endl;
	}

	for(auto x : ar)
		cout << mp[x] << " ";
	cout << endl;
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