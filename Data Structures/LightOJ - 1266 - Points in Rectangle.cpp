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
#define REP(i, n) for(int i=0; i<n; ++i)
#define MEM(array) memset(array, -1, sizeof(array))
#define CLR(array) memset(array, 0, sizeof(array))
#define all(v) v.begin(), v.end()
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b)
#define siii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define TIME(a) printf("Time %d\n", clock() - a)



template <class T> inline T imax(T &a,T b){if(b>a) a=b;}
template <class T> inline T imin(T &a,T b){if(b<a) a=b;}

const int MAX = 1000 + 10;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d, p, q;

int tree[MAX][MAX];
int ar[MAX][MAX];

void update(int x, int y, int val)
{
    x += 3, y += 3;
    int y1;
    while(x <= MAX){
        y1 = y;
        while(y1 <= MAX){
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int sum(int x, int y)
{
    x += 3, y += 3;
    int ret = 0, y1;
    while(x > 0){
        y1 = y;
        while(y1 > 0){
            ret += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return ret;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    si(t);
    while(t--){

        CLR(tree);
        CLR(ar);

        si(q);
        printf("Case %d\n", ++caseno);
        while(q--){
            si(m);
            if(m == 0){
                sii(a, b);
                //a++, b++;
                if(ar[a][b] == 0)
                    update(a, b, 1), ar[a][b] = 1;
            }
            else {
                sii(a, b);
                sii(c, d);
                //a++, b++, c++, d++;
                printf("%d\n", sum(c, d) - sum(c, b-1) - sum(a-1, d) + sum(a-1, b-1));
            }
        }
    }
    return 0;
}
