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
    unordered_map<TreeNode*, int> dp;
public:
    int solve(TreeNode* root) {
        if(dp.count(root)) return dp[root];

        int ans = root->val;
        if(root->left) ans += solve(root->left->left) + solve(root->left->right);
        if(root->right) ans += solve(root->right->left) + solve(root->right->right);

        ans = max(ans, solve(root->left) + solve(root->right));
        return dp[root] = ans;
    }

    int rob(TreeNode* root) {
        dp[nullptr] = 0;

        int ans = max(solve(root), solve(root->left) + solve(root->right));
        return ans;
    }
};