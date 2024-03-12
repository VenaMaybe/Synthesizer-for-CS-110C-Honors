#ifndef VENA_UTILITY_H
#define VENA_UTILITY_H

#include <iostream>

// A utility function to print a string

// Flag for no final endl!
struct NoEndl {};

// Handling the NoEndl flag!
inline void print(const NoEndl&) {
    // Intentionally empty: do not print a newline when this overload is invoked
}

// Base case for the variadic template print function
inline void print() {
    // Prints newline when there are no more arguments
    std::cout << std::endl;
}

template<typename T, typename... Args>
inline void print(const T &firstArg, const Args &... args) {
    std::cout << firstArg;
    // A recursive call on all the arguments (I think)
    print(args...);
}

#endif // VENA_UTILITY_H