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

const int MAX = 1e5 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;
int ar[MAX];
int dp[MAX];

int contagious(int i, int sum)
{
    if(i == n) return sum;

    int &ret = dp[i];
    if(ret != -INF) return ret;

    int ans1 = 0, ans2 = 0;
    ans1 = contagious(i+1, sum+ar[i]);
    ans2 = contagious(i+1, ar[i]);

    ret = ar[i];

    return ret = max(max(ans1, ans2), ret);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        FOR(i, 0, n) cin >> ar[i];
        FOR(i, 0, MAX) dp[i] = -INF;
        cout << contagious(0, 0) << endl;
    }
    return 0;
}
