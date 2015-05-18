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

const int MAX = 100 + 1;
const ll MAXINT = 1e18;
int t, caseno = 0, n, r, a, b, traverse = 0, s, e;

vi ar[MAX];
int level[MAX];
int max_depth = 0;

void dfs(int a, int prev_level)
{
    level[a] = prev_level + 1;
    max_depth = imax(max_depth, level[a]);

    FOR(i, 0, ar[a].sz){
        if(level[ar[a][i]] == -1)
            dfs(ar[a][i], level[a]);
    }

}

int main()
{
    cin >> t;
    while(t--){
        cin >> n >> r;

        FOR(i, 0, n){
            ar[n].clear();
        }
        MEM(level, -1);

        traverse = 0;
        max_depth = 0;

        FOR(i, 0, r){
            cin >> a >> b;
            ar[a].pb(b);
            ar[b].pb(a);
            traverse++;
        }

        cin >> s >> e;

        /*FOR(i, 0, n){
            if(level[i] == -1)
                dfs(i, -1);
        }*/
        dfs(s, -1);

        printf("Case %d: %d\n", ++caseno, level[e]);
    }

    return 0;
}

