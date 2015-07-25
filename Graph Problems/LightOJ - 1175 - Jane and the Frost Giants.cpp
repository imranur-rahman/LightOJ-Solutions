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

const int MAX = 200 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, r, jr, jc, ur, uc, vr, vc;
char ar[MAX][MAX];
int d[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool onTheGrid(int i, int j)
{
    return (i>=0 and i<r and j>=0 and j<c);
}

bool possibleEscape(int n, int m)
{
    return (n==0 or n==r-1 or m==0 or m==c-1);
}

void fire(queue<int>&q)
{
    while(!q.empty()){

            ur = q.front(); q.pop();
            uc = q.front(); q.pop();

            FOR(i, 0, 4){

                    vr = ur + dx[i];
                    vc = uc + dy[i];

                    if(onTheGrid(vr, vc)  and  d[vr][vc] > d[ur][uc] + 1){

                            d[vr][vc] = d[ur][uc] + 1;
                            q.push(vr);
                            q.push(vc);
                    }
            }
    }
}

int joe(int jr, int jc)
{
    queue<int>q;
    if(possibleEscape(jr, jc)) return 0;
    d[jr][jc] = 0;
    q.push(jr); q.push(jc);

    while(!q.empty()){

            ur = q.front(); q.pop();
            uc = q.front(); q.pop();

            FOR(i, 0, 4){

                    vr = ur + dx[i];
                    vc = uc + dy[i];

                    if(onTheGrid(vr, vc)  and  d[vr][vc] > d[ur][uc] + 1){

                            d[vr][vc] = d[ur][uc] + 1;
                            if(possibleEscape(vr, vc)) return d[vr][vc];
                            q.push(vr);
                            q.push(vc);
                    }
            }
    }
    return -1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    si(t);
    while(t--){

            sii(r, c);
            FOR(i, 0, r) scanf("%s", ar[i]);

            queue<int>q;

            FOR(i, 0, r) FOR(j, 0, c) {

                    if(ar[i][j] == 'J') jr = i, jc = j;
                    else if(ar[i][j] == '.') d[i][j] = INF;
                    else if(ar[i][j] == 'F') q.push(i), q.push(j), d[i][j] = 0;
                    else d[i][j] = -1;
            }

            fire(q);
            int x = joe(jr, jc);

            if(x == -1) printf("Case %d: IMPOSSIBLE\n", ++caseno);
            else printf("Case %d: %d\n", ++caseno, x + 1);
    }
    return 0;
}
