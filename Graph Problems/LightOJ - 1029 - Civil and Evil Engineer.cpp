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

int t, n, caseno = 0, a, b, c;

vector<pair<int, pair<int,int> > >grid;
int parent[MAX];

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
        if(!isSameSet(grid[i].ss.ff, grid[i].ss.ss)){
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

        cin >> n;
        grid.clear();
        while(cin >> a >> b >> c){
            if(!a  and  !b  and  !c) break;
            grid.pb(mp(c, mp(a, b)));

        }

        FOR(i, 0, MAX+1)
            parent[i] = i;

        //cout << min_spanning_tree() << endl;

        sort(grid.begin(), grid.end());
        int mini = min_spanning_tree();

        FOR(i, 0, MAX+1)
            parent[i] = i;

        reverse(grid.begin(), grid.end());
        int maxi = min_spanning_tree();

        if((maxi % 2 == 0  and  mini % 2 == 0) or (maxi % 2 == 1  and  mini % 2 == 1))
            printf("Case %d: %d\n", ++caseno, (maxi+mini)/2);
        else
            printf("Case %d: %d/2\n", ++caseno, maxi+mini);
        //cout << maxi << " " << mini << endl;
    }
    return 0;
}
