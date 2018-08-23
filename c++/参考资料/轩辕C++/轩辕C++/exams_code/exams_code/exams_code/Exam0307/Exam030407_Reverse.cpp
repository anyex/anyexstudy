/*
 * Exam030407_Reverse.cpp
 *
 *  Created on: 2010-2-17
 *      Author: kwarph
 */

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " input_file output_file\n";
        return 1;
    }

    // 这句加了 ios::ate
    ifstream in(argv[1], ios::in | ios::binary | ios::ate);
    if (!in) {
        cout << "Open file " << argv[1] << " failed.\n";
        return 1;
    }

    // num of bytes in file
    long i = (long) in.tellg() - 1;
    // remove eof
    //    i -= 2;

    ofstream out(argv[2]);
    if (!out) {
        cout << "Open file " << argv[1] << " failed.\n";
        return 1;
    }
    char ch;
    for (; i >= 0; --i) {
        in.seekg(i, ios::beg);
        in.get(ch);
        cout.put(ch);
        out.put(ch);
    }
    cout << endl;
    in.close();
    out.close();
}
