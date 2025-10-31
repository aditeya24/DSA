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

void PostOrder(struct TreeNode* root, int* a, int* returnSize) {
    if (root != NULL) {
        PostOrder(root->left, a, returnSize);
        PostOrder(root->right, a, returnSize);
        a[(*returnSize)++] = root->val;
    }
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* a = (int*)malloc(100*sizeof(int));
    *returnSize = 0;
    PostOrder(root, a, returnSize);
    return a;
}
