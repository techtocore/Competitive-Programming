#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ms(a,b) memset(a,b,sizeof(a))
#define fr(i,a,b) for(long long int i=a;i<b;i++)
#define vsort(v) sort(v.begin(),v.end())
#define whl(t) while(t--)
#define vuni(vec) vec.erase( unique( vec.begin(), vec.end() ), vec.end() )
#define parr(a,n) fr(i,0,n){ cout<<a[i]<<" "; } cout<<"\n";
#define mod 1000000007

using namespace std;
//akashravi.tk

//http://www.spoj.com/problems/FENTREE/

typedef long long ll;

void fscpp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<ll> a;
ll n;

void update(ll pos, ll val)
{
    while(pos<=n)
    {
        a[pos] += val;
        pos += (pos & (-pos));
    }
}

ll querry(int pos)
{
    ll sum = 0;
    while(pos>0)
    {
        sum += a[pos];
        pos -= (pos & (-pos));
    }
    return sum;
}

int main()
{
  fscpp();
  ll q,l,r,f,k;
  char p;
  cin>>n;
  ll b[n+1];
  fr(i,0,n)
  {
      cin>>b[i];
      a.pb(0);
  }
  a.pb(0);
  fr(i,0,n)
  {
      update(i+1,b[i]);
  }
  cin>>q;
  whl(q)
  {
      cin>>p>>l>>r;
      if(p == 'q')
      {
          f = querry(r);
          k = querry(l-1);
          cout<<f-k<<"\n";
      }
      else
      {
          update(l,r);
      }

  }
  
  
  return 0;
}

