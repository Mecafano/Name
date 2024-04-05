#include <iostream>
#include <cctype>

bool isPalindrome(const std::string& str, int start, int end) {
    if (start >= end)
        return true;

    // Convert characters to lowercase for case-insensitive comparison
    char left = std::tolower(str[start]);
    char right = std::tolower(str[end]);

    if (left != right)
        return false;

    // Move to the next pair of characters
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    bool result = isPalindrome(input, 0, input.length() - 1);

    if (result)
        std::cout << "Output: 1\n"; // Palindrome
    else
        std::cout << "Output: 0\n"; // Not a palindrome

    return 0;
}
