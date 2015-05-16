#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if(n==1) return false;
    else if(n==2) return true;
    else{

        for(int i=2; i<n; i+=2){

            if(n%i == 0){

                return false;
            }
        }

        return true;
    }
}

int main()
{
    int a, b;
    int sum = 0;

    scanf("%d%d", &a, &b);

    for(int i=a; i<=b; i++){

        if(isPrime(i)){

            //cout << i << endl;
            sum += i;
        }
    }

    printf("%d", sum);
    return 0;
}
