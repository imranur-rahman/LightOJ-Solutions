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

const int MAX = 1e5 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;

int dp[MAX][2]; // 0 -> left, 1 -> right
int W[MAX], H[MAX];

int solve(int pos, bool t)
{
    if(pos == n) return 0;
    if(pos == n-1) return 1;

    int &ret = dp[pos][t];
    if(ret != -1) return ret;

    ll last = W[pos - 1];
    if(t) last += H[pos - 1]; // right e felchi

    int ans = 0;

    /*if(W[pos] - H[pos] > last)
        ans = max(ans, 1 + solve(pos + 1, 0));
    else */if(W[pos] + H[pos] < W[pos + 1])
        ans = max(ans, 1 + solve(pos + 1, 1));

    ans = max(ans, solve(pos + 1, 0));
    return ret = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    FOR(i, 0, n) cin >> W[i] >> H[i];
    MEM(dp, -1);
    cout << solve(1, 0) + 1;

    return 0;
}
