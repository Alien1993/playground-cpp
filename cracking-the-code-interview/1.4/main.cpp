#include <string>
#include <locale>
#include <cctype>
#include <unordered_map>
#include <assert.h>

using namespace std;

bool hasPalindrome(const string s)
{
    unordered_map<char, int> letters;

    for (auto c : s) {
        if (!isalpha(c)) {
            continue;
        }
        if (letters.find(tolower(c)) == letters.cend()) {
            letters[tolower(c)] = 1;
        } else {
            letters[tolower(c)]++;
        }
    }

    auto count = 0;
    auto it = letters.cbegin();
    while(it != letters.cend()) {
        count += it->second % 2;
        it++;
    }
    return count <= 1;
}

int main(int argc, char* argv[])
{
    assert(hasPalindrome("Tact Coa"));
    assert(hasPalindrome(" f o bo f"));
    assert(!hasPalindrome("foobar"));
}