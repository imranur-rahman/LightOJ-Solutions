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



template <class T> inline T imax(T &a,T b){if(b>a) a=b;}
template <class T> inline T imin(T &a,T b){if(b<a) a=b;}

const int MAX = 100 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;

int main()
{
    //ios_base::sync_with_stdio(false);

    set<int>s;
    map<int, int>m;

    si(n);
    int ar[n];
    int pos[MAX];
    int ok[n];

    REP(i, n) {
        si(ar[i]);
        pos[ar[i]] = i + 1;
        s.insert(ar[i]);
        //m.insert(ar[i]);
    }

    REP(i, n){

            if(s.find(i+1) == s.end()){

                    ok[i] = i+1;
            }
            else
                ok[pos[i+1]-1] = i+1;
    }
    REP(i, n) printf("%d ", ok[i]);

    return 0;
}
