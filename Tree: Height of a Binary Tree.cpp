int height(Node* root) {
        // Write your code here.
         if (root == nullptr)
        return -1;

    int left_height = height(root->left);
    int right_height = height(root->right);

    return max(left_height, right_height) + 1;
    }
