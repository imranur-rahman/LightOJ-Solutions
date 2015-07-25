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

const int MAX = 10000 + 1;
const ll MAXINT = 1e18;

int t, n, m, p, caseno = 0, a, b, c, flag;
string t1, t2;
vector<pair<int, pair<int,int> > >grid;
int parent[MAX];
//map<string, int>m;

bool cmp_max(const pair<int, pair<int,int> > &A, const pair<int, pair<int,int> > &B)
{
    return A.ff > B.ff;
}

void print()
{
    FOR(i, 0, n+1)
        cout << parent[i] << " ";
    cout << endl;
}

int Find(int n)
{
    if(n != parent[n])
        parent[n] = Find(parent[n]);
    return parent[n];
}

void Union(int a, int b)
{
    int pa = parent[a];
    int pb = parent[b];
    parent[pa] = Find(pb);
    //parent[a] = parent[b];
}

bool isSameSet(int a, int b)
{
    /*int x = parent[a];
    int y = parent[b];
    return x == y;*/
    return Find(a) == Find(b);
}

int min_spanning_tree()
{

    int ret = 0;
    for(int i=0; i<grid.size(); i++){

        if(!isSameSet(grid[i].ss.ff, grid[i].ss.ss)  and  grid[i].ff < p){ //grid[i].ff < p ei check korata important, karon amar rasta banaite jodi airport bananor cheye beshi khoroc hoy taile ami rasta banabo na

            Union(grid[i].ss.ff, grid[i].ss.ss);
            ret += grid[i].ff;
            //print();
            //cout << ret << endl;
        }
        /*if(Merge(grid[i].ss.ff, grid[i].ss.ss))
            ret += grid[i].ff;*/
    }
    return ret;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){

        cin >> n >> m >> p;
        grid.clear();
        //imap.clear();
        flag = 0;
        FOR(i, 0, m){
            cin >> a >> b >> c;
            grid.pb(mp(c, mp(a, b)));

        }

        FOR(i, 1, n + 1)
            parent[i] = i;

        //cout << min_spanning_tree() << endl;

        sort(grid.begin(), grid.end());
        int mini = min_spanning_tree();
        int cnt = 0;
        FOR(i, 1, n + 1){
            if(parent[i] == i)
                cnt++;
        }

        /*if(cnt > 1)
            printf("Case %d: Impossible\n", ++caseno);
        else
            printf("Case %d: %d\n", ++caseno, mini);
        */

        printf("Case %d: %d %d\n", ++caseno, mini + p * cnt, cnt);
    }
    return 0;
}

