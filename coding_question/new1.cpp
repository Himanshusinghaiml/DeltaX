#include <iostream>
#include <string>

void formatJson(std::string json) {
    int indentation = 0;
    bool inString = false;

    for (char c : json) {
        if (c == '"' && (json.empty() || json.back() != '\\')) {
            inString = !inString;
        }

        if (!inString) {
            if (c == '{' || c == '[') {
                std::cout << "**" << c;
                indentation += 2;
            } else if (c == '}' || c == ']') {
                indentation -= 2;
                std::cout << "\n";
                for (int i = 0; i < indentation; ++i) {
                    std::cout << "*";
                }
                std::cout << c;
            } else if (c == ',') {
                std::cout << c << "\n";
                for (int i = 0; i < indentation; ++i) {
                    std::cout << "*";
                }
            } else {
                std::cout << c;
            }
        } else {
            std::cout << c;
        }
    }
    std::cout << std::endl;
}

int main() {
    std::string jsonString = "{\"name\":\"james\",\"friends\":[{\"id\":0,\"name\":\"Christi Harmon\"},{\"id\":1,\"name\":\"Garrison peck\"},{\"id\":2,\"name\":\"jaclyn Kirk\"}]}";
    formatJson(jsonString);
    return 0;
}
