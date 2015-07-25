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

const int MAX = 100 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;
vector<int>ar[MAX];
int vis[MAX];
int par[MAX];
int low[MAX];
int discovery[MAX];
bool points[MAX];
int TIME = 0, cnt = 0, root, flag = 0, rootchildren = 0;;
enum{WHITE, BLACK, GRAY};

void articulationPoint(int u, int parent = -1)
{
    low[u] = discovery[u] == ++TIME;

    int children = 0;

    vis[u] = GRAY;

    FOR(i, 0, ar[u].sz){

            int v = ar[u][i];

            if(v == parent) continue;

            if(vis[v] == WHITE){

                    children++;

                    articulationPoint(v, u);

                    low[u] = min(low[u], low[v]);

                    if(low[v] >= discovery[u])
                        points[u] = true;
            }

            else// if(v != par[u])
                low[u] = min(low[u], discovery[v]);

    }
    if(parent == -1) points[u] = children > 1;

    vis[u] = BLACK;
}

void clearData()
{
    TIME = 0, cnt = 0, flag = 0, rootchildren = 0;
    FOR(i, 0, n+1) {
        ar[i].clear();
        vis[i] = WHITE;
        points[i] = false;
    }
    /*MEM(par, -1);
    MEM(vis, WHITE);
    MEM(low, 0);
    MEM(discovery, 0);
    MEM(points, false);*/
}

int main()
{
    ios_base::sync_with_stdio(false);

    freopen("in.txt", "r", stdin);
    si(t);
    while(t--){

            sii(n, m);
            clearData();

            while(m--){

                    sii(a, b);
                    ar[a].pb(b);
                    ar[b].pb(a);
            }

            root = 1;
            articulationPoint(1);

            FOR(i, 1, n+1) if(points[i]) ++cnt;//cout << i << endl;


            printf("Case %d: %d\n", ++caseno, cnt);
    }
    return 0;
}
