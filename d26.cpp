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
Find the shortest substring of each string such that it doesn't appear in any other string as a substring. For each substring let's store the index of the string which contains this substring or  - 1 if there are more than one such string. Iterate over all substrings which have values that are not  - 1 and update the answer for the corresponding string.
*/
map<string ,int >mp;
void fill(vector<string> &ar)
{
    int n = ar.size();
    for(int i =0 ;i < n; i++)
    {
        set<string> st;
        for(int j =1 ; j<=10; j++)
        {
            string s = ar[i].substr(0,j);
            st.insert(s);
            for(int k  = j; k<9; k++)
            {

                s.erase(s.begin());
                s.push_back(ar[i][k]);
                st.insert(s);
            }
        }
        for(auto x: st)
            mp[x]++;
    }
}
pair<string, int> check(int len , string & str)
{
    
    string x = str.substr(0, len);
    if(mp[x] == 1)
    {
        return {x, true};
    }
    for(int k = len ; k < 10; k++)
    {
        x.erase(x.begin());
        x.push_back(str[k]);
        if(mp[x] == 1)
        {
            return {x, 1};
        }
    }
    return {"", false};
}
void solve()
{
    int n;
    cin >> n;
    vector<string > ar(n);
    for(int i =0 ;i< n ; i++)
    {
        cin >> ar[i];
    }
    fill(ar);


    for(int i=0 ; i<n ;i++)
    {
        int l = 1;
        int r = 10;
        string res =ar[i];
        while(l <= r)
        {
            int mid = (l +r)/2;
            pair<string, bool > cur = check(mid, ar[i]);
            if(cur.second)
            {
                res =  cur.first;
                r = mid -1;
            }
            else
            {
                l = mid +1;
            }
            
        }
        cout<< res << endl;
    }
}



int32_t main(){
	// fast;       
   solve();              
}