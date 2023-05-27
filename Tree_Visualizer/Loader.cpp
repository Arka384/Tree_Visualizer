#include "Loader.hpp"

Loader::Loader()
{
}

void Loader::generateTree(BinaryTree& binaryTree)
{
	binaryTree.root = binaryTree.buildTree(inorder, preorder, 0, inorder.size() - 1, preIndex);
}

std::vector<char>& Loader::getInorder()
{
	return this->inorder;
}

std::vector<char>& Loader::getPreorder()
{
	return this->preorder;
}

int& Loader::getPreIndex()
{
	return this->preIndex;
}
