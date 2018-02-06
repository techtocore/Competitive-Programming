#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ms(a,b) memset(a,b,sizeof(a))
#define fr(i,a,b) for(long long int i=a;i<b;i++)
#define vsort(v) sort(v.begin(),v.end())
#define whl(t) while(t--)
#define vuni(vec) vec.erase( unique( vec.begin(), vec.end() ), vec.end() )
#define mod 1000000007

using namespace std;
//akashravi.tk

typedef long long ll;

void fscpp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


vector<complex<double> > fft(vector<complex<double> > p, ll n, complex<double> w)
{
    if(n==1) return p;
    vector<complex<double> > a1,a2;
    for(ll i=0;i<n/2;i++)
    {
        a1.pb(p[i*2]);
        a2.pb(p[i*2+1]);
    }
    vector<complex<double> > q = fft(a1,n/2,w*w);
    vector<complex<double> > r = fft(a2,n/2,w*w);
    //vector<complex<double> > w;
    complex<double> h=1;
    fr(i,0,n/2)
    {
        p[i] = q[i]+h*r[i];
        p[i+n/2] = q[i]-h*r[i];
        h*=w;
    }
    return p;

}

vector<complex<double> > ifft(vector<complex<double> > p, ll n, complex<double> w)
{
    p=fft(p,n,(complex<double>)(1)/w);
    fr(i,0,n)
    p[i]/=((complex<double>)(n));
    return p;
}


int main()
{
    fscpp();
    // enter the input polinomial's coeff in a
    vector<complex<double> > a = {1,1,2,3}, b,c;
   // ll n=2;
    ll n=4;
    complex<double>  w;
    //fr(i,0,n)
    {
        double a = (2*M_PI)/n;
        w=complex<double>(cos(a),sin(a));
    }

    b=fft(a,n,w);

    fr(i,0,n)
    cout<<b[i]<<endl;

    cout<<endl;

    c=ifft(b,n,w);
    fr(i,0,n)
    cout<<c[i]<<endl;



    //cout<<"\n";

    return 0;
}
