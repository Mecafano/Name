#include <iostream>
#include <string>

std::string substring(const std::string& str, int i, int j) {
    if (i < 0 || j >= str.length() || i > j)
        return "";

    if (i == 0 && j == str.length() - 1)
        return str;

    return str[i] + substring(str, i + 1, j);
}

int main() {
    std::string input;
    int i, j;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::cout << "Enter the positions i and j: ";
    std::cin >> i >> j;

    std::string result = substring(input, i, j);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
