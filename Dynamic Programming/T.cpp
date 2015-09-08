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
#define REP(i, n) for(int i=0; i<n; ++i)
#define MEM(array) memset(array, -1, sizeof(array))
#define CLR(array) memset(array, 0, sizeof(array))
#define all(v) v.begin(), v.end()
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b)
#define siii(a,b,c) scanf("%d%d%d",&a,&b,&c)


template <class T> inline T imax(T &a,T b){if(b>a) a=b;}
template <class T> inline T imin(T &a,T b){if(b<a) a=b;}

const int MAX = 1e3 + 1;
const ll MAXINT = 1e18;
const int INF = 1e8;

int t, n, m, caseno = 0, a, b, c, d, q, sumtime;
int ar[MAX][MAX];
int dp1[MAX][MAX], dp2[MAX][MAX], dp3[MAX][MAX], dp4[MAX][MAX];


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    sii(n, m);
    REP(i, n) REP(j, m) si(ar[i+1][j+1]);

    //1,1 to i,j
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
                dp1[i][j] = ar[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);

    //n,1 to i,j
    for (int i=n; i>=1; --i)
        for (int j=1; j<=m; ++j)
                dp2[i][j] = ar[i][j] + max(dp2[i + 1][j], dp2[i][j - 1]);

    //1,m to i,j
    for (int i=1; i<=n; ++i)
        for (int j=m; j>=1; --j)
                dp3[i][j] = ar[i][j] + max(dp3[i - 1][j], dp3[i][j + 1]);

    //n,m to i,j
    for (int i=n; i>=1; --i)
        for (int j=m; j>=1; --j)
                dp4[i][j] = ar[i][j] + max(dp4[i + 1][j], dp4[i][j + 1]);

    int ans = 0;
    for (int i=2; i<n; ++i)
        for (int j=2; j<m; ++j){

                imax(ans, dp1[i][j - 1] + dp2[i + 1][j] + dp3[i - 1][j] + dp4[i][j + 1]);
                imax(ans, dp1[i - 1][j] + dp2[i][j - 1] + dp3[i][j + 1] + dp4[i + 1][j]);

    }

    cout << ans;


    return 0;
}
