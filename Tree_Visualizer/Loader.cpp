#include "Loader.hpp"

Loader::Loader() {
	//XDDDDD
}

void Loader::loadTraversals()
{
	int data, size, i = 0;
	std::ifstream input("input/input.txt");
	if (!input.is_open())
		exit(1);
	input >> size;
	while (i < size) {
		input >> data;
		inorder.push_back(data);
		i++;
	}
	i = 0;
	while (i < size) {
		input >> data;
		preorder.push_back(data);
		i++;
	}
	input.close();
}

void Loader::generateTree(BinaryTree& binaryTree) {
	binaryTree.root = binaryTree.buildTree(inorder, preorder, 0, inorder.size() - 1, preIndex);
}

int& Loader::getPreIndex() {
	return this->preIndex;
}
