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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            bool foundx=false;
            bool foundy=false;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->val==x) foundx=true;
                if(temp->val==y) foundy=true;
                if(temp->left && temp->right){
                    if(temp->left->val==x && temp->right->val==y) return false;
                    if(temp->left->val==y && temp->right->val==x) return false;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(foundx && foundy) return true;
        }
        return false;
    }
};