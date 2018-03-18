#include <unordered_map>
#include <string>
#include <assert.h>

using namespace std;

// This solutions takes O(N) space since an hashtable has been used.
// Time complexity would be O(S N) at worst where S is strings size 
// and N is hashtable size, but it would take O(S) on average since
// hashtable insertion and search are O(1) on average but O(N) at worst
bool isPermutation(const string s1, const string s2)
{
    if (s1.size() != s2.size()) {
        return false;
    }

    unordered_map<char, int> letters;

    for (auto c : s1) {
        if (letters.find(c) == letters.cend()) {
            letters[c] = 1;
        } else {
            letters[c]++;
        }
    }

    for (auto c : s2) {
        auto it = letters.find(c);
        if (it == letters.cend()) {
            return false;
        } else {
            if ((*it).second == 0) {
                return false;
            } else {
                (*it).second--;
            }
        }
    }
    
    return true;
}

int main(int argc, char* argv[])
{
    assert(isPermutation("asdfghj", "asdfghj"));
    assert(isPermutation("asd", "sda"));
    assert(isPermutation("loool", "ololo"));
    assert(isPermutation("", ""));
    assert(!isPermutation("a a", "aba"));
    assert(!isPermutation("ab", "a"));
    assert(!isPermutation("", " "));
    return 0;
}