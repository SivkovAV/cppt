#include "local_utils.h"
#include <string>

void addOne(int &value) {
    value += 1;
};

std::string intToString(int const& value) {
    return std::to_string(value);
};

int fooToInt(FooStruct const& a) {
    return a.intValue;
};

int addToSum(int const& sum, double const&  n) {
    return sum + static_cast<int>(round(n));
};