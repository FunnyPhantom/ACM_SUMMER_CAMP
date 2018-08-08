//
// Created by Mohamad on 7/31/2018.
//

#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n, t;
        cin >> n >> t;
        if (n == 0 && t == 0)
            break;
        int *arr = new int[t];
        for (int i = 0; i < t; ++i) {
            cin >> arr[i];
        }
        vector<string> outs(12);
        cout << "Sums of " << n << ":\n";
        for (int i = (1 << t); i > 0; i--) {
            int sum = 0;
            int mask = 1 << t;
            int j = t;
            vector<int> nums(12);
            while (j--) {
                if (mask & i) {
                    sum += arr[j];
                    nums.push_back(arr[j]);
                }
                if (sum >= n)
                    break;
                mask >> 1;
            }
            if (sum == n) {
                string s;
                for (int k = 0; k < nums.size(); ++k) {
                    if (k = nums.size() - 1) {
                        s.append(to_string(nums[k]));
                    } else {
                        s.append(to_string(nums[k]) + "+");
                    }
                }
                outs.push_back(s);
            }
        }
        if (outs.size() == 0)
            cout << "NONE\n";
        else {
            cout << outs.size() << "\n";
            for (int i = 0; i < outs.size(); ++i) {
                cout << outs[i] << "\n";
            }
        }
    }

    return 0;
}