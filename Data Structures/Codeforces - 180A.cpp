
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
#define sz size()
#define ll long long
#define FOR(i, k, n) for(int i=(int) k ; i<(int)n; ++i)
#define MEM(array, value) memset(array, value, sizeof(array))
#define all(v) v.begin(), v.end()
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b)
#define siii(a,b,c) scanf("%d%d%d",&a,&b,&c)



template <class T> inline T imax(T a,T b){return (a>b)?a:b;}
template <class T> inline T imin(T a,T b){return (a<b)?a:b;}

const int MAX = 500 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d, mod;
int dp[MAX][MAX][MAX];
int ar[MAX];

int solve(int idx, int line, int bug)
{
    if(line > m) return 0;
    if(idx == n) return 0;
    if(bug > b) return 0;

    int &ret = dp[idx][line][bug];
    if(ret != -1) return ret;
    if(line == m) return ret = 1;

    ret = 0;
    ret += solve(idx, line + 1, bug + ar[idx]) + solve(idx + 1, line, bug);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    MEM(dp, -1);
    cin >> n >> m >> b >> mod;
    FOR(i, 0, n) cin >> ar[i];

    cout << solve(0, 0, 0) % mod;

    return 0;
}
