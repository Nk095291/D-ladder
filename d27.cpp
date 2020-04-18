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
    int n , k , m;
    cin >> n >> m >> k;
    vector<int> ar(n);
    for(int i =0 ; i< n; i++)
    {
        cin >> ar[i];
    } 
    sort(ar.begin(), ar.end());

    int i = 0;
    int j = k -1;
    int res =0;
    while(j < n)
    {
        while( j < n && ar[j] < ar[i] + m)      // if there are k alarms within m range then remove the kth alarm
        {
            ar[j] = -1;
            if(i == j)                  // if k == 1
                i++;
            j ++;
            res ++;
        }

        while(i+1  < n && ar[i+1] == -1)    // to prevent from going to the removed alarms
        {
            i++;
        }
        i++;
        j++;
    }
    cout << res << endl;
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
   solve();              
}