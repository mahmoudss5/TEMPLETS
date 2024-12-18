
// شمال ثم نوود ثم يمين
void inOrder(node *root) {
    if (root == NULL) return;

    inOrder(root->left);
    printf("%d ", root->info);
    inOrder(root->right);
}

// نود ثم شمال ثم يمين
void preOrder(node *root) {
    if (root == NULL) return;

    printf("%d ", root->info);
    preOrder(root->left);
    preOrder(root->right);
}

// شمال ثم يمين ثم نود
void postOrder(node *root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->info);
}
