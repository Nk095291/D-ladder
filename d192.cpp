#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);


// Header files, namespaces, 
// macros as defined above 

  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
/*


find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.
To find the first element k must be zero.

Let us assume we have a set s : {1, 5, 6, 17, 88}, then :

*(s.find_by_order(2)) : 3rd element in the set i.e. 6
*(s.find_by_order(4)) : 5th element in the set i.e. 88

order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :

s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.

*/



/*

solution link - https://codeforces.com/blog/entry/71740


*/

void solve()
{
    int n ;
    cin >> n;
    vector<int> org(n);
    vector<pair<int, int>> ar(n);
    for(int i =0 ; i< n; i++)
    {
        cin >>org[i];
        ar[i] = {-org[i], i};
    }
    sort(ar.begin(), ar.end());

    int m ;
    cin >> m;
    vector<pair<int, pair<int, int> > > query(m);
    for(int i=0 ; i<m ; i++)
    {
        int a, b;
        cin >> a  >> b;
        query[i] = {a, {b, i}};
    }
    sort(query.begin(), query.end());


    vector<int> res(m);
    int len =0;
    ordered_set st;
    for(int i =0 ; i< query.size(); i++)
    {
        while(query[i].first > len)
        {
            st.insert(ar[len++].second);
        }
        res[query[i].second.second] = org[*(st.find_by_order(query[i].second.first -1))]; 
    }
    for(auto x: res)
        cout<< x <<endl;
    
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