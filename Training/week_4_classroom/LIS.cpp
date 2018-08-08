//
// Created by Mohamad on 8/5/2018.
//

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000;
int arr[max_n], dp[max_n][2];

int f(int n) {
    dp[0][0] = 1;
    dp[0][1] = -1;
    for (int i = 1; i < n; ++i) {
        int max_before = -1;
        int max_index = -1;
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j] < arr[i]) {
                if (dp[j][0] > max_before) {
                    max_before = dp[j][0];
                    max_index = j;
                }
            }
        }
        if (max_before == -1) {
            dp[i][0] = 1;
            dp[i][1] = -1;
        } else {
            dp[i][0] = dp[max_index][0] + 1;
            dp[i][1] = max_index;
        }
    }
}

void find_max_and_print(int n) {
    int max_find = -1, max_i = -1;
    for (int i = 0; i < n; ++i) {
        if (dp[i][0] > max_find) {
            max_find = dp[i][0];
            max_i = i;
        }
    }
    cout << max_find << endl;
    stack<int> s;
    do {
        s.push(max_i);
        max_i = dp[max_i][1];
    } while (max_i != -1);
    while (!s.empty()) {
        cout << arr[s.top()] << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    f(n);
    find_max_and_print(n);

    return 0;
}