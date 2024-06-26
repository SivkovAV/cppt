#include "utils_tests.h"

int main()
{
    // join
    joinTestForEmptyStdArray();
    joinTestForEmptyStdVector();
    joinTestForStdVector();
    joinTestForStdList();

    // fmap
    fmapTestWithFunctionForStdVector();
    fmapTestWithFunctionForStdList();
    fmapTestWithFunctorForStdVector();
    fmapTestWithFunctorForStdList();
    fmapConstTestWithFunctionForStdVector();
    fmapConstTestWithFunctionForStdList();
    fmapConstTestWithFunctorForStdVector();
    fmapConstTestWithFunctorForStdList();

    // sort
    sortTestWithFunctionForStdVector();
    sortTestWithFunctorForStdVector();

    // fold
    foldlTestWithFunctionForStdVector();
    foldlTestWithFunctionForStdList();
    foldlTestWithFunctorForStdVector();
    foldlTestWithFunctorForStdList();
    foldrVSfoldlTest();
}
