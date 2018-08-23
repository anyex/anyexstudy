#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string.h>
using namespace std;

//function process requests
string sed_func(const string& pattern, const string& replace, char* & filename) {

    //function result
    string result = "";

    //partial implementation of REGEX, ^ and &.
    //head string
    string hstr = "";
    //end string
    string estr = "";

    //pattern matching
    if (pattern.find('^') != string::npos) {
        hstr = pattern.substr(pattern.find('^') + 1, string::npos);
    } else if (pattern.find('&') != string::npos) {
        estr = pattern.substr(0, pattern.length() - 1);
    }

    //partial implementation of replacement, \L, \U
    string line = "";

    //read fstream
    fstream file;
    file.open(filename, ios::in);

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            if (hstr.length() > 0) {
                if (line.find(hstr) == 0) {
                    if (replace == "\\L") {
                        transform(hstr.begin(), hstr.end(), hstr.begin(),
                                ::tolower);
                        line.replace(0, hstr.length(), hstr);

                    } else if (replace == "\\U") {
                        transform(hstr.begin(), hstr.end(), hstr.begin(),
                                ::toupper);
                        line.replace(0, hstr.length(), hstr);
                    }
                }
            } else if (estr.length() > 0) {
                if (line.find_last_of(estr) == line.length() - estr.length()) {
                    if (replace == "\\L") {
                        transform(estr.begin(), estr.end(), estr.begin(),
                                ::tolower);
                        if (line.length() > 0) {
                            line.replace(line.length() - estr.length(),
                                    estr.length(), estr);
                        }

                    } else if (replace == "\\U") {
                        transform(estr.begin(), estr.end(), estr.begin(),
                                ::toupper);
                        if (line.length() > 0) {
                            line.replace(line.length() - estr.length(),
                                    estr.length(), estr);
                        }

                    }
                }
            }
            //append new line to result.
            result = result.append(line);
            result = result.append("\n");
        }
    } else {
        result = "Open file failed. \n";
    }

    return result;
}

string sed_func(const string& pattern, const string& replace) {

    //function result
    string result = "";

    //partial implementation of REGEX, ^ and &.
    //head string
    string hstr = "";
    //end string
    string estr = "";

    //pattern matching
    if (pattern.find('^') != string::npos) {
        hstr = pattern.substr(pattern.find('^') + 1, string::npos);
    } else if (pattern.find('&') != string::npos) {
        estr = pattern.substr(0, pattern.length() - 1);
    }

    //partial implementation of replacement, \L, \U
    string line = "";
    //read from cin
    string cin_line;
    for (;;) {
        //get input from keyboard and output it when a newline is entered.
        getline(cin, cin_line);

        if (hstr.length() > 0) {
            if (cin_line.find(hstr) == 0) {
                if (replace == "\\L") {
                    transform(hstr.begin(), hstr.end(), hstr.begin(), ::tolower);
                    cin_line.replace(0, hstr.length(), hstr);

                } else if (replace == "\\U") {
                    transform(hstr.begin(), hstr.end(), hstr.begin(), ::toupper);
                    cin_line.replace(0, hstr.length(), hstr);
                }
            }
        } else if (estr.length() > 0) {
            if (cin_line.find_last_of(estr) == cin_line.length()
                    - estr.length()) {
                if (replace == "\\L") {
                    transform(estr.begin(), estr.end(), estr.begin(), ::tolower);
                    if (cin_line.length() > 0) {
                        cin_line.replace(cin_line.length() - estr.length(),
                                estr.length(), estr);
                    }

                } else if (replace == "\\U") {
                    transform(estr.begin(), estr.end(), estr.begin(), ::toupper);
                    if (cin_line.length() > 0) {
                        cin_line.replace(cin_line.length() - estr.length(),
                                estr.length(), estr);
                    }

                }
            }
        }

        cout << cin_line << endl;
    }

    return result;
}

//usage:
//fixed sequence: my_sed [command] [filename|keyboard] [options]
//my_sed 's/pattern/replaced/' [filename|keyboard] [options]
//my_sed '/pattern/' [filename|keyboard] [options]
void my_sed(int argc, char* argv[]) {

    //check whether option is specified. only one option -n is required in this case.
    string option = argv[argc - 1];
    int option_on = 0;
    if (option == "-n")
        option_on = 1;

    //check read from cin (third argument is blank) or read from file.
    int cin_on = 0;
    if (argc == 3) {
        if (option_on == 1)
            cin_on = 1;
    } else if (argc < 3) {
        cin_on = 1;
    }
    //check command type: search and replace or search only
    //if command type is seach and replace, argv[1] contains at least three "/" signs.
    // and first slash sign is preceded with s, "s/"
    int cmd_type = 0;
    //convert argv[1] into a string for search purpose
    string argv1 = argv[1];

    //find the position of first / to check command validity "s/".
    size_t found_sslash;
    found_sslash = argv1.find('/');

    //count occurence of /.
    unsigned int count_slash = 0;
    count_slash = count(argv1.begin(), argv1.end(), '/');
    if (count_slash == 3 && ((found_sslash > 0) ? (argv1.at(found_sslash - 1)
            == 's') : false))
        cmd_type = 1;
    //otherwise this command is search only.

    size_t found2 = argv1.substr(found_sslash + 1, string::npos).find('/');
    size_t found3 = argv1.substr(found_sslash + found2 + 2, string::npos).find(
            '/');

    //extract pattern, replaced and filename.
    string pattern = argv1.substr(found_sslash + 1, found2);
    string replace = cmd_type == 1 ? argv1.substr(found_sslash + found2 + 2,
            found3) : "";

    //call sed_func
    string result = cin_on == 0 ? sed_func(pattern, replace, argv[2])
            : sed_func(pattern, replace);
    cout << result << endl;

}

int main(int argc, char* argv[]) {
    my_sed(argc, argv);
}
