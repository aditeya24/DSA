/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxHeight = 0;

int findHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left, right;
    left = findHeight(root->left);
    right = findHeight(root->right);
    if (left + right > maxHeight) {
        maxHeight = left + right;
    }
    return (left > right ? left + 1 : right + 1);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    findHeight(root);
    int ans = maxHeight;
    maxHeight = 0;
    return ans;
}
