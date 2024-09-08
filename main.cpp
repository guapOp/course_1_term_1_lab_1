#include "iostream"
#include "generantor.h"

using namespace std;

int main (int argc, char * argv[]) {
    if (argc != 3) {
        cerr << "using: " << argv[0] << " <pass length> <complexity>" << endl;
        cerr << "complexity: 1 - number and lowe cae chars, 2 - numbers, lower case and uppercase chars, 3 - (2) + special chars" << endl;
        return 1;
    }

    int length = stoi(argv[1]);
    int complexity = stoi(argv[2]);

    string password = Generator::pass(length, complexity);

    cout << password;

}
