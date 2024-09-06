#include <iostream>
#include <string>
#include <windows.h>

int encrypt(unsigned char in);

int main() {
    for(;;){
        std::string password;

        std::cout << "Enter a password: ";
        std::cin >> password;


        int ascii[password.length()];

        int iter = 0;
        for(int i = 0; i < password.length(); i++){
            ascii[i] = password[i - 1] != NULL && password[i] > password[i - 1] ?(encrypt(password[i])): abs((encrypt(password[i])));
            iter++;
        }

        std::cout << "Code:" << std::endl;

        int index = 0;
        for(auto i: ascii){
            Beep(i, 500);
            if(i < 0){
                int temp = i - i * 2;
                std::cout << index << " " << temp << " ";
            }
            index+= i > ascii[0] ? i : 1;
        }

        std::cout << "\n";
    }
}

int encrypt(unsigned char in){
    int out = (int)in;
    out = ~out;
    out += 1;
    out *= 10;

    return out;
}
