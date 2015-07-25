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
template <class T> inline T imin(T a,T b){return (a<b)?a:b;}


const int MAX = 100 + 1;
const ll MAXINT = 1e18;

int grid[MAX][3], caseno = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n; cin >> t;
    while(t--){

        cin >> n;
        FOR(i, 0, n){
            FOR(j, 0, 3)
                cin >> grid[i][j];
        }

        FOR(i, 1, n){
            FOR(j, 0, 3){

                if(j==0) grid[i][j] += imin(grid[i-1][1], grid[i-1][2]);
                else if(j==1) grid[i][j] += imin(grid[i-1][0], grid[i-1][2]);
                else if(j==2) grid[i][j] += imin(grid[i-1][0], grid[i-1][1]);

            }
        }

        printf("Case %d: %d\n", ++caseno, imin(grid[n-1][0], imin(grid[n-1][1], grid[n-1][2])));
    }
    return 0;
}
