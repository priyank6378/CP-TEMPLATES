vector<int> g[MAX_NODES_POSSIBLE];
void make_g(TreeNode* root){
        if (root->left){
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
            make_g(root->left);
        }
        if (root->right){
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
            make_g(root->right);
        }
    }