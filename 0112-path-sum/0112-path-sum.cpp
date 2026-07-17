class Solution {
public:
    void path(TreeNode *root, vector<int>& ans, vector<vector<int>>& allPaths) {
        if (!root) return;
        
        // 1. Always push the current node's value first
        ans.push_back(root->val);
        
        // 2. If it's a leaf node, copy the completed path to allPaths
        if (!root->left && !root->right) {
            allPaths.push_back(ans);
            // Don't just return here! We must pop this leaf node value 
            // before exiting the function to keep backtracking clean.
            ans.pop_back(); 
            return;
        }
        
        // 3. Recursively explore both branches
        path(root->left, ans, allPaths);
        path(root->right, ans, allPaths);
        
        // 4. Backtrack: remove the current node before going back up to the parent
        ans.pop_back();
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false; // Edge case: empty tree has no paths
        
        vector<vector<int>> allPaths;
        vector<int> ans;
        path(root, ans, allPaths);
        
        // Your exact summation logic
        for (auto it : allPaths) {
            int sum = 0;
            for (int val : it) {
                sum += val;
            }
            if (sum == targetSum) return true;
        }
        return false;
    }
};