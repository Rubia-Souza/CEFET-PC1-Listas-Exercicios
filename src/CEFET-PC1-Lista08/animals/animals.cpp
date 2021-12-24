#include <iostream>
#include <string>

using namespace std;

class Node {
    private:
        Node *leftNode = NULL;
        Node *rightNode = NULL;
        string value = "";
    
    public: 
        Node() {}

        Node(const string value) {
            setValue(value);
        }

        Node(const string value, Node *leftNode, Node *rightNode) {
            setValue(value);
            setLeftNode(leftNode);
            setRightNode(rightNode);
        }

        void setValue(const string value) {
            this->value = value;
        }

        string getValue() {
            return value;
        }

        void setLeftNode(Node *nodeReference) {
            this->leftNode = nodeReference;
        }

        Node *getLeftNode() {
            return leftNode;
        }

        void setRightNode(Node *nodeReference) {
            this->rightNode = nodeReference;
        }

        Node *getRightNode() {
            return rightNode;
        }
};

class Tree {
    private:
        Node *root = NULL;
    
    public:
        Tree(Node *root) {
            this->root = root;
        }

        Tree(const string value) {
            root = new Node();
            root->setValue(value);
        }

        bool isEmpty() {
            return (root == NULL);
        }
};

int main() {

    return 0;
}
