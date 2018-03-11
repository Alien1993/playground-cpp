#pragma once

struct Node {
    Node(int v, Node* l = nullptr, Node* r = nullptr) 
        : value{v}, left{l}, right{r} {};
    int value;
    Node* left;
    Node* right;
};

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    bool contains(int value) const;
    bool append(int value);
    void remove(int value);

    void clean();

    int size() const { return m_size; }
private:
    void clean(Node* node);

    Node* m_head;
    int m_size;
};