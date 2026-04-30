#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include <iterator>


template <typename Iterator1, typename Iterator2>
Iterator1 my_search(Iterator1 first1, Iterator1 last1,
    Iterator2 first2, Iterator2 last2);


template <typename Iterator1, typename Iterator2, typename Predicate>
Iterator1 my_search_if(Iterator1 first1, Iterator1 last1,
    Iterator2 first2, Iterator2 last2,
    Predicate pred);

#include "SearchAlgorithms.cpp" 

#endif