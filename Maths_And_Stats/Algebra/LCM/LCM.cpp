#include <type_traits>
namespace algo_ds
{
    /*
     * The implementation are kinda cryptic. I will try my best to explain what all the template stuff means
     * First off, both lcm and gcd are function templates, taking `a` of type T and `b` of type U
     * 
     * If both T and U are the same, the return type is gonna be just that, otherwise, std::common_type_t comes in.
     * std::common_type_t does some hackery, and gives us a type both T and U are convertible to. If such a type
     * doesn't exist... there's gonna be some template errors (although on clang 10.1 at least, they are pretty good)
     * 
     * the noexcept basically means, that if T and U are primitives, i.e. [int, long, unsigned, char] etc., it is guaranteed
     * the "functions" won't throw an exception
     */


    //implementation for a gcd function template in C++ 14
    template<typename T, typename U>
    [[nodiscard]] constexpr std::common_type_t<T, U> gcd(const T& a, const U& b) noexcept(std::is_integral<T>::value && std::is_integral<U>::value)
    {
        if (a == 0)
        {
          return b;
        }
        return gcd(b % a, a); 
    }
    //implementation for a lcm function template in C++ 14
    template<typename T, typename U>           
    [[nodiscard]] constexpr std::common_type_t<T, U> lcm(const T& a, const U& b) noexcept(std::is_integral<T>::value && std::is_integral<U>::value)
    {
        return (a / gcd(a, b)) * b;
    }
}

/**
 * Prints a nice table, the output should look like this:
 
 
    Table of the least common multiples for the pairs in the range 1-9:
    
        1 |    2     3     4     5     6     7     8     9 
    ______________________________________________________
        2 |    2     6     4    10     6    14     8    18 
        3 |    6     3    12    15     6    21    24     9 
        4 |    4    12     4    20    12    28     8    36 
        5 |   10    15    20     5    30    35    40    45 
        6 |    6     6    12    30     6    42    24    18 
        7 |   14    21    28    35    42     7    56    63 
        8 |    8    24     8    40    24    56     8    72 
        9 |   18     9    36    45    18    63    72     9 
 
 */ 
#include <iostream>
#include <iomanip>
int main()
{
    std::cout << "Table of the least common multiples for the pairs in the range 1-9:\n\n";
    for(auto i = 1; i < 10; i++)
    {
        //Make the table look pretty by giving it a border
        if(i == 2)
        {
            for(auto j = 0; j < 6*9; j++)
            {
                std::cout << '_';
            }
            std::cout << '\n';
        }
        for(auto j = 1; j < 10; j++)
        {
            //setw() to align the numbers in the table
            std::cout << std::setw(5) << algo_ds::lcm(i, j) << ' ';
            if(j == 1) //again, making a border
            {
                std::cout << '|';
            }
        }
        std::cout << '\n';
    }
}
