#pragma once
class Node
{
private:
	int data;
public:
    Node* left;
    Node* right;
    Node();
    Node(int data);
    int getData(void);
};

