#ifndef CEXCEP
#define __ERRORS__

#include <exception>
using namespace std;

struct myOwnError: public exception {
    const char* what() const throw() {
        return "dahlah saya sudah lelah\n";
    }
};

#endif