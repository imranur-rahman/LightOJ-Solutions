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

#define ok(i,j) (i>=0 && i<n && j>=0 && j<n)

template <class T> inline T imax(T a,T b){return (a>b)?a:b;}
template <class T> inline T imin(T a,T b){return (a<b)?a:b;}

const int MAX = 100 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;
int Ax, Ay, Bx, By, Cx, Cy;

int bfs()
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    si(t);
    while(t--){

            si(n);

            char grid[n][n];
            for(int i=0; i<n; ++i)
                scanf("%s", grid[i]);

            set<pair<int, int> >s;
            FOR(i, 0, n) FOR(j, 0, n) {

                    if(grid[i][j] == 'A')
                        Ax = i, Ay = j;
                    else if(grid[i][j] == 'B')
                        Bx = i, By = j;
                    else if(grid[i][j] == 'C')
                        Cx = i, Cy = j;
                    else if(grid[i][j] == 'X')
                        s.insert(mp(i, j));
            }

    }
    return 0;
}
