//
// https://www.geeksforgeeks.org/print-subsequences-string/
//

// Print all subsequences of a string

#include <string>
#include <iostream>

void print_subsequences(const std::string &str) {
    std::cout << str << ":\t";
    unsigned int i = 0;
    unsigned int window_size = 1;   //window size will grow to str.length();

    do {
        for (; i + window_size <= str.length(); i++) {
            std::cout << str.substr(i, window_size) << ", ";
        }
        i = 0;
        ++window_size;
    } while (window_size <= str.length());
    std::cout << std::endl;
}

int main() {
    print_subsequences("aba");
    print_subsequences("aaaabbaa");
    print_subsequences("abcabcbb");
    print_subsequences("bbbbb");
    print_subsequences("pwwkew");
    print_subsequences(" ");
    print_subsequences("ab");
    print_subsequences("aaaaabc");
    print_subsequences("dvadf");
    print_subsequences("nfpdmpi");
    print_subsequences("aabaab!bb");
    return 0;
}
