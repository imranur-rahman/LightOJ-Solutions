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

const int N = 111111;
long long a[N], b[N];
int n, m, w;
long long bit[N];

struct fenwick
{
	fenwick() { memset(bit, 0, sizeof(bit)); }
	long long pref(int x)
	{
		long long ret = 0;
		for (int i = x; i >= 0; i = (i & (i+1)) - 1) ret += bit[i];
		return ret;
	}
	inline void upd(int x, long long val) { for (int i = x; i < N; i |= i+1) bit[i] += val; }
	inline long long que(int x, int y) { return pref(y) - pref(x-1); }
};

bool poss(long long mi)
{
	for (int i = 0; i < n; i++) b[i] = max(0ll, mi - a[i]);
	memset(bit, 0, sizeof(bit));
	fenwick x;
	for (int i = 0; i < n; i++) x.upd(i, b[i] - (i == 0 ? 0 : b[i-1]));

	long long ct = 0;
	for (int i = 0; i < n; i++)
		if (x.que(0, i) > 0)
		{
			long long nu = x.que(0, i);
			x.upd(i, -nu);
			x.upd(i+w, nu);
			ct += nu;
			if (ct > m) return false;
		}
	return true;
}

int main()
{
    //not my code
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> w;
	for (int i = 0; i < n; i++) cin >> a[i];
	long long lo = 1, hi = 0x3f3f3f3f3f3f3f3fll;
	while (lo < hi)
	{
		long long mi = (lo+hi+1) / 2;
		if (poss(mi)) lo = mi;
		else hi = mi - 1;
	}
	cout << lo << "\n";
	return 0;
}
