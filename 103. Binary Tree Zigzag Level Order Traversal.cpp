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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        bool zigzag = false;
        q.push(root);
        while (!q.empty()) {
            vector<int> row;
            for (int i = q.size() - 1; i >= 0; --i) {
                TreeNode *cur = q.front();
                q.pop();
                if (zigzag) {
                    row.insert(row.begin(), cur->val);
                } else {
                    row.push_back(cur->val);
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            zigzag = !zigzag;
            ans.push_back(row);
        }
        return ans;
    }
};
