#include <iostream>
#include <string>
#include <cctype>
#include<bits/stdc++.h>

bool isValidPhoneNumber(const std::string& phoneNumber) {
    // Check if the phone number starts with +91, 0, 7, 8, or 9
    if (phoneNumber.empty() || !(phoneNumber[0] == '+' || phoneNumber[0] == '0' || (phoneNumber[0] >= '7' && phoneNumber[0] <= '9'))) {
        return false;
    }

    // Remove spaces and check if the remaining characters are digits
    std::string strippedNumber;
    for (char c : phoneNumber) {
        if (!std::isspace(c)) {
            strippedNumber.push_back(c);
            if (!std::isdigit(c)) {
                return false;
            }
        }
    }

    // Check if the length of the stripped number is 10
    return strippedNumber.length() == 10;
}

int main() {
    std::vector<std::string> phoneNumbers = {
        "+91 12345 67890",
        "0 98765 43210",
        "78901 23456",
        "6543210987",
        "12345",
        "ABCD",
        "8 76543 21098",
        "+918147326014"
    };

    for (const std::string& phoneNumber : phoneNumbers) {
        bool isValid = isValidPhoneNumber(phoneNumber);
        std::cout << phoneNumber << " is " << (isValid ? "valid" : "invalid") << std::endl;
    }

    return 0;
}
