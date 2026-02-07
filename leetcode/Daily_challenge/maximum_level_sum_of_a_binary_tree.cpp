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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        int maximumLevelSum = INT_MIN;
        int levelWithMaximumSum = 1, currentLevel = 0;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int nodesInCurrentLevel = nodeQueue.size();
            int currentLevelSum = 0;
            currentLevel++;

            for (int i = 0; i < nodesInCurrentLevel; ++i) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                currentLevelSum += currentNode->val;

                if (currentNode->left) {
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    nodeQueue.push(currentNode->right);
                }
            }

            if (currentLevelSum > maximumLevelSum) {
                maximumLevelSum = currentLevelSum;
                levelWithMaximumSum = currentLevel;
            }
        }

        return levelWithMaximumSum;
    }
};

// Time O(N)
// Space O(W)