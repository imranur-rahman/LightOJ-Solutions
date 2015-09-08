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

const int MAX = 1e4 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;

string pref;
int pi[MAX];

int failure()
{
    int now = -1;
    pi[0] = -1;

    for(int i=1; i<n; ++i){

            while(now != -1  &&  pref[now+1] != pref[i])

                    now = pi[now];

            if(pref[now+1] == pref[i])

                    pi[i] = ++now;

            else pi[i] = now = -1;
    }

    REP(i, n+1) printf("%d ", pi[i]);
    printf("\n");

    /*int a = -1;
    for(int i = m; i <= 2*m; ++i) imax(a, pi[i]);
    a++;*/
    int a = *max_element(pi + m + 1, pi + m + m) + 1;
    return m - a;
}

int main()
{
    //ios_base::sync_with_stdio(false);

    // from Shanto sir's book

    si(t);
    while(t--){

            cin >> pref;

            reverse(all(pref));
            m = pref.sz;

            pref += " " + pref;
            n = pref.sz;

            printf("Case %d: %d\n", ++caseno, failure());
    }


    return 0;
}
