class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        bool even = true; // true represents even-indexed levels (0, 2, 4...)
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            // Collect all elements of the current level
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            
            // Validate the level
            if (even) {
                // Even level: values must be ODD and STRICTLY INCREASING
                for (int i = 0; i < level.size(); i++) {
                    // Check parity for every element
                    if (level[i] % 2 == 0) return false; 
                    // Check strictly increasing order for subsequent elements
                    if (i > 0 && level[i] <= level[i - 1]) return false;
                }
            } 
            else {
                // Odd level: values must be EVEN and STRICTLY DECREASING
                for (int i = 0; i < level.size(); i++) {
                    // Check parity for every element
                    if (level[i] % 2 != 0) return false; 
                    // Check strictly decreasing order for subsequent elements
                    if (i > 0 && level[i] >= level[i - 1]) return false;
                }
            }
            
            even = !even; // Switch level parity for the next level
        }
        
        return true;
    }
};