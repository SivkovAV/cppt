#pragma once

// join
void joinTestForEmptyStdArray();
void joinTestForEmptyStdVector();
void joinTestForStdVector();
void joinTestForStdList();

// fmap
void fmapTestWithFunctionForStdVector();
void fmapTestWithFunctionForStdList();
void fmapTestWithFunctorForStdVector();
void fmapTestWithFunctorForStdList();
void fmapConstTestWithFunctionForStdVector();
void fmapConstTestWithFunctionForStdList();
void fmapConstTestWithFunctorForStdVector();
void fmapConstTestWithFunctorForStdList();

// sort
void sortTestWithFunctionForStdVector();
void sortTestWithFunctorForStdVector();

// fold
void foldlTestWithFunctionForStdVector();
void foldlTestWithFunctionForStdList();
void foldlTestWithFunctorForStdVector();
void foldlTestWithFunctorForStdList();
void foldrVSfoldlTest();
