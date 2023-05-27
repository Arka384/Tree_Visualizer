#include "Node.hpp"

Node::Node()
{
    this->data = -1;
    this->right = nullptr;
    this->left = nullptr;
}

Node::Node(char data)
{
    this->data = data;
    this->right = nullptr;
    this->left = nullptr;
}

char Node::getData(void)
{
    return this->data;
}
