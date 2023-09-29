#include <iostream>
#include <string>

using namespace std;

string formatJson(const string& input_str) {
    string formatted_str;
    int indentation = 0;
    bool inside_quotes = false;
    char last_char = ' ';

    for (char c : input_str) {
        if (c == '"' && last_char != '\\') {
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

        last_char = c;
    }

    return formatted_str;
}

int main() {
    // string input_str = "{\"name\":\"john\",\"email\":\"john.d@gmail.com\"}";
     string input_str = "{\"name\":\"james\",\"friends\":[{\"id\":0,\"name\":\"Christi Harmon\"},{\"id\":1,\"name\":\"Garrison peck\"},{\"id\":2,\"name\":\"jaclyn Kirk\"}]}";
      string input_str2 = "{\"name\":\"james\",\"friends\":[{\"id\":0,\"name\":\"Christi Harmon\"},{\"id\":1,\"name\":\"Garrison peck\"},{\"id\":2,\"name\":\"jaclyn Kirk\"}]}";

    string formatted_json = formatJson(input_str2);
    cout << "Formatted JSON:" << endl;
    cout << formatted_json << endl;

    return 0;
}
