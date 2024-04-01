#pragma once
/*
// (c) Copyright Aleksei Sivkov 2024
Syntctic sugar for c++
*/
#include <string>
#include <algorithm> // std::sort(), std::transform(), std::reverse()
#include <numeric>   // std::accumulate()

namespace cppt{

// -- join ------------------------------------------------

template <typename StringContainerT, typename StringT>
StringT join(StringT const&separator, StringContainerT const& strings)
{
    if (strings.size() == 0) {
        return StringT();
    }
    const auto beginIterator = strings.begin();
    StringT result = *beginIterator;
    for (auto it = std::next(beginIterator); it != strings.end(); it++) {
        result += separator + *it;
    }
    return result;
}
  
// -- fmap ------------------------------------------------

template <typename ContainerTypeT, typename ItemT>
void fmap(ContainerTypeT & items, void(*transformFunction)(ItemT &)) {
    for (auto it = items.begin(); it != items.end(); it++) {
        transformFunction(*it);
    }
}

template <typename ContainerTypeT, typename TransformFunctorT>
void fmap(ContainerTypeT & items, TransformFunctorT const& transformFunctor) {
    for (auto it = items.begin(); it != items.end(); it++) {
        transformFunctor.operator()(*it);
    }
}

template <
    typename DstContainerT,
    typename SrcContainerT,
    typename TransformFunctor>
    DstContainerT fmap(SrcContainerT const& items, TransformFunctor const& transformFunctor) {
    DstContainerT result;
    std::transform(items.begin(), items.end(), std::back_inserter(result), transformFunctor);
    return result;
}

// -- sort ------------------------------------------------

template <typename ContainerType, typename ItemType, typename CompareType>
ContainerType sort(ContainerType const& items, CompareType(*transformFunction)(ItemType const& item), bool reverse = false) {
    ContainerType dstItems = items;
    std::sort(dstItems.begin(), dstItems.end(), [=](ItemType const& a, ItemType const& b) {
        if (reverse) {
            return transformFunction(a) >= transformFunction(b);
        }
        return transformFunction(a) < transformFunction(b);
    });
    return dstItems;
}

template <typename ItemType, typename ContainerType, typename TransformFunctorT>
ContainerType sort(ContainerType const& items, TransformFunctorT const& transformFunctor, bool reverse = false) {
    ContainerType dstItems = items;
    std::sort(dstItems.begin(), dstItems.end(), [=](ItemType const& a, ItemType const& b) {
        if (reverse) {
            return transformFunctor(a) >= transformFunctor(b);
        }
        return transformFunctor(a) < transformFunctor(b);
    });
    return dstItems;
}

// -- fold ------------------------------------------------

#define foldl(items, beginAccumalator, functor) \
     std::accumulate(items.begin(), items.end(), beginAccumalator, functor)

#define fold foldl

template <typename ItemContainerT, typename ItemT, typename FunctorT>
ItemT foldr(ItemContainerT const& items, ItemT const& beginAccumalator, FunctorT functor) {
    auto reversedItems = items;
    std::reverse(reversedItems.begin(), reversedItems.end());
    return foldl(reversedItems, beginAccumalator, functor);
}

} // namespace cppt