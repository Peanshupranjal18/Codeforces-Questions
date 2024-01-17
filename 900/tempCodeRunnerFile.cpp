#include <string>
#include <iostream>

void removeAllOccurrences(std::string &str, const std::string &subStr)
{
    size_t pos = str.find(subStr);
    while (pos != std::string::npos)
    {
        // Replace found substring with a single space
        str.replace(pos, subStr.length(), " ");
        pos = str.find(subStr);
    }
}

int main()
{
    std::string s;
    std::getline(std::cin, s); // Read the entire line, including spaces

    std::string p = "WUB";
    removeAllOccurrences(s, p);

    std::cout << s;
}
