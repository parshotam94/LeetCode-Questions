/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void rec(TreeNode *node, int level, vector<int>&res){
        if(!node) return;
        if(res.size()==level) res.push_back(node->val);
        rec(node->right, level+1, res);
        rec(node->left, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        rec(root, 0, res);
        return res;
    }
};