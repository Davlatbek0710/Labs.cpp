#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int validation_ckeck_for_number() {
    string num;
    bool check = true;
    while (true) {
        cout << "Enter a telephone number: ", cin >> num;
        for (int i = 0; i < num.length(); i++) {
            if (!(num[i] >= 48 && num[i] <= 57)) {
                check = false;
                break;
            }
        }
        if (check) {
            break;
        }
        else {
            check = true;
            continue;
        }
    }
    return from_string_to_integer(num);
}
int from_string_to_integer(string num) {
    int result = 0;
    for (int i = 0; i <= num.length(); i++) {
        if (!(num[i] >= '0' && num[i] <= '9')) {
            break;
        }
        else {
            // for example: str x = "67" -> to integer. 
            // first x[0] -> '6', in Ascii: '6' == 54. and '0' == 48. 
            // so when we substract 54 - 48 = 6. just what we wanted to get.
            //And so on...
            result = 10 * result + (num[i] - '0');
        }
    }
    return result;
}
int main() {
   
    int i = validation_ckeck_for_number();
    cout << i << endl;


    return 0;
}