/*
 * Main.cpp
 *
 *  Created on: 2010-1-23
 *      Author: kwarph
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <exception>
using namespace std;


/**
 * TODO add switches: -l -w -c
 */

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " input-file ...\n";
        return 0;
    }

    const int FIELD_WIDTH = 4;

    // tcc-total bytes, tcw-total words, tcl-total lines
    int tcc = 0, tcw = 0, tcl = 0;
    // cc-bytes, cw-words, cl-lines
    int cc = 0, cw = 0, cl = 0;

    ifstream fin; // reuse this stream.
    for (int i = 1; i < argc; ++i) {
        fin.clear(); // let status of fin good
        fin.open(argv[i], ios::binary);
        if (!fin) {
            cerr << argv[0] << ": open file " << argv[i] << " failed.\n";
            continue;
        }
        // Don't initialize these variables (cc, cw, cl) here.
        // Put them out of for loop.
        cc = 0;
        cw = 0;
        cl = 0;
        char c;
        while (fin.get(c)) {
            // cout.put(c);
            ++cc;
            if (isspace(c)) {
                if (!isspace(fin.peek())) {
                    ++cw;
                }
                if ('\n' == c) {
                    ++cl;
                }
            }
        }
        fin.close(); // Don't forget do this!

        cout << setw(FIELD_WIDTH) << right << cl << ' ';
        cout << setw(FIELD_WIDTH) << right << cw << ' ';
        cout << setw(FIELD_WIDTH) << right << cc << ' ';
        cout << argv[i] << endl;

        // Don't initialize these variables (tcc, tcw, tcl) here.
        // Put them out of for loop.
        tcl += cl;
        tcw += cw;
        tcc += cc;
    }

    if (argc > 2) { // Print Total when files number greater than 1
        cout << setw(FIELD_WIDTH) << right << tcl << ' ';
        cout << setw(FIELD_WIDTH) << right << tcw << ' ';
        cout << setw(FIELD_WIDTH) << right << tcc << ' ';
        cout << "Total" << endl;
    }
}
