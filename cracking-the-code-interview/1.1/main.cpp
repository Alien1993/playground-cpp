#include <string>
#include <set>
#include <assert.h>

// This solution has lower time complexity at O(N) but that some space cause of
// the set being used that has a O(N) space complexity
bool isUnique1(const std::string s)
{
    std::set<char> unique;
    for (auto c : s) {
        if (unique.find(c) != unique.cend()) {
            return false;
        } else {
            unique.insert(c);
        }
    }
    return true;
}

// This solution has constant space consumption at O(1) but time complexity is 
// higher at O(N^2)
bool isUnique2(const std::string s)
{
    for (auto i = 0; i < s.size(); i++) {
        for (auto j = i + 1; j < s.size(); j++) {
            if (s.at(i) == s.at(j)) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    assert(isUnique1("asdfghjk"));
    assert(isUnique2("asdfghjk"));

    assert(!isUnique1("aaa"));
    assert(!isUnique2("aaa"));
    
    return 0;
}
