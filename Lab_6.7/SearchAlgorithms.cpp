#ifndef SEARCH_ALGORITHMS_CPP
#define SEARCH_ALGORITHMS_CPP

template <typename Iterator1, typename Iterator2>
Iterator1 my_search(Iterator1 first1, Iterator1 last1,
    Iterator2 first2, Iterator2 last2)
{
    if (first2 == last2) return first1; 

    for (; first1 != last1; ++first1)
    {
        Iterator1 it1 = first1;
        Iterator2 it2 = first2;

        while (it1 != last1 && it2 != last2 && *it1 == *it2)
        {
            ++it1;
            ++it2;
        }

        if (it2 == last2) 
            return first1;

        if (it1 == last1)
            return last1;
    }

    return last1;
}


template <typename Iterator1, typename Iterator2, typename Predicate>
Iterator1 my_search_if(Iterator1 first1, Iterator1 last1,
    Iterator2 first2, Iterator2 last2,
    Predicate pred)
{
    if (first2 == last2) return first1;

    for (; first1 != last1; ++first1)
    {
        Iterator1 it1 = first1;
        Iterator2 it2 = first2;

        while (it1 != last1 && it2 != last2 && pred(*it1, *it2))
        {
            ++it1;
            ++it2;
        }

        if (it2 == last2)
            return first1;

        if (it1 == last1)
            return last1;
    }

    return last1;
}

#endif