#pragma once
#include "BinaryTree.hpp"

class Loader
{
private:
	std::vector<char> inorder{ 16, 8, 2, 12, 10, 15, 5, 4, 20, 6 };
	std::vector<char> preorder {10, 2, 8, 16, 12, 20, 5, 15, 4, 6};

	/*std::vector<char> inorder{ 8,4,9,2,10,5,11,1,12,6,13,3,14,7,15 };
	std::vector<char> preorder { 1,2,4,8,9,5,10,11,3,6,12,13,7,14,15 };*/

	/*std::vector<char> inorder { 2,5,1,9,8,15,6,10,7,3,12,4,2 };
	std::vector<char> preorder { 10,1,5,2,6,8,9,15,2,3,7,12,4 };*/
	int preIndex = 0;

public:
	Loader();

	void generateTree(BinaryTree& binaryTree);
	std::vector<char>& getInorder();
	std::vector<char>& getPreorder();
	int& getPreIndex();

};

