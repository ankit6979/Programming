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
    int findDepth(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        return max (findDepth(node->left), findDepth(node->right)) + 1;
    }
    int subtreeWithAllDeepestHelper (TreeNode* node, TreeNode*& subtree, int  maxDepth) {
        if (node == NULL) {
            return 0;
        }
        int ldepth = subtreeWithAllDeepestHelper(node->left, subtree, maxDepth - 1);
        int rdepth = subtreeWithAllDeepestHelper(node->right, subtree, maxDepth - 1);

        if (ldepth == (maxDepth - 1) && rdepth == (maxDepth - 1)) {
            subtree = node;
        }

        return max (ldepth, rdepth) + 1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = findDepth(root);
        TreeNode* subtree;
        subtreeWithAllDeepestHelper (root, subtree, maxDepth);
        return subtree;
    }
};