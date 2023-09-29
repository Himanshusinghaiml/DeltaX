#include <iostream>
#include <string>
using namespace std;

int main() {
    string url;
    cin >> url;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        // Find the position of the key in the URL
        size_t keyPos = url.find(s + "=");

        if (keyPos != string::npos) {
            // Extract the substring starting from the key position
            string substring = url.substr(keyPos + s.length() + 1);

            // Find the position of '&' to determine the end of the value
            size_t ampersandPos = substring.find('&');

            // If '&' is found, extract the value up to that position
            if (ampersandPos != string::npos) {
                string value = substring.substr(0, ampersandPos);
                cout << value << endl;
            } else {
                // If '&' is not found, extract the entire substring as the value
                cout << substring << endl;
            }
        } else {
            // Key not found
            cout << "-1" << endl;
        }
    }

    return 0;
}
