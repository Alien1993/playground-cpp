#include <iostream>
#include <string>
#include <assert.h>

// This solution would take O(N)
char* urlify(char s[], int size)
{
    auto spaceCount = 0;
    for (auto i = 0; i < size; i++) {
        if (s[i] == ' ') {
            spaceCount++;
        }
    }

    auto index = spaceCount * 2 + size;
    for (auto i = size - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            s[index - 1] = '0';
            s[index - 2] = '2';
            s[index - 3] = '%';
            index -= 3; 
        } else {
            s[index - 1] = s[i];
            index--;
        }
    }
    return s;
}

int main(int argc, char* argv[])
{
    char smith[] = {"Mr John Smith    "};
    assert(std::string(urlify(&smith[0], 13)) == "Mr%20John%20Smith");

    char other[] = {"Another  test  to see if it  works                  "};
    assert(std::string(urlify(&other[0], 34)) == "Another%20%20test%20%20to%20see%20if%20it%20%20works");

    return 0;
}