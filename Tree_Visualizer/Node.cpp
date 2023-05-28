#include "Node.hpp"

Node::Node()
{
    this->data = -1;
    this->right = nullptr;
    this->left = nullptr;
}

Node::Node(int data)
{
    this->data = data;
    this->right = nullptr;
    this->left = nullptr;
}

int Node::getData(void)
{
    return this->data;
}
