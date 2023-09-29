/* 
 unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;*/

#include <iostream>
#include <unordered_map>
#include <string>

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

    for (int i = s.size() - 1; i >= 0; --i) {
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

bool isValidRoman(const std::string& s) {
    for (char c : s) {
        if (c != 'I' && c != 'V' && c != 'X' && c != 'L' && c != 'C' && c != 'D' && c != 'M') {
            return false;
        }
    }
    return true;
}
 
int main() {
    std::string romanNumeral;
    std::cout << "Enter a Roman numeral: ";
    std::cin >> romanNumeral;

    if (isValidRoman(romanNumeral)==false) {
        std::cout << "Invalid" << std::endl;
    } else {
        int numericValue = romanToInt(romanNumeral);
        std::cout << "Numeric equivalent: " << numericValue << std::endl;
    }

    return 0;
}
