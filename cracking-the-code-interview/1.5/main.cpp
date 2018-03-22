#include <string>
#include <unordered_map>
#include <assert.h>

using namespace std;

#include <iostream>

bool isSimilar(const string& s1, const string& s2)
{
    int diff = s1.length() - s2.length();

    if (-1 > diff || diff > 1) {
        return false;
    }
    
    string shorter, longer;
    if (diff == -1) {
        shorter = s1;
        longer = s2;
    } else {
        shorter = s2;
        longer = s1;
    }

    unordered_map<char, int> letters;
    for (auto c : longer) {
        if (letters.find(c) == letters.cend()) {
            letters[c] = 1;
        } else {
            letters[c]++;
        }
    }

    for (auto c : shorter) {
        if (letters.find(c) != letters.cend()) {
            letters[c]--;
        }
    }

    auto count = 0;
    auto it = letters.cbegin();
    while (it != letters.cend()) {
        count += it->second;
        if (count > 1) {
            return false;
        }
        it++;
    }
    
    return count <= 1;
}


int main(int argc, char* argv[])
{
    assert(isSimilar("pale", "ple"));
    assert(isSimilar("pales", "pale"));
    assert(isSimilar("pale", "bale"));
    assert(!isSimilar("pale", "bake"));
    assert(!isSimilar("long", "longer"));
}