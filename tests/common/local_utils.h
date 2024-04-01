#pragma once
#include <string>

void addOne(int &value);

std::string intToString(int const& value);

struct FooStruct {
    bool operator==(FooStruct const& f) const {
        return strcmp(stringValue, f.stringValue) == 0 && intValue == f.intValue;
    }

    char stringValue[4];
    int intValue;
};

int fooToInt(FooStruct const& a);

int addToSum(int const& sum, double const&  n);