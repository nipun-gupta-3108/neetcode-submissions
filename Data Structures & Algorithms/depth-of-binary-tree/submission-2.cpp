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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        int ans = 0;
        while(!st.empty()) {
            auto cur = st.top();
            st.pop();

            TreeNode* node = cur.first;
            int depth = cur.second;

            if(node) {
                ans = max(ans, depth);
                st.push({node->left, depth + 1});
                st.push({node->right, depth + 1});
            }
        }

        return ans;
    }
};
