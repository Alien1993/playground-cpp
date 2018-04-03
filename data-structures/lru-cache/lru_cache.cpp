#include <algorithm>

#include "lru_cache.h"

LRUCache::LRUCache(int maxSize)
    : m_maxSize{maxSize}
    , m_usage{new list<Element*>}
    , m_elements{new unordered_map<int, Element*>}
{

}

LRUCache::~LRUCache()
{
    m_usage->clear();
    delete m_usage;
    m_elements->clear();
    delete m_elements;
}

string LRUCache::get(int id) const
{
    auto eIt = m_elements->find(id);

    if (eIt == m_elements->cend()) {
        // Element not cached
        return "";
    }

    auto uIt = find_if(m_usage->cbegin(), m_usage->cend(),
        [=] (Element* e) { return e->id == id; }
    );

    m_usage->push_back(*uIt);
    m_usage->erase(uIt);

    return eIt->second->value;
}

void LRUCache::set(int id, const string& value)
{
    auto eIt = m_elements->find(id);

    // Modifies cached value
    if (eIt != m_elements->cend()) {
        eIt->second->value = value;

        auto uIt = find_if(m_usage->cbegin(), m_usage->cend(),
            [=] (Element* e) { return e->id == id; }
        );

        m_usage->push_back(*uIt);
        m_usage->erase(uIt);
        return;
    }

    // Caches new value
    auto element = new Element(id, value);
    m_usage->push_back(element);
    m_elements->insert({id, element});
    
    // Deletes least recently used element if size limit is reached
    if (m_usage->size() > m_maxSize) {
        auto toRemove = m_usage->front();
        m_elements->erase(toRemove->id);
        m_usage->pop_front();
        delete toRemove;
    }
}