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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.ss-a.ff>b.ss-b.ff;
}
void solve(ll tt)
{
    // In first half if there is i , i then in second half there will be a j, j 
    // and in the first half if there is i, j (only one) then in the second half there will be a j, i (only one
    
    ll n, k; 
    cin>>n>>k;
    ll arr[2*n]; 

    for (int i=0; i<2*n; i++)
        cin>>arr[i]; 

    vector<int> mark(n+1, 0); 
    // mark[i] = 2 means in first half there is i, i
    // mark[i] = -2 means in search half there is i, i
    // mark[i] = 0 means there is one i in first half and one i in second half

    for (int i=0; i<n; i++)
    {
        mark[arr[i]]++;
    }

    for (int i=n; i<2*n; i++)
    {
        mark[arr[i]]--;
    }

    vector<int> two_in_left; 
    vector<int> two_in_right;
    vector<int> one_one_in_left_right; 

    for (int i=1; i<=n; i++)
    {
        if (mark[i] == 2)
            two_in_left.pb(i); 
        else if (mark[i] == -2)
            two_in_right.pb(i); 
        else if (mark[i] == 0)
            one_one_in_left_right.pb(i); 
    }

    vector<int> left, right;

    while(left.size()<2*k)
    {
        if (two_in_left.size() > 0 and two_in_right.size() > 0)
        {
            left.pb(two_in_left.back());
            left.pb(two_in_left.back());
            two_in_left.pop_back();

            right.pb(two_in_right.back());
            right.pb(two_in_right.back());
            two_in_right.pop_back();
        }

        else if (one_one_in_left_right.size() > 0)
        {
            left.pb(one_one_in_left_right.back());
            right.pb(one_one_in_left_right.back());
            one_one_in_left_right.pop_back();
        }   
    }

    for (int i=0; i<left.size(); i++)
    {
        cout<<left[i]<<gap;
    }
    cout<<endl;
    for (int i=0; i<right.size(); i++)
    {
        cout<<right[i]<<gap;
    }
    cout<<endl;
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
