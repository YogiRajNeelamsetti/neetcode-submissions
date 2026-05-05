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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> in;
        int ans;
        TreeNode* curr = root;
        int cnt = 0;
        while(curr != NULL) {
            if(curr -> left == NULL) {
                in.push_back(curr -> val);
                cnt++;
                if(cnt == k) {
                    ans = curr -> val;
                }
                curr = curr -> right;
            } else {
                TreeNode* prev = curr -> left;
                while(prev -> right && prev -> right != curr) {
                    prev = prev -> right;
                }
                if(prev -> right == NULL) {
                    prev -> right = curr;
                    curr = curr -> left;
                } else {
                    prev -> right = NULL;
                    in.push_back(curr -> val);
                    cnt++;
                    if(cnt == k) {
                        ans = curr -> val;
                    }
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};
