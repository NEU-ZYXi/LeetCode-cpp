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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int left_height = get_depth(root->left);
        int right_height = get_depth(root->right);
        return abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
private:
    int get_depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_height = get_depth(root->left);
        int right_height = get_depth(root->right);
        return max(left_height, right_height) + 1;
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
    bool isBalanced(TreeNode* root) {
        return get_depth(root) != -1;
    }
    
private:
    int get_depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_height = get_depth(root->left);
        if (left_height == -1) {
            return -1;
        }
        int right_height = get_depth(root->right);
        if (right_height == -1) {
            return -1;
        }
        if (abs(left_height - right_height) > 1) {
            return -1;
        }
        return max(left_height, right_height) + 1;
    }
};
