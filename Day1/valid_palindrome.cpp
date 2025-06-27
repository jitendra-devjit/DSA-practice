#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is alphanumeric
bool isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

// Function to convert a character to lowercase
char toLower(char c) {
    if(c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

// Main palindrome checking function
bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while(left < right) {
        // Skip non-alphanumeric characters from the left
        while(left < right && !isAlphanumeric(s[left])) left++;
        // Skip non-alphanumeric characters from the right
        while(left < right && !isAlphanumeric(s[right])) right--;

        // Compare characters in lowercase
        if(toLower(s[left]) != toLower(s[right]))
            return false;

        left++;
        right--;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string to check if it is a valid palindrome:\n";
    getline(cin, input);

    if(isPalindrome(input))
        cout << "Yes, it is a valid palindrome.\n";
    else
        cout << "No, it is not a valid palindrome.\n";

    return 0;
}
