class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> prev(matrix[0].begin(), matrix[0].end());

        for (int i = 1; i < n; i++) {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; j++) {
                int up = prev[j];
                int leftDiag = (j > 0) ? prev[j - 1] : 1e9;
                int rightDiag = (j < m - 1) ? prev[j + 1] : 1e9;

                curr[j] = matrix[i][j] + min({up, leftDiag, rightDiag});
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};