#include <iostream>
#include <cstring>

using namespace std;

 int countOccurrences(const char* str) {
    int count = 0;
    size_t len = strlen(str);
    for (int i = 0; i < len - 2; i++) {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c') {
            count++;
        }
    }
    return count;
}

char* replaceOccurrences(const char* str) {
    size_t len = strlen(str);
    char* result = new char[len * 2 + 1];  
    char* temp = result;

    for (int i = 0; i < len;) {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c') {
            *temp++ = '*';
            *temp++ = '*';
            i += 3;
        }
        else {
            *temp++ = str[i++];
        }
    }
    *temp = '\0';  

    return result;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int occurrences = countOccurrences(str);
    cout << "Number of 'abc' occurrences: " << occurrences << endl;

    char* modifiedStr = replaceOccurrences(str);

    cout << "Modified string: " << modifiedStr << endl;

   
    delete[] modifiedStr;

    return 0;
}
