/*
the main idea is we have to traverse the whole graph twice except the on which have max distance from source

The idea was to find the maximum depth (by the dfs we found all distance from the source and
                                        in line 62 we traverse whole dist array to find the max distance)

*/
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
#define ll long long
#define FOR(i, k, n) for(int i=(int) k ; i<(int)n; ++i)
#define MEM(array, value) memset(array, value, sizeof(array))

template <class T> inline T imax(T a,T b){return (a>b)?a:b;}

const int MAX = 100000 + 1;
const ll MAXINT = 1e18;

vector< pii > ar[MAX];
bool vis[MAX] = {false};
ll dist[MAX] = {0};

void dfs(int n)
{
    vis[n] = true;
    FOR(i, 0, ar[n].size()){
        int child = ar[n][i].ff;
        if(!vis[child]){
            dist[child] = dist[n] + ar[n][i].ss;
            dfs(child);
        }
    }
}

int main()
{
    int n, u, v, w; cin >> n;
    ll traverse = 0;

    FOR(i, 1, n){

        cin >> u >> v >> w;
        ar[u].pb(mp(v, w));
        ar[v].pb(mp(u, w));
        traverse += w;

    }

    dfs(1);

    ll depth = 0;
    FOR(i, 1, n+1)
        depth = max(depth, dist[i]);

    cout << traverse + traverse - depth << endl;
    return 0;
}
