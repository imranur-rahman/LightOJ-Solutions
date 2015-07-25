#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair
#define ll long long
#define FOR(i, n) for(int i=0; i<(int)n; ++i)
#define MEM(array, value) memset(array, value, sizeof(array))

template <class T> inline T imax(T a,T b){return (a>b)?a:b;}

const int MAX = 10000 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int n, ar[3];
int dp[4001];

int solve(int n)
{
    if(n == 0) return 0;
    if(n < 0) return -INF;
    if(dp[n] != -1) return dp[n];

    int ans = -INF;
    FOR(i,3){
        ans = max(ans, 1 + solve(n - ar[i]));
    }
    return dp[n] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    FOR(i,3) cin >> ar[i];
    MEM(dp, -1);

    cout << solve(n);
    return 0;
}
