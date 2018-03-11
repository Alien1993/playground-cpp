#include "binary-tree.h"

BinaryTree::BinaryTree()
    : m_head{nullptr}
    , m_size{0}
{
    
}

BinaryTree::~BinaryTree()
{
    clean();
}

void BinaryTree::clean() 
{
    clean(m_head);
    m_head == nullptr;
    m_size = 0;
}

// Recursively deletes node and node's children
void BinaryTree::clean(Node* node)
{
    if (node->left) {
        clean(node->left);
        node->left = nullptr;
    }
    if (node->right) {
        clean(node->right);
        node->right = nullptr;
    }
    if (!node->left && !node->right) {
        delete node;
        m_size--;
    }
}

bool BinaryTree::contains(int value) const
{
    auto current = m_head;
    while (current) {
        if (current->value > value) {
            current = current->left;
        } else if (current->value < value) {
            current = current->right;
        } else {
            return true;
        }
    }
    return false;
}

bool BinaryTree::append(int value)
{
    if (m_size == 0) {
        m_head = new Node(value);
        m_size++;
        return true;
    }

    auto current = m_head;
    while (current) {
        if (current->value > value) {
            if (current->left) {
                current = current->left;
            } else {
                current->left = new Node(value);
                m_size++;
                return true;
            }
        } else if (current->value < value) {
            if (current->right) {
                current = current->right;
            } else {
                current->right = new Node(value);
                m_size++;
                return true;
            }
        } else {
            return false;
        }
    }
}

void BinaryTree::remove(int value)
{
    auto previous = m_head;
    auto current = m_head;
    auto prevDir = 0;
    // Finds node to delete
    while (current) {
        if (current->value > value) {
            previous = current;
            current = previous->left;
            prevDir = -1;
        } else if (current->value < value) {
            previous = current;
            current = previous->right;
            prevDir = 1;
        } else {
            break;
        }
    }

    // Node to delete is a leaf
    if (!current->right && !current->left) {
        if (prevDir == -1) {
            previous->left = nullptr;
        } else if (prevDir == 1) {
            previous->right = nullptr;
        }
        delete current;
        m_size--;
        return;
    }
    
    // Node to delete has one child
    if (!current->right && current->left) {
        if (prevDir == -1) {
            previous->left = current->left;
        } else if (prevDir == 1) {
            previous->right = current->left;
        }
        delete current;
        m_size--;
        return;
    } else if (current->right && !current->left) {
        if (prevDir == -1) {
            previous->left = current->right;
        } else if (prevDir == 1) {
            previous->right = current->right;
        }
        delete current;
        m_size--;
        return;
    }

    // Node to delete has two children
    auto previous2 = current;
    auto current2 = current->right;

    // Finds last left node that has no left node
    while (current2->left) {
        previous2 = current2;
        current2 = previous2->left;
    }

    // Subsitute node to delete with last left node found
    if (prevDir == -1) {
        previous->left = current2;
    } else if (prevDir == 1) {
        previous->right = current2;
    }

    // If last left node has one substitute with its right child
    if (current2->right) {
        previous2->left = current2->right;
    } else {
        previous2->left = nullptr;
    }

    delete current;
    m_size--;
}