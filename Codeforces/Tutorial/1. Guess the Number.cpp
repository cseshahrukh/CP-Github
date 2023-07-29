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

void flagprint(bool flag)
{
    if (flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.ss-a.ff>b.ss-b.ff;
}
void solve(ll tt)
{
    /*
        if solution is x=1
        and l=1 and r=2 then infinite while loop

        for this reason mid=(l+r+1)/2 instead of mid=(l+r)/2
    */
    ll l=1, r=1000000;
    //printf("Hehe\n");

    string response;
    while(l<r)
    {
        ll mid=(l+r+1)/2;

        //Without \n can be an serious issue in interactive problem
        printf("%lld\n", mid);
        fflush(stdout);

        cin>>response;

        if(response=="<")
        {
            r=mid-1;
        }

        else
        {
            l=mid;
        }

    }

    printf("! %lld", l);
    fflush(stdout);
    return;

}

int main()
{

    ll t=1;
    //cin>>t;

    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}
