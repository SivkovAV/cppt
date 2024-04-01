#include "utils_tests.h"
#include <cassert>
#include "cppt_utils.h"
#include "local_utils.h"
#include <string>
// supported container types
#include <array>
#include <vector>
#include <list>

using namespace cppt;

// -- join tests ------------------------------------------

void joinTestForEmptyStdArray() {
    const std::array<std::string, 0> src{};

    const auto dst = join(std::string("\r\n"), src);

    assert(dst == "");
}

void joinTestForEmptyStdVector() {
    const std::vector<std::string> src{};

    const auto dst = join(std::string("\r\n"), src);

    assert(dst == "");
}

void joinTestForStdVector() {
    const std::vector<std::string> src{ "str1", "str2", "str3" };

    const auto dst = join(std::string("\r\n"), src);

    assert(dst == "str1\r\nstr2\r\nstr3");
}

void joinTestForStdList() {
    const std::list<std::string> src{ "rootDir", "midDir", "filename.ext" };
    const std::string res{ "rootDir/midDir/filename.ext" };

    const auto dst = join(std::string("/"), src);

    assert(dst == res);
}

// -- fmap tests ------------------------------------------

void fmapTestWithFunctionForStdVector() {
    std::vector<int> src{ 1, 2, -4, 6 };
    const std::vector<int> res{ 2, 3, -3, 7 };

    fmap(src, addOne);

    assert(src == res);
}

void fmapTestWithFunctionForStdList() {
    std::list<int> src{ 1, 2, -4, 6 };
    const std::list<int> res{ 2, 3, -3, 7 };

    fmap(src, addOne);

    assert(src == res);
}

void fmapTestWithFunctorForStdVector() {
    std::vector<int> src{ 1, 2, -4, 6 };
    const std::vector<int> res{ 2, 3, -3, 7 };

    fmap(src, [=](int &i) {return addOne(i); });

    assert(src == res);
}

void fmapTestWithFunctorForStdList() {
    std::list<int> src{ 1, 2, -4, 6 };
    const std::list<int> res{ 2, 3, -3, 7 };

    fmap(src, [=](int &i) {return addOne(i); });

    assert(src == res);
}

void fmapConstTestWithFunctionForStdVector() {
    const auto src = std::vector<int>{ 1, 2, -4, 6 };
    const auto res = std::vector<std::string>{ "1", "2", "-4", "6" };

    const auto dst = fmap<std::vector<std::string>>(src, intToString);

    assert(dst == res);
}

void fmapConstTestWithFunctionForStdList() {
    const auto src = std::list<int>{ 1, 2, -4, 6 };
    const auto res = std::list<std::string>{ "1", "2", "-4", "6" };

    const auto dst = fmap< std::list<std::string>>(src, intToString);

    assert(dst == res);
}

void fmapConstTestWithFunctorForStdVector() {
    const auto src = std::vector<int>{ 1, 2, -4, 6 };
    const auto res = std::vector<std::string>{ "1", "2", "-4", "6" };

    const auto dst = fmap<std::vector<std::string>>(src, [=](int const& i) {return intToString(i); });

    assert(dst == res);
};

void fmapConstTestWithFunctorForStdList() {
    const auto src = std::list<int>{ 1, 2, -4, 6 };
    const auto res = std::list<std::string>{ "1", "2", "-4", "6" };

    const auto dst = fmap<std::list<std::string>>(src, [=](int const& i) {return intToString(i); });

    assert(dst == res);
};

// -- sort tests ------------------------------------------

void sortTestWithFunctionForStdVector() {
    const FooStruct a{"a", 0 }, b{ "b", -3 }, c{ "c", 25};
    const auto src = std::vector<FooStruct>{a, b, c};
    const auto res = std::vector<FooStruct>{b, a, c};

    const auto dst = sort(src, fooToInt);

    assert(dst == res);
}

void sortTestWithFunctorForStdVector() {
    const FooStruct a{"a", 0 }, b{ "b", -3 }, c{ "c", 25};
    const auto src = std::vector<FooStruct>{a, b, c};
    const auto res = std::vector<FooStruct>{b, a, c};

    const auto dst = sort<FooStruct>(src, [=](FooStruct const& a) {return a.intValue; });

    assert(dst == res);
}

// -- fold tests ------------------------------------------

void foldlTestWithFunctionForStdVector() {
    const auto src = std::vector<double>{1.0, -2.0, 4.1};
    const int res = 3;

    const int dst = foldl(src, 0, addToSum);

    assert(dst == res);
}

void foldlTestWithFunctionForStdList() {
    const auto src = std::list<double>{ 1.0, -2.0, 4.1 };
    const int res = 3;

    const int dst = foldl(src, 0, addToSum);

    assert(dst == res);
}

void foldlTestWithFunctorForStdVector() {
    const auto src = std::vector<double>{ 1.0, -2.0, 4.1 };
    const int res = 3;

    const int dst = foldl(src, 0, [=](int sum, double n) {return sum + static_cast<int>(round(n)); });

    assert(dst == res);
}

void foldlTestWithFunctorForStdList() {
    const auto src = std::list<double>{ 1.0, -2.0, 4.1 };
    const int res = 3;

    const int dst = foldl(src, 0, [=](int sum, double n) {return sum + static_cast<int>(round(n)); });

    assert(dst == res);
}

void foldrVSfoldlTest() {
    const auto src = std::list<char>{ 'a', 'b', 'c', 'd' };
    const std::string lRes = "abcd";
    const std::string rRes = "dcba";
    const std::string initState;
    auto foldProcessor = [=](std::string r, char n) {return r + std::string(1, n); };

    const std::string lDst = foldl(src, initState, foldProcessor);
    const std::string rDst = foldr(src, initState, foldProcessor);

    assert(lRes == lDst);
    assert(rRes == rDst);
    assert(lDst != rDst);
}
