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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }
        return generate(1, n);
    }
    
private:
    vector<TreeNode*> generate(int l, int r) {
        vector<TreeNode*> ans;
        if (l > r) {
            ans.push_back(NULL);
        }
        for (int i = l; i <= r; ++i) {
            vector<TreeNode*> left_subtree = generate(l, i - 1);
            vector<TreeNode*> right_subtree = generate(i + 1, r);
            for (TreeNode* left_node : left_subtree) {
                for (TreeNode* right_node : right_subtree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_node;
                    root->right = right_node;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
