//
// Created by Mohamad on 8/2/2018.
//
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int max_mn = 3e5 + 1;
const ll inf = 1e15;
vector<int> adj_list[max_mn];
vector<ll> adj_weight[max_mn];
int n, m;

struct Ras {
    ll id;
    ll weight;

    Ras(ll idd, ll w = inf) {
        id = idd;
        weight = w;
    }
};

ll operator<(const Ras &r1, const Ras &r2) {
    return r2.weight - r1.weight;
}

void dijkstra(int source) {
    priority_queue<int, vector> rasa;
    for (int i = 0; i < n; ++i) {
        if (i == source) {
            rasa.push((i));
        } else {
            rasa.push((i));
        }
    }

    for (int j = 0; j < n; ++j) {
        cout << rasa.top() + 1 << endl;
        rasa.pop();
    }


}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);


    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        adj_weight[u].push_back(w);
        adj_weight[v].push_back(w);
    }
    int source;
    cin >> source;
    source--;
    dijkstra(source);


    return 0;
}
