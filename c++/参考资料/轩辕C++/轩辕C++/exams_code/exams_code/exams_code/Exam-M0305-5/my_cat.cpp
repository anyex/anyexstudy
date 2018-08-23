/*
 * my_cat.cpp
 *
 *  Created on: Sep 18, 2012 10:18:18 AM
 *      Author: kwarph
 *         Web: http:://www.xuanyuan-soft.cn
 *        Mail: kwarph@163.com
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
	bool printLN = false;
	if (argc > 1 && ((strcmp(argv[1], "-n") == 0))) {
		printLN = true;
	}

	string line;
	if (1 == argc || (2 == argc && printLN)) {
		// No arguments, or only one argument "-n", get content from stdin
		vector<string> content;
		while (getline(cin, line)) {
			content.push_back(line);
		}

		const size_t sz = content.size();
		for (size_t i = 0; i < sz; ++i) {
			if (printLN)
				cout << setw(8) << right << i + 1 << ' ';
			cout << content[i] << endl;
		}
	} else { // read files
		int nf = 1 + printLN;
		ifstream fin;
		for (; nf < argc; ++nf) {
			fin.open(argv[nf], ios::in | ios::binary);
			if (!fin) {
				cerr << '\n' << argv[nf] << ": No such file or directory\n";
				fin.close();
			} else {
				int i = 0;

				cout << '\n' << argv[nf] << ":\n";
				while (getline(fin, line)) {
					if (printLN)
						cout << setw(8) << right << ++i << ' ';
					cout << line << endl;
				}
				fin.close();
			}
			fin.clear();
		}
	}
}

