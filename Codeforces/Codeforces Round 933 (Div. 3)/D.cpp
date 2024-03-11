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
void solve(ll tt) {
    int total_players, total_throws, initial_player_position; 
    cin >> total_players >> total_throws >> initial_player_position; 
    initial_player_position--; // 0 based indexing

    char ch; 

    int directions[total_throws]; // -1 means unknown
    int distances[total_throws]; // 

    for(int i = 0; i < total_throws; i++) {
        cin >> distances[i];
        cin >> ch;
        if (ch == '0')
            directions[i] = 0;
        else if (ch == '1')
            directions[i] = 1;
        else
            directions[i] = -1;
    }

    set<int> final_playerindex; // Use set instead of vector

    final_playerindex.insert(initial_player_position); // Insert initial position
    
    int add_position = 0; 
    for(int i = 0; i < total_throws; i++) {
        if (directions[i] != -1) {
            if (directions[i] == 0)
                add_position = (add_position + distances[i]) % total_players;
            else
                add_position = (add_position - distances[i]) % total_players;
        }
        else {
            // Create a temporary set to hold new positions
            set<int> temp;
            for (auto index : final_playerindex) {
                temp.insert((index + distances[i])%total_players);
                temp.insert((index - distances[i])%total_players); 
            }
            final_playerindex.clear(); // Clear final_playerindex
            final_playerindex = temp; // Update final_playerindex with new positions
            // cout<<"in iteration "<<i<<" final_playerindex is "<<final_playerindex.size()<<endl;
            // for (auto index : final_playerindex) {
            //     cout<<index<<gap;
            // }
            // cout<<endl;
        }
    }
    //cout<<"add_position is "<<add_position<<endl;

    set<int> res; 
    for(auto index : final_playerindex) {
       index = ((index + add_position) % total_players) + 1; 
       if (index <= 0) {
           index += total_players;
       }
       //cout<<"before inserting index is "<<index<<endl;
        res.insert(index);
    }

    cout << res.size() << endl;

    for(auto i : res) {
        cout << i << gap;
    }
    cout << endl;
}

int main()
{
    //cout<<"Before fileio"<<endl;
    //freopen("text.txt", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    file_i_o();

    //cout<<"after fileio"<<endl;
    ll t=1;
    cin>>t;



    for(int i=1; i<=t; i++)
    {
        //cout<<"CASE is "<<i<<endl;
        solve(i);
    }
}
