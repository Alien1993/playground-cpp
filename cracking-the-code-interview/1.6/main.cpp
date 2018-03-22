#include <string>
#include <assert.h>

using namespace std;

string compress(const string& s)
{
    string compressed;
    auto previous = s[0];
    auto count = 1;
    for (auto i = 1; i < s.size(); i++) {
        if (s[i] == previous) {
            count++;
        } else {
            compressed.append(1, previous);
            compressed.append(to_string(count));
            previous = s[i];
            count = 1;
        }
    }

    compressed.append(1, previous);
    compressed.append(to_string(count));

    if (s.length() <= compressed.length()) {
        return s;
    }

    return compressed;
}

int main(int argc, char* argv[])
{
    assert(compress("aabcccccaaa") == "a2b1c5a3");
    assert(compress("aaaabbbbeeeefui") == "a4b4e4f1u1i1");
    assert(compress("aa") == "aa");
    assert(compress("lol") == "lol");
}