#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    int t, len;
    string number;
    bool inverse;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> number;
        len = number.length();
        inverse = false;
        for (int j = 0; j < len; j++) {
            if (inverse) {    
                number[j] = '9';
            } else {
                if (j < len-1 && number[j] > number[j+1]) {
                    number[j]--;
                    if (j > 0 && number[j] < number[j-1]) {
                        j -= 2;
                    } else {
                        inverse = true;
                    } 
                }
            }
        }
        for (int j = 0; j < len; j++) {
            if (number[j]=='0') {
                number = &number[j+1];
                j--;
                len--;
            }
        }
        cout << "Case #" << i+1 << ": " << number <<  endl;
    }
    return 0;
} 
