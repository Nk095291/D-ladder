#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
int p = 31;
int m = 1e9  + 9;
vector<int> hash1 , hash2 ,ppow;
/*
This problem can be solved in many ways, but the simplest approach is as follows:
 we find all the divisors of the string s 1 , all the divisors of s 2 and find the intersection of these two sets.

How to find all line dividers? Let t be the divisor of the string s .
Then it is obvious that | s | = 0 ( mod | t |) , and also t is the prefix of the string s . 
These considerations make it possible to find all line divisors, namely, we sort through the length of the prefix, check the divisibility, 
and then check that the prefix recorded in a row the necessary number of times matches s .

There are no more suitable prefixes in total , checking each works for O (| s |) , 
which means that the final solution is for , where n  =  max (| s |, | t |) .

Finding the intersection of two sets of rows is easy; you can use standard data structures
*/

void init (string & s1, string & s2)
{
    int n = s2.size();
    ppow.clear(); ppow.resize(n);
    hash1.clear() ; hash1.resize(s1.size()+ 1);
    hash2.clear() ; hash2.resize(n + 1);
    ppow[0] = 1;

    for(int i =1 ; i<n ; i++)
    {
        ppow[i] = (ppow[i-1] * p )%m;
    }
    for(int i =0 ; i <n;  i++)
    {
        hash2[i + 1] = (hash2[i]  + (s2[i] - 'a' + 1) * ppow[i]) % m;
    }
      for(int i =0 ; i <s1.size();  i++)
    {
        hash1[i + 1] = (hash1[i]  + (s1[i] - 'a' + 1) * ppow[i]) % m;
    }
}

bool check(string &s1, string &s2,  string c)   // instead of taking O(n) in comparing two string ,    where n = max(n1, n2)
                                                // i cam simple use hash function to do the comparision in just O(time)     (where time = (n2/n3))
{
    int n1 = s1.size();
    int n2 = s2.size();
    int n3 = c.size();
    if( n1 % n3 !=0 || n2 % n3 != 0)
        return false;
    int h = 0;
    for(int i =0 ; i< n3; i++)
    {
         h = (h + (c[i] - 'a' + 1) * ppow[i]) % m; 
    }
    for(int i = n3 ; i<= n1; i += n3)
    {
        int cur = (hash1[i] - hash1[i - n3] + m) % m;
        if( cur != (h * ppow[i - n3]) % m)
            return false;
    }

    for(int i = n3 ; i<= n2; i += n3)
    {
        int cur = (hash2[i] - hash2[i - n3] + m) % m;
        if( cur != (h * ppow[i - n3]) % m)
            return false;
    }
    return true;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2 ;
    if( s1.size() > s2.size())
    {
        swap(s1, s2);
    }
    string res = "";
    int count = 0;
    init(s1, s2);
    for(int i =0 ; i< s1.size() ;i++)
    {
        res += s1[i];
        // cout<< res ;
        bool t = check(s1, s2, res);
        // cout << " " << t << endl;
        if( t)
            count ++;
    }
    cout<< count << endl;

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


// good solution
/*
author - koblyk
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    if (n > m)
    {
        swap(s1, s2);
        swap(n, m);
    }
    string t1, t2;
    int ans = 0;
    for (int i=0; i<n; i++)
    {
        t1 += s1[i];
        if (n % (i+1) != 0 || m % (i+1) != 0)
            continue;
        t2.clear();
        for (int j=0; j<n/(i+1); j++)
            t2 += t1;
        if (t2 != s1)
            continue;
        for (int j=0; j<(m-n)/(i+1); j++)
            t2 += t1;
        if (t2 != s2)
            continue;
        ans++;
    }
    cout << ans;
    return 0;
} 
*/