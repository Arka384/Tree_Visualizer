#pragma once
class Node
{
private:
	char data;
public:
    Node* left;
    Node* right;
    Node();
    Node(char data);
    char getData(void);
};

