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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        path_sum(root, ans);
        return ans;
    }
    
private:
    int path_sum(TreeNode* root, int& ans) {
        if (!root) {
            return 0;
        }
        int left_sum = max(path_sum(root->left, ans), 0);
        int right_sum = max(path_sum(root->right, ans), 0);
        ans = max(ans, root->val + left_sum + right_sum);
        return root->val + max(left_sum, right_sum);
    }
};
