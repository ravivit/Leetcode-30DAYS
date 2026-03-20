#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                
                vector<int> vals;
                
                // collect elements
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        vals.push_back(grid[x][y]);
                    }
                }
                
                sort(vals.begin(), vals.end());
                
                // ✅ remove duplicates
                vals.erase(unique(vals.begin(), vals.end()), vals.end());
                
                // ✅ if only 1 unique element
                if (vals.size() <= 1) {
                    ans[i][j] = 0;
                    continue;
                }
                
                int minDiff = INT_MAX;
                for (int p = 1; p < vals.size(); p++) {
                    minDiff = min(minDiff, vals[p] - vals[p - 1]);
                }
                
                ans[i][j] = minDiff;
            }
        }
        
        return ans;
    }
};