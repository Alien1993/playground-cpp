#include <unordered_map>
#include <list>

using namespace std;


struct Element {
    Element(const int i, const string v) : id{i}, value{v} {};
    int id;
    string value;
};

class LRUCache 
{
public:
    LRUCache(int maxSize);
    LRUCache(const LRUCache&) = delete;
    LRUCache(LRUCache&&) = delete;
    ~LRUCache();

    LRUCache& operator=(const LRUCache&) = delete;
    LRUCache& operator=(LRUCache&&) = delete;

    string get(int id) const;
    void set(int id, const string& value);
    
    list<Element*>* usage() { return m_usage; }

private:
    int m_maxSize;
    list<Element*>* m_usage;
    unordered_map<int, Element*>* m_elements;
};
