#include "BinaryTree.hpp"

BinaryTree::BinaryTree()
{
	this->root = nullptr;
}

Node* BinaryTree::buildTree(std::vector<char>& inorder, std::vector<char>& preorder, int start, int end, int& preIndex)
{
    nodeCount = end + 1;
    if (start > end)
        return nullptr;
    Node* t = new Node(preorder[preIndex++]);
    if (start == end)
        return t;
    //seperate two parts
    int inOrderIndex = search(inorder, start, end, t->getData());
    t->left = buildTree(inorder, preorder, start, inOrderIndex - 1, preIndex);
    t->right = buildTree(inorder, preorder, inOrderIndex + 1, end, preIndex);
    return t;
}

int BinaryTree::search(std::vector<char>& arr, int start, int end, char data)
{
    for (int i = start; i <= end; i++) {
        if (arr[i] == data)
            return i;
    }
    return -1;
}

int BinaryTree::findHeight(Node* root)
{
    if (root == nullptr)
        return 0;
    int leftHeigh = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    if (leftHeigh > rightHeight)
        return leftHeigh + 1;
    else
        return rightHeight + 1;
}

void BinaryTree::Inorder(Node* root)
{
    if (root == nullptr) return;
    Inorder(root->left);
    printf("%d ", root->getData());
    Inorder(root->right);
}

void BinaryTree::Preorder(Node*)
{
    if (root == nullptr) return;
    printf("%d ", root->getData());
    Preorder(root->left);
    Preorder(root->right);
}

void BinaryTree::Postorder(Node*)
{
    if (root == nullptr) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->getData());
}

int BinaryTree::getNodeCount()
{
    return nodeCount;
}
