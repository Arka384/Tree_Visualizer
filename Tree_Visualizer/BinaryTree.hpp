#pragma once
#include "Node.hpp"
#include <vector>

class BinaryTree
{
private:
	int nodeCount = 0;
	int level = 0;
	int height = 0;

public:
	Node* root;

	BinaryTree();
	Node* buildTree(std::vector<int>& inorder, std::vector<int>& preorder, int start, int end, int& preIndex);
	int search(std::vector<int>&, int, int, int);
	int findHeight(Node* root);

	void Inorder(Node* );
	void Preorder(Node* );
	void Postorder(Node* );

	int getNodeCount();

};

