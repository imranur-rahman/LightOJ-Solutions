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

int t, n, m, caseno = 0, a, b, c, d, dfsNumberCounter, flag, num;
vi ar[MAX], dfs_num, dfs_low, visited;
stack<int> s;
string p, q;
map<string, int>mapi;
map<int, string>mapi2;

void clearData()
{
    FOR(i, 1, n+1)
        ar[i].clear();

    dfsNumberCounter = 0;
    flag = 0;
    num = 0;

    dfs_low.assign(n+1, 0);
    dfs_num.assign(n+1, 0);
    visited.assign(n+1, 0);
    while(!s.empty())
        s.pop();
    mapi.clear();
    mapi2.clear();
}

void tarjanSCC(int u)
{
    //if(visited[u]) return;
    dfs_low[u] = dfs_num[u] =  ++dfsNumberCounter;
    visited[u] = 1;
    s.push(u);

    FOR(j, 0, ar[u].sz){

        int v = ar[u][j];

        if(dfs_num[v] == 0)
            tarjanSCC(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u]){
        ++flag;
        while(!s.empty()){
            int a = s.top(); s.pop();

            //printf("%d ", a);

            cout << mapi2[a] << " ";

            if(a == u) break;
        }
        printf("\n");
    }

}

int main()
{
    ios_base::sync_with_stdio(false);

    //cin >> t;
    while(1){

        cin >> n >> m;

        if(n==0  and  m==0) break;

        clearData();

        while(m--){
            cin >> p >> q;
            if(!mapi.count(p))
                a = mapi[p];
            else{
                a = mapi[p] = ++num;
                mapi2[num] = p;
            }

            if(!mapi.count(q))
                b = mapi[q];
            else{
                b = mapi[q] = ++num;
                mapi2[num] = q;
            }
            ar[a].pb(b);
            ar[b].pb(a);
        }

        for(int i=1; i<=n; i++){
            if(visited[i] == 0){
                tarjanSCC(i);
            }
        }

        printf("Case %d: %d\n", ++caseno, flag);
    }
    return 0;
}
