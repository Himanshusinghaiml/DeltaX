#include <iostream>
#include <string>
#include <stack>

using namespace std;

string formatJson(const string& input_str) {
    string formatted_str;
    int indentation = 0;
    bool inside_quotes = false;
    stack<char> brace_stack;

    for (char c : input_str) {
        if (c == '"' && (brace_stack.empty() || brace_stack.top() != '\\')) {
            inside_quotes = !inside_quotes;
        }

        if (!inside_quotes) {
            if (c == '{' || c == '[') {
                formatted_str += '\n';
                for (int i = 0; i < indentation; i++) {
                    formatted_str += "**";
                }
                formatted_str += c;
                formatted_str += '\n';
                indentation++;
                for (int i = 0; i < indentation; i++) {
                    formatted_str += "**";
                }
            } else if (c == '}' || c == ']') {
                indentation--;
                formatted_str += '\n';
                for (int i = 0; i < indentation; i++) {
                    formatted_str += "**";
                }
                formatted_str += c;
            } else if (c == ',') {
                formatted_str += c;
                formatted_str += '\n';
                for (int i = 0; i < indentation; i++) {
                    formatted_str += "**";
                }
            } else {
                formatted_str += c;
            }
        } else {
            formatted_str += c;
        }
    }

    return formatted_str;
}

int main() {
    // string input_str = R"({"name":"john","email":"john.d@gmail.com"})";
    
    string formatted_json = formatJson(input_str);
    cout << "Formatted JSON:" << endl;
    cout << formatted_json << endl;
    
    return 0;
}
