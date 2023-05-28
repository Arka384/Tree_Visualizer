#pragma once
#include "BinaryTree.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

class Loader
{
private:
	std::vector<int> inorder;
	std::vector<int> preorder;
	int preIndex = 0;

public:
	Loader();

	void loadTraversals();
	void generateTree(BinaryTree& binaryTree);
	int& getPreIndex();

};

