#pragma once

struct Node {
    Node(int v, Node* n) : value{v}, next{n} {}
    int value;
    Node* next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    int at(int index) const;
    bool insert(int index, int value);
    void append(int value);
    bool removeAt(int index);
    int pop();

    void clean();

    int size() const { return m_size; }

private:
    Node* m_head;
    int m_size;
};
