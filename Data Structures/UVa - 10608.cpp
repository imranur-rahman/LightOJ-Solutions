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


const int MAX = 100 + 5;
const ll MAXINT = 1e18;
const int mod = 1e8 + 7;

ll t, caseno = 0, m, n, a, b, maxi = 0, flag = 0;

int ar[50005];
map<int,int>mapi;

int Find(int x)
{
    if(x != ar[x])
        ar[x] = Find(ar[x]);
    return ar[x];
}

bool Union(int a, int b)
{
    if((a = ar[a]) != (b = ar[b]))
    {
        ar[Find(a)] = Find(b);
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    //cin >> t;
    while(1){

        flag = 0;
        //mapi.clear();
        cin >> n >> m;
        if(n==0 and m==0) break;

        FOR(i, 1, n+1)
            ar[i] = i;

        while(m--){
            cin >> a >> b;
            Union(a, b);
        }

        FOR(i, 1, n+1) {
            //++mapi[Find(i)];
            if(ar[i] == i)
                flag++;
        }
        //FOR(i, 0, n+1) if()
        cout << "Case " << ++caseno << ": " << flag << endl;
    }
    return 0;
}

