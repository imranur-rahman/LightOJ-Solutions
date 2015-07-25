#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define FOR(i, k, n) for(int i=(int) k ; i<(int)n; ++i)
#define MEM(array, value) memset(array, value, sizeof(array))

template <class T> inline T imax(T a,T b){return (a>b)?a:b;}
template <class T> inline T imin(T a,T b){return (a<b)?a:b;}

const int MAX = 1e5 + 1;
const ll MAXINT = 1e18;
const ll mod = 1e9+7;

int t, n, m, q, a, b;

ll dp[MAX], ar[MAX];

void update(int idx, int value = 0)
{
    while(idx<=n)
    {
        cout << idx << endl;
        idx += (idx & -idx);

    }
}

int sum(int idx)
{
    int ret = 0;
    while(idx>0)
    {
        cout << idx << endl;
        idx -= (idx & -idx);

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //while(t--){
        //int n;
        cin >> n >> m;
        while(m--){
            cin >> a;
            //cout << "update:" << endl;
            //update(a);
            cout << "sum:" << endl;
            sum(a);
        }

        //cout << solve(0, 0) << endl;
    //}As

    return 0;
}
