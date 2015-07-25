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

const int MAX = 5000 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d, w, h;
pair<pii, int>ar[MAX];
int dp[MAX], parent[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> w >> h;
    FOR(i, 0, n){
            cin >> ar[i].ff.ff >> ar[i].ff.ss;
            ar[i].ss = i;
    }
    sort(ar+1, ar+n);

    dp[0] = 0;
    FOR(i, 0, n){
            //if(w > ar[i].ff.ff  ||  h > ar[i].ff.ss) continue;
            int p = ar[i].ss;
            if(!p) continue;
            dp[p] = -INF;

            FOR(j, 0, i){

                    if(ar[i].ff.ff > ar[j].ff.ff  &&  ar[i].ff.ss > ar[j].ff.ss  &&  dp[j] + 1 < dp[i]){

                            dp[i] = dp[j] + 1;
                            parent[i] = j;
                    }
            }
    }

    int pos = 0;
    FOR(i, 0, n){
            if(dp[pos] < dp[i])
                pos = i;
    }

    vi result;
    while(pos != 0){
            result.pb(ar[pos].ss);
            pos = parent[pos];
    }

    cout << result.sz << endl;
    for(int i = result.sz - 1; i >= 0; --i){
            cout << result[i] << " ";
    }

    return 0;
}
