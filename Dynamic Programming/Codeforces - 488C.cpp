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

int t, n, m, caseno = 0, a, b, c, d;
int ar[MAX];

int solve(int l, int r)
{
    if(l > r) return 0;
    if(l == r) return 1;

    int mn = INF;
    FOR(i, l, r+1) mn = min(mn, ar[i]);
    int res = mn;
    FOR(i, l, r+1) ar[i] -= mn;

    int last = l - 1;
    FOR(i, l, r+1){
            if(ar[i] == 0){
                    res += solve(last + 1, i - 1);
                    last = i;
            }
    }

    res += solve(last + 1, r);
    return res = min(res, r - l + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    FOR(i, 0, n) cin >> ar[i];
    cout << solve(0, n-1);
    return 0;
}
