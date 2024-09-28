#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];
bool visited[10] = {false};
bool visiting[10] = {false};
vector<vector<int>> cycles;

void dfs(int u, vector<int>& path) {
    visiting[u] = true;
    path.push_back(u);

    for (int v : adj[u]) {
        if (visiting[v]) {
            vector<int> cycle;
            for (auto it = path.rbegin(); it != path.rend(); ++it) {
                cycle.push_back(*it);
                if (*it == v) break;
            }
            reverse(cycle.begin(), cycle.end());
            cycles.push_back(cycle);
        } else {
            dfs(v, path);
        }
    }

    visiting[u] = false;
    visited[u] = true;
    path.pop_back();
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            vector<int> path;
            dfs(i, path);
        }
    }

    if (cycles.empty()) {
        cout << "No cycles found\n";
    } else {
        vector<int> smallestCycle = cycles[0]; // Take the first cycle
        int smallestSum = accumulate(smallestCycle.begin(), smallestCycle.end(), 0); // Sum of nodes in the first cycle, initial value of sum is 0

        for (const auto& cycle : cycles) {
            int sum = accumulate(cycle.begin(), cycle.end(), 0); // Sum of nodes in the current cycle
            if (sum < smallestSum) {
                smallestSum = sum;
                smallestCycle = cycle;
            }
        }

        sort(smallestCycle.begin(), smallestCycle.end());

        for (int node : smallestCycle) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
