#include "qutils_tests.h"
#include <QString>
#include "cppt_utils.h"
#include "local_utils.h"
// supported container types
#include <QList>
#include <QVector>

using namespace cppt;

// -- join tests ------------------------------------------

void joinTestForQList() {
    const auto field1 = join(QString(":"), QList<QString>{"field_name_1", "field_value_1"});
    const auto field2 = join(QString(":"), QList<QString>{"field_name_2", "field_value_2"});
    const auto content = join(QString(",\r\n"), QList<QString>{field1, field2});

    assert(content == "field_name_1:field_value_1,\r\nfield_name_2:field_value_2");
}

// -- fmap tests ------------------------------------------

void fmapTestWithFunctionForQList() {
    QList<int> src{1, 2, -4, 6};
    const QList<int> res{ 2, 3, -3, 7 };

    fmap(src, addOne);

    assert(src == res);
}

void fmapTestWithFunctionForQVector() {
    auto src = QVector<int>{ 1, 2, -4, 6 };
    const auto res = QVector<int>{ 2, 3, -3, 7 };

    fmap(src, addOne);

    assert(src == res);
}

void fmapTestWithFunctorForQList() {
    QList<int> src{ 1, 2, -4, 6 };
    const QList<int> res{ 2, 3, -3, 7 };

    fmap(src, [=](int &i) {i += 1; });

    assert(src == res);
}

void fmapTestWithFunctorForQVector() {
    auto src = QVector<int>{ 1, 2, -4, 6 };
    const auto res = QVector<int>{ 2, 3, -3, 7 };
    
    fmap(src, [=](int &i) {i += 1; });

    assert(src == res);
}

void fmapConstTestWithFunctionForQList() {
    const QList<int> src{ 1, 2, -4, 6 };
    const QList<std::string> res{ "1", "2", "-4", "6" };

    const QList<std::string> dst{fmap<QList<std::string>>(src, intToString)};

    assert(dst == res);
}

void fmapConstTestWithFunctionForQVector() {
    const QVector<int> src{ 1, 2, -4, 6 };
    const QVector<std::string> res{ "1", "2", "-4", "6" };

    const QVector<std::string> dst{fmap<QVector<std::string>>(src, intToString)};

    assert(dst == res);
}

void fmapConstTestWithFunctorForQList() {
    const QList<int> src{ 1, 2, -4, 6 };
    const QList<QString> res{ "1", "2", "-4", "6" };

    const QList<QString> dst{fmap<QList<QString>>(src, [=](int i) {return QString::number(i);})};

    assert(dst == res);
}

void fmapConstTestWithFunctorForQVector() {
    const QVector<int> src{ 1, 2, -4, 6 };
    const QVector<QString> res{ "1", "2", "-4", "6" };

    const QVector<QString> dst{fmap<QVector<QString>>(src, [=](int i) {return QString::number(i);})};

    assert(dst == res);
}

// -- sort tests ------------------------------------------

void sortTestWithFunctionForQList() {
    const FooStruct a{ "a", 0 }, b{ "b", -3 }, c{ "c", 25 };
    const auto src = QList<FooStruct>{ a, b, c };
    const auto res = QList<FooStruct>{ b, a, c };

    const auto dst = sort(src, fooToInt);

    assert(dst == res);
}

void sortTestWithFunctionForVector() {
    const FooStruct a{ "a", 0 }, b{ "b", -3 }, c{ "c", 25 };
    const auto src = QVector<FooStruct>{ a, b, c };
    const auto res = QVector<FooStruct>{ b, a, c };

    const auto dst = sort(src, fooToInt);

    assert(dst == res);
}

void sortTestWithFunctorForQList() {
    const FooStruct a{ "a", 0 }, b{ "b", -3 }, c{ "c", 25 };
    const auto src = QList<FooStruct>{ a, b, c };
    const auto res = QList<FooStruct>{ b, a, c };

    const auto dst = sort<FooStruct>(src, [=](FooStruct const& fs) {return fs.intValue;});

    assert(dst == res);
}

void sortTestWithFunctorForVector() {
    const FooStruct a{ "a", 0 }, b{ "b", -3 }, c{ "c", 25 };
    const auto src = QVector<FooStruct>{ a, b, c };
    const auto res = QVector<FooStruct>{ b, a, c };

    const auto dst = sort<FooStruct>(src, [=](FooStruct const& fs) {return fs.intValue;});

    assert(dst == res);
}

// -- fold tests ------------------------------------------

void foldlTestWithFunctionForQList() {
    const auto src = QList<double>{ 1.0, -2.0, 4.1 };
    const int res = 3;

    const int dst = foldl(src, 0, addToSum);

    assert(dst == res);
}

void foldlTestWithFunctionForQVector() {
    const auto src = QVector<double>{ 1.0, -2.0, 4.1 };
    const int res = 3;

    const int dst = foldl(src, 0, addToSum);

    assert(dst == res);
}