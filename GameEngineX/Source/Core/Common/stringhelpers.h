#ifndef STRINGHELPERS_H
#define STRINGHELPERS_H
#include <sstream>
#include <vector>

class StringHelpers
{
public:
    static std::vector<std::string> split(std::string str, char delimiter) {
        std::vector<std::string> internal;
        std::stringstream ss(str); // Turn the string into a stream.
        std::string tok;

        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }

        return internal;
    }
};
#endif // STRINGHELPERS_H
