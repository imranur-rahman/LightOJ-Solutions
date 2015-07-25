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


const int MAX = 100 + 1;
const ll MAXINT = 1e18;
const int mod = 1e8 + 7;

int coin[MAX];
int way[10001];
int caseno = 0, n, k;

void printdp()
{
    FOR(i, 0, k+1)
        cout << way[i] << " ";
    cout << endl;
}

int solve()
{
    way[0] = 1;

    FOR(i, 0, n){
        //printdp();
        FOR(j, coin[i], k+1){
            //printdp();
            //if(coin[i] <= j){
                way[j] += way[j - coin[i]];
                if(way[j] > mod)
                    way[j] = way[j] % mod;
            //}
        }
    }

    return way[k] % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> n >> k;

        MEM(way, 0);
        FOR(i, 0, n)
            cin >> coin[i];

        printf("Case %d: %d\n", ++caseno, solve());
        //printdp();
    }
    return 0;
}
