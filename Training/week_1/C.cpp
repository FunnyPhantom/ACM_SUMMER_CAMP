//
// Created by Mohamad on 7/31/2018.
// https://vjudge.net/contest/237859#problem/C
//

#include <bits/stdc++.h>


using namespace std;

int N;
int B, SG, SB;
const int MAXB = 100 * 1000 + 1;
int bsolds[MAXB], gsolds[MAXB];

string draw = "green and blue died";
string gwin = "green wins";
string bwin = "blue wins";


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--) {
//        cout << "oy" << endl;
        multiset<int> glemings;
        multiset<int> blemings;
        cin >> B >> SG >> SB;
//        TRACE(B _ SG _ SB);
        int pow;
        for (int i = 0; i < SG; ++i) {
            cin >> pow;
            glemings.insert(pow);
        }
        for (int i = 0; i < SB; ++i) {
            cin >> pow;
            blemings.insert(pow);
        }
//        TRACE(B _ SG _ SB);
        while (glemings.size() > 0 && blemings.size() > 0) {
//            TRACE(B _ SG _ SB);
            int bzende = 0, gzende = 0;
            for (int numOfActiveSolds = 0; numOfActiveSolds < B; ++numOfActiveSolds) {
                if (glemings.empty() || blemings.empty())
                    break;
                auto itBigG = glemings.rbegin();
                auto itBigB = blemings.rbegin();
                if (*itBigG > *itBigB)
                    gsolds[gzende++] = *itBigG - *itBigB;
                else if (*itBigG < *itBigB)
                    bsolds[bzende++] = *itBigB - *itBigG;
                glemings.erase((++itBigG).base());
                blemings.erase((++itBigB).base());
                //GOH TO HAFT JADDO ABADE ITERATOR
            }
            for (int i = 0; i < gzende; ++i) {
                glemings.insert(gsolds[i]);
            }
            for (int i = 0; i < bzende; ++i) {
                blemings.insert(bsolds[i]);
            }
        }
//        TRACE(B);
        if (glemings.size() == 0 && blemings.size() == 0) {
            cout << draw << "\n";
//            TRACE(B);
        } else {
//            TRACE(B _ SB);
            if (glemings.size() == 0) {
                cout << bwin << "\n";
                for (auto it = blemings.rbegin(); it != blemings.rend(); it++) {
                    cout << *it << "\n";
                }
            } else {
                cout << gwin << "\n";
                for (auto it = glemings.rbegin(); it != glemings.rend(); it++) {
                    cout << *it << "\n";
                }
            }
        }
//        cout <<"test finished.";
        if (N != 0) {
            cout << "\n";
        }
    }

    return 0;
}