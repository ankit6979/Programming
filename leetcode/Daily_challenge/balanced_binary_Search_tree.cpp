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
    void inOrderTraversal (TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == NULL) {
            return;
        }
        inOrderTraversal (root->left, nodes);
        nodes.push_back(root);
        inOrderTraversal (root->right, nodes);
    }

    TreeNode* buildBalancedBST (int l, int r, vector<TreeNode*>& nodes) {
        if (l > r) return NULL;
        int mid = (l + r) / 2;

        TreeNode* root = nodes[mid];

        root->left = buildBalancedBST(l, mid - 1, nodes);
        root->right = buildBalancedBST(mid + 1, r, nodes);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inOrderTraversal (root, nodes);
        
        return buildBalancedBST (0, nodes.size() - 1, nodes);
    }
};