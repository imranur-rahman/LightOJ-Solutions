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

int t, n, m, caseno = 0, a, b, c, d, flag;
vector<int>grid[MAX];
int vis[MAX];
enum{WHITE, RED, BLACK};
//black is my target and answer

void dfs(int u, int color)
{
    if(u==1 && !flag) flag = 1;
    else vis[u] = color;

    for(int i=0; i<grid[u].sz; ++i){

            int v = grid[u][i];
            if(vis[v] != BLACK)
                dfs(v, (color==BLACK) ? RED : BLACK);

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    si(t);
    while(t--){

            sii(n, m);
            /*FOR(i, 1, n+1)
                grid[i].clear();

            while(m--){

                    sii(a, b);
                    grid[a].pb(b);
                    grid[b].pb(a);
            }

            MEM(vis, WHITE);
            flag = 0;
            dfs(1, BLACK);

            int ans = 0;
            for(int i=1; i<=n; ++i)
                if(vis[i] == BLACK)
                    ++ans;
            */
            vector<vector<int> >fw(n+1, vector<int>(n+1, INF));

            for(int i=1; i<=n; ++i)
                fw[i][i] = 0;

            while(m--){

                    sii(a, b);
                    fw[a][b] = 1;
                    fw[b][a] = 1;
            }

            for(int k=1; k<=n; ++k)
                for(int i=1; i<=n; ++i)
                    for(int j=1; i<=n; ++j)
                        fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);

            int ans = 0;
            for(int i=1; i<=n; ++i)
                if(fw[i][1] != 1  && fw[i][1] != INF)
                    ans += fw[i][1];

            printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}
