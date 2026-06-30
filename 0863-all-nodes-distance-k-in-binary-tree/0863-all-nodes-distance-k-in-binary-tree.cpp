/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                parent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode*, TreeNode*>parent;
        markParents(root, parent);
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_level++ ==k) break;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};