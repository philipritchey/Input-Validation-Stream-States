#include "functions.hpp"

/*
TODO(student): complete the definition of the functions
    std::istream& getint(std::istream&, int&);
    std::istream& getdouble(std::istream&, double&);
    std::istream& getbool(std::istream&, bool&);
that attempt to read a value (of the specified type) from the specified input stream and throw a std::runtime_error if the input is invalid.
note: no need to "recover" the stream
*/

std::istream& getint(std::istream& input_stream, int& value) {
    input_stream >> value;
    return input_stream;
}

std::istream& getdouble(std::istream& input_stream, double& value) {
    input_stream >> value;
    return input_stream;
}

std::istream& getbool(std::istream& input_stream, bool& value) {
    input_stream >> value;
    return input_stream;
}
