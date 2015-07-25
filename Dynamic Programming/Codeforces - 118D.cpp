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

const int MAX = 100 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;

int MOD = 1e8;
int n1, n2, k1, k2;
int dp[MAX][MAX][12][12];

// line means how many consecutive man we put in this line

int solve(int n1, int n2, int line1, int line2)
{
    if(n1<0 || n2<0) return 0;
    int &ret = dp[n1][n2][line1][line2];
    if(ret != -1) return ret;

    if(k1<line1 || k2<line2) return ret = 0;
    if(n1==0 && n2==0) return ret = 1; // we got "one" way

    return ret = (solve(n1-1, n2, line1+1, 0) + solve(n1, n2-1, 0, line2+1)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);

    MEM(dp, -1);
    cin >> n1 >> n2 >> k1 >> k2;
    cout << solve(n1, n2, 0, 0);

    return 0;
}
