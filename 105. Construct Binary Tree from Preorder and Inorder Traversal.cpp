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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) {
            return NULL;
        }
        return build(preorder, 0, n - 1, inorder, 0, n - 1);
    }
    
private:
    TreeNode* build(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2) {
        if (l1 > r1 || l2 > r2) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[l1]);
        int root_idx = l2;
        while (root_idx <= r2) {
            if (inorder[root_idx] == root->val) {
                break;
            }
            root_idx++;
        }
        root->left = build(preorder, l1 + 1, l1 + root_idx - l2, inorder, l2, root_idx - 1);
        root->right = build(preorder, r1 - r2 + root_idx + 1, r1, inorder, root_idx + 1, r2);
        return root;
    }
};
