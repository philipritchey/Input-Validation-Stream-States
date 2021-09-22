#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "functions.hpp"

/*
TODO(student): define functions
    std::istream& getint(std::istream&, int&);
    std::istream& getdouble(std::istream&, double&);
    std::istream& getbool(std::istream&, bool&);
that attempt to read a value (of the specified type) from the specified input stream and throw a std::runtime_error if the input is invalid.
note: no need to "recover" the stream
*/

// DO NOT CHANGE ANY OF THIS CODE

// a generic function for calling the user-defined get* functions and producing output for I/O tests
template <typename T>
std::istream& do_getT(std::istream&(*getT_func)(std::istream&,T&), std::istream& input_stream, T& value) {
    try {
        // getint(input_stream, value);
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
    
    // take advantage of polymorphism to reduce code duplication / simply the code
    std::istream* input_stream;
    if (stream == "cin") { 
        input_stream = &std::cin;
    } else if (stream.front() == '"') { 
        if (stream.back() != '"') {
            std::cout << "missing expected '\"' at end of string: " << stream << std::endl;
            return 1;
        }
        std::istringstream sin(stream.substr(1, stream.length()-2));
        input_stream = &sin;
    } else {
        std::ifstream fin(stream);
        if (!fin.is_open()) {
            std::cout << "could not open file: " << stream << std::endl;
            return 1;
        }
        input_stream = &fin;
    }
    
    // do the right thing
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
