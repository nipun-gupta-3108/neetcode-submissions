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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool fl = true;
        while(!q.empty()) {
            int sz = q.size();

            vector<int> level;
            while(sz--) {
                auto curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left) {
                    q.push(curr->left);
                }

                if(curr->right) {
                    q.push(curr->right);
                }
            }

            if(!fl) reverse(level.begin(), level.end());
            fl = !fl;

            ans.push_back(level);
        }

        return ans;
    }
};