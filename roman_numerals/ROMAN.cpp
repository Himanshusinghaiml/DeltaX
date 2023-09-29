#include <iostream>
#include <unordered_map>

int romanToInt(const std::string& s) {
    std::unordered_map<char, int> romanValues{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int prevValue = 0;

    for (int i = s.length() - 1; i >= 0; --i) {
        char current = s[i];
        int currentValue = romanValues[current];

        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue;
    }

    return result;
}

int main() {
    std::string romanNumeral;
    std::cout << "Enter a Roman numeral: ";
    std::cin >> romanNumeral;

    int numericValue = romanToInt(romanNumeral);
    std::cout << "Numeric equivalent: " << numericValue << std::endl;

    return 0;
}
