#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        // Step 1: Validate diagonal
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }

        // Step 2: DSU setup
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b) {
            parent[find(a)] = find(b);
        };

        // Step 3: Merge groups where lcp[i][j] > 0
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    unite(i, j);
                }
            }
        }

        // Step 4: Assign characters
        vector<char> res(n);
        unordered_map<int, char> mp;
        char cur = 'a';

        for (int i = 0; i < n; i++) {
            int p = find(i);
            if (!mp.count(p)) {
                if (cur > 'z') return ""; // more than 26 groups
                mp[p] = cur++;
            }
            res[i] = mp[p];
        }

        string word(res.begin(), res.end());

        // Step 5: Validate full LCP matrix
        vector<vector<int>> calc(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    if (i + 1 < n && j + 1 < n)
                        calc[i][j] = 1 + calc[i + 1][j + 1];
                    else
                        calc[i][j] = 1;
                }
            }
        }

        if (calc != lcp) return "";

        return word;
    }
};