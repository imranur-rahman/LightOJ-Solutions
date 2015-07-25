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

#define ok(i,j) (i>=0 && i<n && j>=0 && j<n)

template <class T> inline T imax(T a,T b){return (a>b)?a:b;}
template <class T> inline T imin(T a,T b){return (a<b)?a:b;}

const int MAX = 1e3 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int dp[MAX];
int ar[MAX];

int n, x, t, caseno = 0;

int main()
{
    si(t);
    while(t--){

            si(n);
            FOR(i, 0, n){
                si(x);
                //cnt[x]++;
                ar[i] = x;
                //cnt[x] += x;
            }

            MEM(dp, 0);
            dp[0] = 0;
            dp[1] = ar[1];
            FOR(i, 2, n + 1){

                    dp[i] = max(dp[i-1], dp[i-2] + ar[i]);

            }

            int m = dp[n];

            MEM(dp, 0);
            dp[0] = 0;
            dp[1] = ar[0];
            FOR(i, 2, n){

                    dp[i] = max(dp[i-1], dp[i-2] + ar[i-1]);

            }

            m = max(m, dp[n - 1]);


            printf("Case %d: %d\n", ++caseno, m);
    }
    return 0;
}
