#include <iostream>
#include <vector>
#include "SearchAlgorithms.h"


struct ModuloCompare
{
    bool operator()(int a, int b) const
    {
        return (a % 10) == (b % 10);
    }
};

int main()
{
    std::vector<int> data = { 11, 22, 33, 44, 55, 66 };
    std::vector<int> pattern = { 33, 44 };


    auto it = my_search(data.begin(), data.end(),
        pattern.begin(), pattern.end());

    if (it != data.end())
        std::cout << "Found (search) at position: "
        << std::distance(data.begin(), it) << std::endl;
    else
        std::cout << "Not found (search)" << std::endl;

   
    std::vector<int> pattern2 = { 3, 4 };

    auto it2 = my_search_if(data.begin(), data.end(),
        pattern2.begin(), pattern2.end(),
        ModuloCompare());

    if (it2 != data.end())
        std::cout << "Found (search_if) at position: "
        << std::distance(data.begin(), it2) << std::endl;
    else
        std::cout << "Not found (search_if)" << std::endl;

    return 0;
}