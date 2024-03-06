#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

// A utility function to print a string
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

#endif // UTILITY_H