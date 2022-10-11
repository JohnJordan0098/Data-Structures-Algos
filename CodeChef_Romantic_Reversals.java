#include <bits/stdc++.h>
using namespace std;



void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string ans="";
    int  it1=(k/2),it2=(k/2)-1;
    if(k%2==1)
    {
        cout<<s[it1];
        it1++;
    }
    for(int i=0;i<k/2;i++)
    {
         cout<<s[it1];
        cout<<s[it2];
        it2--;
        it1++;
    }
    cout<<ans;
    for(int i=k;i<n;i++)
    {
        cout<<s[i];
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}