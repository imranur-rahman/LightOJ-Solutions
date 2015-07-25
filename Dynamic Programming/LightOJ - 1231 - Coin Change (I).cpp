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

template <class T> inline T imax(T a,T b){return (a>b)?a:b;}
template <class T> inline T imin(T a,T b){return (a<b)?a:b;}


const int MAX = 50 + 1;
const ll MAXINT = 1e18;
const int mod = 1e8 + 7;

int coin[MAX], numberOfCoins[MAX];
ll dp[MAX][1001];
int caseno = 0, n, k;

void printdp()
{
    FOR(i, 0, n){
        FOR(j, 0, k)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

ll solve(int coinIndex, int make)
{
    if(make == 0) return 1; // have to remember this carefully, even if coinIndex is equal to n and make is equal to
    if(make < 0  or  coinIndex >= n) return 0;

    if(dp[coinIndex][make] != -1) return dp[coinIndex][make];

    //printf("coinIndex: %d  make: %d\n", coinIndex, make);

    ll ans = 0;
    FOR(i, 0, numberOfCoins[coinIndex] + 1){
        //printf("coinIndex: %d  make: %d\n", coinIndex + 1, make - i * coin[coinIndex]);
        ans += solve(coinIndex + 1, make - i * coin[coinIndex]) % mod;

    }

    return dp[coinIndex][make] = ans % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> n >> k;

        MEM(dp, -1);
        FOR(i, 0, n)
            cin >> coin[i];
        FOR(i, 0, n)
            cin >> numberOfCoins[i];

        printf("Case %d: %d\n", ++caseno, solve(0, k));
        printdp();
    }
    return 0;
}
