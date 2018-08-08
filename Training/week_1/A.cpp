//
// Created by Mohamad on 7/31/2018.
// https://vjudge.net/contest/237859#problem/A
//

//todo: ye flag dashte basham, jahate gohaii ke moghe debugo neveshtane code mikhoramo, moghe ersal, disable kone.

#include <bits/stdc++.h>

using namespace std;


int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    while (1) {
        int S, B;
        cin >> S >> B;
        if (S == 0 && B == 0)
            break;
        set<int, less<int>> sarbaza;
        for (int i = 0; i <= S; ++i) {
            sarbaza.insert(i);
        }
        for (int j = 0; j < B; ++j) {
            int L, R;
            cin >> L >> R;
            auto left = sarbaza.find(L);
            auto right = sarbaza.find(R);
            auto after_right = ++right;
            auto before_left = --left;
            left++;
            sarbaza.erase(left, right);


            if (*before_left == 0) {
                cout << "* ";
            } else {
                cout << *before_left << ' ';
            }
            if (after_right == sarbaza.end()) {
                cout << "*\n";
            } else {
                cout << *after_right << "\n";
            }
        }
        cout << "-\n";
    }

    return 0;
}


//----------- code bamdad : O(1)
/*
#include <bits/stdc++.h>
using namespace std;
struct something{
int left;int right;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int s,b;cin>>s>>b;if((s==0)&&(b==0)){break;}
        something dude[s+1];
        for(int i=1;i<=s;i++){
            dude[i].left=i-1;dude[i].right=i+1;
        }dude[s].right=0;
        for(int i=0;i<s;i++){
            cout<<dude[i].left<<"|||"<<dude[i].right<<"\n";
        }

        for(int i=0;i<b;i++){
        int left,right;cin>>left>>right;//left--;right--;
        if(dude[left].left!=0){cout<<dude[left].left;}
        else
        cout<<'*';
        if(dude[right].right!=0){cout<<" "<<dude[right].right<<"\n";}
        else
        {
        cout<<" *\n";
        }
        dude[dude[left].left].right=dude[right].right;
        dude[dude[right].right].left=dude[left].left;
        }

        cout<<"-\n";
        }

    return 0;
    }

 */
