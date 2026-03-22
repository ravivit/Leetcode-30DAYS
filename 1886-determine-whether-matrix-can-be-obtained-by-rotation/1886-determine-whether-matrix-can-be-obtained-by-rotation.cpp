class Solution {
public:
    vector<vector<int>> rotate90(vector<vector<int>> mat) {
        int n = mat.size();
        vector<vector<int>> newMat(n, vector<int>(n));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                newMat[j][n - 1 - i] = mat[i][j];
            }
        }
        
        return newMat;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int k = 0; k < 4; k++) {
            if(mat == target) return true;
            mat = rotate90(mat);
        }
        return false;
    }
};