// This problem is to calculate how many ways you can sum consecutive prime numbers 
// to get a certain series of numbers
// For example 5 + 7 + 11 + 13 + 17 = 53, so there is one way to sum to 53
// However there are 3 ways to get to 41, so the progrem should return 3 when its 
// read in 41
// Prime is from 2 to 10000
#include <iostream>
using namespace std;

bool is_prime(int ipt, int total, int prime[]){
    for(int i = 0; i < total; i++) {
        if(!(ipt % prime[i])){
            return false;
        }
    }
    return true;
}

int main() {
    const int maxp = 2000, n = 10000;
    int prime[maxp], total = 0;
    //is_prime(2, 0, prime);
    //is_prime(3, 1, prime);
    for(int i = 2; i <= n; i++){
        if(is_prime(i, total, prime)){
            prime[total++] = i;
        }
    }
    prime[total] = n + 1;
    
    int m, ans;
    while(cin >> m && m) {
        ans = 0;
        for (int i = 0; m >= prime[i]; i++) {
            int cnt = 0;
            for (int j = i; j < total && cnt < m; j++){
                cnt += prime[j];
                if(cnt == m){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}