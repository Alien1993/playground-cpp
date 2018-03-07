#include "linked-list.h"

LinkedList::LinkedList()
    : m_head{nullptr}
    , m_size{0}
{

}

LinkedList::~LinkedList()
{
    auto previous = m_head;
    auto current = m_head;
    while (current) {
        previous = current;
        current = previous->next;
        delete previous;
    }
}

int LinkedList::at(int index) const
{
    auto current = m_head;
    auto next = m_head->next;
    for (auto i = 0; i < index; i++) {
        if (i == index) {
            return current->value;
        }
        current = next;
        next = current->next;
    }
}

bool LinkedList::insert(int index, int value)
{
    if (index == 0 && !m_head) {
        m_head = new Node(value, nullptr);
        m_size++;
        return true;
    }
    
    if (index >= m_size) {
        return false;
    }

    auto previous = static_cast<Node*>(nullptr);
    auto current = m_head;
    for (auto i = 0; i < m_size; i++) {
        if (i == index) {
            previous->next = new Node(value, current);
            m_size++;
            return true;
        }
        previous = current;
        current = previous->next;
    }
    return false;
}

void LinkedList::append(int value)
{
    if (!m_head) {
        m_head = new Node(value, nullptr);
    } else {
        auto current = m_head;
        auto next = m_head->next;
        while (next) {
            current = next;
            next = current->next;
        }
        current->next = new Node(value, nullptr);
    }
    m_size++;
}

bool LinkedList::removeAt(int index)
{
    if (index >= m_size) {
        return false;
    }

    auto previous = static_cast<Node*>(nullptr);
    auto current = m_head;

    if (index == 0) {
        m_head = current->next;
        delete current;
        m_size--;
        return true;
    }

    for (auto i = 0; i < m_size; i++) {
        if (i == index) {
            previous->next = current->next;
            delete current;
            m_size--;
            break;
        }
        previous = current;
        current = previous->next;
    }

    return true;
}

int LinkedList::pop()
{
    auto previous = static_cast<Node*>(nullptr);
    auto current = m_head;

    if (m_size == 1) {
        auto value = current->value;
        delete current;
        m_head = nullptr;
        m_size--;
        return value;
    }

    while (current->next) {
        previous = current;
        current = previous->next;
    }

    auto value = current->value;
    previous->next = static_cast<Node*>(nullptr);
    delete current;
    m_size--;

    return value;
}

void LinkedList::clean()
{
    auto previous = m_head;
    auto current = m_head;
    while (current) {
        previous = current;
        current = previous->next;
        delete previous;
        m_size--;
    }
}