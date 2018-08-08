//
// Created by Mohamad on 8/7/2018.
//

#include <bits/stdc++.h>

using namespace std;

string s1, s2;

int dp[1000][1000];
bool decide[1000][1000];
bool init = false;

int lcs(int i, int j) {
    if (!init) {
        memset(dp, -1, sizeof(dp));
        memset(decide, -1, sizeof(decide));
        init = true;
    }
    if (i == -1 || j == -1)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j]) {
        dp[i][j] = lcs(i - 1, j - 1) + 1;
    } else {
        decide[i][j] = (lcs(i - 1, j) > lcs(i, j - 1));
        if (decide[i][j]) {
            dp[i][j] = lcs(i - 1, j);
        } else {
            dp[i][j] = lcs(i, j - 1);
        }
    }
    return dp[i][j];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2;
    char mystr[lcs(s1.size() - 1, s2.size() - 1) + 1];
    int ind = lcs(s1.size() - 1, s2.size() - 1);
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while (ind != -1) {
        if (s1[i] == s2[j]) {
            mystr[ind] = s1[i];
            ind--;
            i--;
            j--;
        } else {
            if (dp[i - 1][j] < dp[i][j - 1]) {
                j--;
            } else {
                i--;
            }
        }
    }
    cout << mystr << endl;


    return 0;
}