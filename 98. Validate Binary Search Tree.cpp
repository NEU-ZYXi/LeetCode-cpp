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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        vector<TreeNode*> stk;
        TreeNode *cur = root, *prev = NULL;
        while (!stk.empty() || cur) {
            while (cur) {
                stk.push_back(cur);
                cur = cur->left;
            }
            cur = stk.back();
            stk.pop_back();
            if (prev && prev->val >= cur->val) {
                return false;
            }
            prev = cur;
            cur = cur->right;
        }
        return true;
    }
};




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
    bool isValidBST(TreeNode* root) {
        return is_valid(root, NULL, NULL);
    }
    
private:
    bool is_valid(TreeNode* root, TreeNode* min_node, TreeNode* max_node) {
        if (!root) {
            return true;
        }
        if ((min_node && root->val <= min_node->val) || (max_node && root->val >= max_node->val)) {
            return false;
        }
        return is_valid(root->left, min_node, root) && is_valid(root->right, root, max_node);
    }
};
