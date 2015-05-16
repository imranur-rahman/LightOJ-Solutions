#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--){
        long long n, p = 1, i;
        cin >> n;
        for(i = 0; i*i <= n; i++){
            while(n%i == 0){
                p = i;
                n /= i;
            }
        }
        if(n > 1) p = n;
        cout << p << endl;
    }

    return 0;
}

