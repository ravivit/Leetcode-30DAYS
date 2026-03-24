class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int MOD = 12345;
        int size = n * m;

        vector<int> arr;
        for (auto &row : grid) {
            for (int x : row) arr.push_back(x % MOD);
        }

        vector<int> prefix(size, 1), suffix(size, 1);

        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i-1] * arr[i-1]) % MOD;
        }

        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i+1] * arr[i+1]) % MOD;
        }

        vector<vector<int>> res(n, vector<int>(m));
        int k = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = (prefix[k] * suffix[k]) % MOD;
                k++;
            }
        }

        return res;
    }
};