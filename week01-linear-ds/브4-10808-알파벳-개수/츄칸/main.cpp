#include <iostream>
using namespace std;

int main() {
    string word;
    cin >> word;

    int count[26] = {0};

    for (char c : word) {
        count[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << count[i] << " ";
    }

    return 0;
}