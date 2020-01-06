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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> stk;
        TreeNode *cur = root, *first = NULL, *second = NULL, *prev = NULL;
        while (!stk.empty() || cur) {
            while (cur) {
                stk.push_back(cur);
                cur = cur->left;
            }
            cur = stk.back();
            stk.pop_back();
            if (!first && prev && prev->val >= cur->val) {
                first = prev;
            }
            if (first && prev->val >= cur->val) {
                second = cur;
            }
            prev = cur;
            cur = cur->right;
        }
        swap(first->val, second->val);
    }
};
