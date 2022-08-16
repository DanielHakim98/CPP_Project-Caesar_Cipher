#include <iostream>
using std::cout;
using std::endl;
using std::string;

string caesar(string str_1, int num);
int check_wrap_capital(int shifted_num);
int check_wrap_lower(int shifted_num);

int main(){

    cout << "Test 1 : 'A',1\n";
    cout << caesar("A",1) << "\n\n";

    cout << "Test 2 : 'Aaa',1\n";
    cout << caesar("Aaa",1) << "\n\n";

    cout << "Test 3 : 'Hello World',5\n";
    cout << caesar("Hello, World!", 5) << "\n\n";

    cout << "Test 4 : 'Mjqqt, Btwqi!, -5\n";
    cout << caesar("Mjqqt, Btwqi!", -5) << "\n\n";

    cout << "Test 5 : 'Z',1\n";
    cout << caesar("Z",1) << "\n\n";

    cout << "Test 6 : 'Hello, World!',75\n";
    cout << caesar("Hello, World!", 75) << "\n\n";

    cout << "Test 7 : 'Hello, World!', -29\n";
    cout << caesar("Hello, World!",-29) << "\n\n";

    return 0;
}

string caesar(string str_1, int num){
    int i = 0;
    int shifted_num;
    string final_str;

    for (char c: str_1){
        // Shift it by 'num' when c is a ASCII decimal of an ASCII Capital
        if(int(c)>= 65 && int(c) <= 90){
            shifted_num = int(c) + num;
            if (shifted_num < 65 || shifted_num > 90)
                shifted_num = check_wrap_capital(shifted_num);
        }
        // Shift it by 'num' when c is a ASCII decimal of an ASCII lower
        else if(int(c) >= 97 && int(c) <= 122){
            shifted_num = int(c) + num;
            if(shifted_num < 97 || shifted_num > 122)
                shifted_num = check_wrap_lower(shifted_num);
        }
        // No ASCII decimal shift if value is non character [*A-Za-z]
        else
            shifted_num = int(c);

        // Convert shifted character to ASCII character
        final_str += char(shifted_num);
        i++;
    }
    return final_str;
}

// Wrap from Z to A / Z to A if shifted_num is out range of from ASCII capital
int check_wrap_capital(int shifted_num){
    if (shifted_num > 90){
        while(shifted_num > 90)
            shifted_num = (shifted_num - 90) + 65 - 1;
    }
    else{
        while(shifted_num < 65)
            shifted_num = 90 - (65 - shifted_num) + 1;
    }
    return shifted_num;
}

// Wrap from z to a / a to z if shifted_num is out range of from ASCII lower
int check_wrap_lower(int shifted_num){
    if (shifted_num > 122){
        while(shifted_num > 122)
            shifted_num = (shifted_num - 122) + 97 - 1;
    }
    else{
        while(shifted_num < 97)
            shifted_num = 122 - (97 - shifted_num) + 1;
    }
    return shifted_num;
}




