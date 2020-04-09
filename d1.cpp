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
    int n ;
    cin >> n ;
    vector<int> ar(n);
    for(int i =0 ; i<n ;i++)
    {
        cin >> ar[i];
    }
    vector<int> price(5);
    vector<int> res(5);
    for(int i=0 ; i<5; i++)
    {
        cin >> price[i];
    }
    int sum =0;
    for(int i =0 ; i<n ; i++)
    {
        sum += ar[i];
        auto it =upper_bound(price.begin(), price.end(), sum); 
        while( it != price.begin())
        {
            int index = (it - price.begin()) -1 ;
            if(index == 4)
            {
                int times = (sum/price[index]);
                res[index] += times;
                sum -= price[index]*times;
            }
            else
            {
                res[index]++;
                sum -= price[index];
            }
            it =upper_bound(price.begin(), price.end(), sum); 
        }
    }
    for(auto x: res)
        cout<< x << " ";
    cout<< endl;
    cout<< sum <<endl;


    
}
void better_solve()
{
    int n ;
    cin >> n ;
    vector<int> ar(n);
    for(int i =0 ; i<n ; i++)
        cin >> ar[i];
    vector<int> price(5), res(5);
    for(int i = 0; i<5; i++)
    {
        cin >> price[i];

    }
    int sum =0;
    for(int i =0 ; i<n; i++)
    {
        sum += ar[i];
        for(int j = 4; j >=0; j--)
        {
            int times = sum / price[j];
            res[j] += times;
            sum -= times* price[j];
        }

    }
    for(auto x : res)
        cout<< x << " ";
    cout<< endl;
    cout << sum << endl;
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
//    solve(); 
    better_solve();             
}