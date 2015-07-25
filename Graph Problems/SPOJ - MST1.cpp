/*
We cannot use recursive call here
*/

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
#define ll long long
#define FOR(i, k, n) for(int i=(int) k ; i<(int)n; ++i)
#define MEM(array, value) memset(array, value, sizeof(array))

template <class T> inline T imax(T a,T b){return (a>b)?a:b;}
template <class T> inline T imin(T a,T b){return (a<b)?a:b;}

const int MAX = 20000000 + 7;
const ll MAXINT = 1e18;

ll dp[MAX];
int caseno = 0;

long int dp[MAX+1];

int main() {
	// your code goes here
	int n;
	cin>>n;
	dp[0]=0;
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;

	for(int i=4;i<=MAX;i++){
		dp[i]= 1+ dp[i-1];
		if(i%2==0)
		dp[i]= min(dp[i],1+dp[i/2]);

		if(i%3==0)
		dp[i]= min(dp[i],1+dp[i/3]);
	}

	for(int i=1;i<=n;i++){
		long long int a;
		cin>>a;
		cout<<"Case "<<i<<": "<<dp[a]<<endl;
	}
	return 0;
}
