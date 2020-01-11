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
    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }
    
private:
    int sum(TreeNode* root, int prev_sum) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 10 * prev_sum + root->val;
        }
        return sum(root->left, 10 * prev_sum + root->val) + sum(root->right, 10 * prev_sum + root->val);
    }
};
