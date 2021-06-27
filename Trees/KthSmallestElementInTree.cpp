/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// This is O(1) space and also time complexity is O(B) i.e. value of k
int Solution::kthsmallest(TreeNode* A, int B) {
    int count = 0;
    stack<TreeNode*> st;
    TreeNode* curr = A;
    
    while(curr!=NULL || !st.empty()){
        //st.push(curr);
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        count++;
        if(count == B) return curr->val;
        curr = curr->right;
    }
}
