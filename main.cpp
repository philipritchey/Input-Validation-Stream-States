#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "functions.hpp"

// TODO(student): goto functions.cpp

// DO NOT CHANGE ANY OF THIS CODE

// a generic function for calling the user-defined get* functions and producing output for I/O tests
template <typename T>
std::istream& do_getT(std::istream&(*getT_func)(std::istream&,T&), std::istream& input_stream, T& value) {
    try {
        // e.g. "getint(input_stream, value);"
        getT_func(input_stream, value);
        std::cout << value << std::endl;
    } catch (const std::runtime_error& err) {
        std::cout << "invalid" << std::endl;
    }
    
    return input_stream;
}

// the main program driver that parses the test input
int main() {
    std::string function, stream;
    std::cin >> function >> stream;
    
    // this block takes advantage of polymorphism to reduce code duplication / simply the code
    std::istream* input_stream;
    std::istringstream sin;
    std::ifstream fin;
    if (stream == "cin") { 
        input_stream = &std::cin;
    } else if (stream.front() == '"') { 
        if (stream.back() != '"') {
            std::cout << "missing expected '\"' at end of string: " << stream << std::endl;
            return 1;
        }
        // set the contents of the stream
        sin.str(stream.substr(1, stream.length()-2));
        input_stream = &sin;
    } else {
        // open the file
        fin.open(stream);
        if (!fin.is_open()) {
            std::cout << "could not open file: " << stream << std::endl;
            return 1;
        }
        input_stream = &fin;
    }
    
    // this block does the right thing
    if (function == "getint") {
        int i;
        do_getT(&getint, *input_stream, i);
    } else if (function == "getdouble") {
        double d;
        do_getT(&getdouble, *input_stream, d);
    } else if (function == "getbool") {
        bool b;
        do_getT(&getbool, *input_stream, b);
    } else {
        std::cout << "error: "<<function<< " is undefined" << std::endl;
    }
    
    return 0;
}
