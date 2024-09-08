#include "generantor.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


using namespace std;
using namespace Generator;

namespace Generator {
    string pass(int length, int complexity) {
        string numbers = "0123456789";
        string lowercase = "abcdefghijklmnopqrstuvwxyz";
        string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string special = "!@#$%^&*()-_=+[]{}|;:,.<>?";

        string characters;

        if (complexity == 1) {
            characters = numbers + lowercase;
        } else if (complexity == 2) {
            characters = numbers + lowercase + uppercase;
        } else if (complexity == 3) {
            characters = numbers + lowercase + uppercase + special;
        } else {
            cerr << "wrong complexity, need from 1 to 3" << endl;
            return "";
        }

        string password;
        srand(time(0));

        for (int i = 0; i < length; ++i) {
            int randomIndex = rand() % characters.size();
            password += characters[randomIndex];
        }

        return password;
    }
}