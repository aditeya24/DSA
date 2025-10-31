/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void PreOrder(struct TreeNode* root, int* a, int* returnSize) {
    if (root != NULL) {
        a[(*returnSize)++] = root->val;
        PreOrder(root->left, a, returnSize);
        PreOrder(root->right, a, returnSize);
    }
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* a = (int*)malloc(100*sizeof(int));
    *returnSize = 0;
    PreOrder(root, a, returnSize);
    return a;
}
