#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for (ll i = 0; i < n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        ll ans=(a[n-1]-a[0])*a[n-2];
        cout<<ans<<endl;
    }
}