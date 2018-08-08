//
// Created by Mohamad on 8/5/2018.
//

#include <bits/stdc++.h>

#define ld long double
using namespace std;

double


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int all_v;

    int *v = new int[n];
    ld *p = new ld[n];
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> p[i];
    }
    cout << f(all_v, n - 1, v, p) << endl;
    return 0;
}