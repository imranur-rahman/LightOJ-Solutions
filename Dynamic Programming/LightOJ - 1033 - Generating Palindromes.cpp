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
#define MEM(array) memset(array, -1, sizeof(array))
#define CLR(array) memset(array, 0, sizeof(array))
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

char ar[201];
int dp[MAX][MAX];

int solve(int i, int j)
{
    if(i>j) return 0;
    if(i==j) return 1;

    int &ret = dp[i][j];
    if(ret != -1) return ret;

    if(ar[i] == ar[j])
        ret = max(ret, 2 + solve(i+1, j-1));
    else{
        int ans = max(solve(i+1, j), solve(i, j-1));
        ans = max(ans, solve(i+1, j-1));
        ret = max(ret, ans);
    }

    return ret;
}

int main()
{
    //ios_base::sync_with_stdio(false);

    si(t);
    while(t--){

            getchar();
            gets(ar);
            MEM(dp);
            int ans = solve(0, strlen(ar) - 1);
            printf("Case %d: %d\n", ++caseno, strlen(ar) - ans);
    }

    return 0;
}
