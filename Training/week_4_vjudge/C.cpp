//
// Created by Mohamad on 8/6/2018.
//



#include <bits/stdc++.h>

using namespace std;
int modu = 1e6;

long long dp[105][105];
bool initilized = false;

long long f(int N, int K) {
    if (!initilized) {
        memset(dp, -1, sizeof(dp));
        initilized = true;
    }
    if (K == 1)
        return 1;
    if (K == 2)
        return N + 1;


    if (dp[N][K] != -1) return (dp[N][K] % modu);
    long long ans = 0;
    for (int i = N; i >= 0; i--) {
        ans = ans + f(i, K - 1);
    }
    dp[N][K] = ans % modu;
    return (dp[N][K]);

}


int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n, k;
    while (1) {
        cin >> n >> k;
        if (n == 0 && k == 0)
            break;
        cout << f(n, k) << "\n";
    }


    return 0;
}