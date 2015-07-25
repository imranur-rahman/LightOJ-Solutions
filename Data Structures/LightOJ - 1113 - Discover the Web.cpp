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

vector<string>ar(MAX, "0");
string str;
int len, max_len;

int t, m, n, caseno = 0;

void print()
{
    FOR(i, 0, max_len+2)
        cout << i << " " << ar[i] << endl;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--){

        FOR(i, 0, 101) ar[i] = "0";
        len = 0;
        max_len = 0;
        //printf("Case %d:\n", ++caseno);
        cout << "Case " << ++caseno << ":" << endl;
        ar[0] = "http://www.lightoj.com/";


        while(cin >> str){

            max_len = max(max_len, len);

            if(str == "QUIT") {
                //printf("\b");
                break;
            }
            //printf("\n");
            if(str == "VISIT"){

                if(len != max_len)
                    FOR(i, len+1, max_len+1)
                        ar[i] = "0", max_len = len;

                cin >> str;
                ar[++len] = str;
                cout << str << endl;

            }
            else if(str == "BACK"){

                if(len != 0){
                    cout << ar[--len] << endl;
                }
                else
                    cout << "Ignored" << endl;

            }
            else if(str == "FORWARD"){

                if(len != max_len)
                    cout << ar[++len] << endl;
                else
                    cout << "Ignored" << endl;

            }
            //print();
        }
    }
    return 0;
}
