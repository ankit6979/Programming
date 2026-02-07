#define mod 1000000007
#define ll long long
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
    long long traverse (TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        ll left = 0, right = 0;
        if (node->left) {
            left = traverse (node->left);
        }
        if (node->right) {
            right = traverse (node->right);
        }
        return (node->val + left + right);
    }
    long long traverse_subtree (TreeNode* node, ll total_sum, ll& max_sum) {
        if (node == NULL) {
            return 0;
        }
        ll left = 0, right = 0;
        if (node->left) {
            left = traverse_subtree (node->left, total_sum, max_sum);
        }
        if (node->right) {
            right = traverse_subtree (node->right, total_sum, max_sum);
        }
        int curr_sum = (node->val + left + right);
        max_sum = max (max_sum, (curr_sum * (total_sum - (curr_sum))));
        return curr_sum;
    }
    int maxProduct(TreeNode* root) {
        ll total_sum = traverse (root);
        ll max_sum = -1;
        traverse_subtree (root, total_sum, max_sum);

        return max_sum % mod;
    }
};