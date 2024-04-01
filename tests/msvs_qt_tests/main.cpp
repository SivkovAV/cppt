#include "qutils_tests.h"

int main(int argc, char* argv[]) {
    // join tests
    joinTestForQList();

    // fmap tests
    fmapTestWithFunctionForQList();
    fmapTestWithFunctionForQVector();
    fmapTestWithFunctorForQList();
    fmapTestWithFunctorForQVector();
    fmapConstTestWithFunctionForQList();
    fmapConstTestWithFunctionForQVector();
    fmapConstTestWithFunctorForQList();
    fmapConstTestWithFunctorForQVector();

    // sort tests
    sortTestWithFunctionForQList();
    sortTestWithFunctionForVector();
    sortTestWithFunctorForQList();
    sortTestWithFunctorForVector();

    // fold tests
    foldlTestWithFunctionForQList();
    foldlTestWithFunctionForQVector();
}
