#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define pb          push_back
#define mp          make_pair
#define mt          make_tuple
#define ff          first
#define ss          second
#define pii         pair<int,int>
#define vi          vector<int>
#define vpii        vector<pii>
#define mii         map<int,int>
#define ump         unordered_map
#define ll          long long
#define pqb         priority_queue<int>
#define pqs         priority_queue<int, vi,greater<int>>
#define setbits(x)  __buitin_popcountll(x)
#define inf         1e9
#define ps(x,y)     fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n]
#define range(a,b)  substr(a,b-a+1)
#define w(x)        int x; cin>>x; while(x--)
#define trace(x)    cerr<<#x<<": "<<x<<" "<<endl;
#define FI0         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define mid(l,f)    l+(f-l)/2
#define loop(i,a,b) for (int i=(a); i<=(b);i++)
#define rep(i,a,b)  for (int i=(a); i<(b);i++)
#define reprev(i,a,b) for (int i=(a); i>=(b); i--)
#define looprev(i,a,b) for (int i=(a); i>=(b); i--)
#define gap ' '
#define lld long long double
const double PI=3.1415926535893238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define loop(i,a,b) for (int i=(a); i<=(b);i++)
#define ceil(x,y)       (x + y - 1)/y
//#define N 101*2
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);


void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("text.txt", "r", stdin);
#endif // ONLINE_JUDGE
}

void flagprint(bool flag)
{
    if (flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}


void solve(ll tt)
{

    //try to make equal
    int a, b, c;
    cin>>a>>b>>c;

    for (int i=0; i<5; i++)
    {

        if (a<=b and a<=c)
            a++;
        else if (b<=c and b<=a)
            b++;
        else
            c++;
    }
    cout<< a*b*c<<endl;

}
int main()
{
    // freopen("text.txt", "r", stdin);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    file_i_o();

    ll t=1;
    cin>>t;



    for(int i=1; i<=t; i++)
    {
        //cout<<"CASE is "<<i<<endl;
        solve(i);
    }
}
