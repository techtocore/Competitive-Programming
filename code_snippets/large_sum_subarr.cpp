#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define fr(i,a,b) for(ll int i=a;i<b;i++)
#define vsort(v) sort(v.begin(),v.end())
#define whl(t) while(t--)
#define vuni(vec) vec.erase( unique( vec.begin(), vec.end() ), vec.end() )

using namespace std;
//akashravi.tk



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll int t,ct,n,r,f;
	vector<ll int> a;
    cin>>t;
    whl(t)
    {
        cin>>n;
        a.clear();
        fr(i,0,n)
        {
            cin>>r;
            a.pb(r);
        }
         ll max_so_far = a[0];
   ll curr_max = a[0];

   for (ll i = 1; i < n; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   cout<< max_so_far<<"\n";
    }
    //cout<<"\n";

    return 0;
}
