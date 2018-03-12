#pragma once

#include <string>
#include <forward_list>

#define BUCKET_SIZE 10


struct Pair
{
    Pair(std::string k, int v) : key{k}, value{v} {};
    std::string key;
    int value;
};

class HashTable 
{
public:
    HashTable();
    ~HashTable();

    void insert(const std::string key, const int value);
    int value(const std::string key, const int defaultValue = 0) const;
    void remove(const std::string key);
    bool contains(const std::string key) const;

    void clear();
    
    int size() const { return m_size; }

private:
    std::forward_list<Pair*>* m_buckets[BUCKET_SIZE];
    int m_size;
};