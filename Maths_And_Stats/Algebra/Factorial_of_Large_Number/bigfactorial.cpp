/**
 * Implementation of a arbitrary precision factorial calculation program
 * note: This is neither fast, or very useful in normal code. Please use a library like Boost.Multiprecision
 * if you want arbitrary precision arithmetic.
 * 
 */ 
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cctype>

namespace algo_ds
{
    


    struct Number
    {
        std::string representation;
        //Adding digits, one by one
        Number operator+(const Number& other)
        {
            std::string outnumber;
            //get smaller and bigger number
            auto result = std::minmax(representation, other.representation, [](const auto& a, const auto& b){
                return a.size() < b.size();
            });  
            const auto& min = result.first;
            const auto& max = result.second;
                            
            //reserve the appropiate amount of memory for the result
            outnumber.resize(max.size() + 1);
            //iterators for the numbers being added
            auto back_smaller   = min.crbegin();
            auto back_bigger    = max.crbegin();
            //iterator for string            
            auto digit = outnumber.rbegin();

            //adding each digit of min and max into outnumber from the back
            char carry = 0;
            for(;back_smaller != min.crend(); back_bigger++, back_smaller++, digit++)
            {
                auto value = ((*back_smaller + *back_bigger + carry) - 2*'0') % 10;
                carry = ((*back_smaller + *back_bigger + carry) - 2*'0')/10;
                *digit = '0' + value;
            }
            //the smaller number has run out of digits, what remains is to apply the bigger number to the result + carry
            for(;back_bigger != max.crend(); back_bigger++, digit++)
            {
                auto value = (*back_bigger - '0' + carry) % 10;
                carry = (*back_bigger - '0' + carry)/10;
                *digit = '0' + value;
            }
            //since we resized to (max.size() + 1), we know there is one digit left
            *digit = '0' + carry;
            if(outnumber[0] == '0') //remove a leading 0 if it exists
            {
                outnumber.erase(outnumber.begin());
            }
            return Number{outnumber};
        }
        //Long multiplication
        Number operator*(const Number& other)
        {
            std::vector<Number> numbers;
            numbers.reserve(other.representation.size());

            std::size_t magnitude = 0; //how many 0 to add to the end of the current number
            //for each digit of the number we multiply by
            for(auto digit = other.representation.rbegin(); digit != other.representation.rend(); digit++, magnitude++)
            {
                //the resulting number -> `*this` times `digit`
                std::string number;
                //Allocate space
                number.resize(representation.size() + 1 + magnitude);              
                //add (magnitude) zeros to the end
                std::fill(number.rbegin(), number.rbegin() + magnitude, '0');

                //The number we multiply by
                auto factor = *digit - '0'; 

                //anything * 0 is 0
                if(factor == 0)
                {
                    for(auto& c : number) c = '0';
                    numbers.push_back(Number{std::move(number)});
                    continue;
                }

                //Begin calculations after the magnitude indicating zeros
                auto result = number.rbegin() + magnitude;      
                
                // iterator to the digit we multiply by `factor`
                auto multiplicand = representation.crbegin();  
                
                // The carry
                char carry = 0;                
                for(; multiplicand != representation.crend(); multiplicand++, result++)
                {
                    auto value = ((*multiplicand - '0') * factor) + carry;
                    carry = value/10;
                    *result = '0' + (value % 10);
                }   
                //since we allocated (representation.size() + magnitude + 1), `result` is valid
                *result = '0' + carry;
                //strip a possible leading 0
                if(number[0] == '0')
                {
                    number.erase(number.begin());
                }
                numbers.push_back(Number{std::move(number)});
            }
            Number result{"0"};
            for(const auto& num : numbers)
            {
                result = result + num;
            }   
            
            //strip leading characters
            auto& str = result.representation;
            auto begin = str.begin();
            while(*begin == '0' || !std::isdigit(*begin) && (begin != str.end() || begin != str.end() - 1))
            {
                begin++;
            } 
            str.erase(str.begin(), begin );
            return result;
        }
        // needed for factorial
        bool operator!=(const Number& other) const
        {
            return representation != other.representation;
        }
    };
    //it's customary to put literal operators in their own namespace
    namespace literals
    {
        //Make our life easier
        Number operator"" _N(const char* num, std::size_t)
        {
            return Number{num};
        }
    }
    using namespace algo_ds::literals;
    //Finally, the factorial function
    Number factorial(Number n)
    {    
        auto result = "1"_N;
        for(auto counter = "1"_N; counter != n + "1"_N; counter = counter + "1"_N)
        {
            result = result * counter;
        }
        return result;
    }
}
#include <iostream>
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "\nWrong usage!\n\tnote:\tExample usage: './bignum 20' -> calculates the factorial of 20\n\n";
        return 1;
    }
    std::string number{ argv[1] };
    //check whether each character is a digit
    for(auto c : number)
    {
        if(!std::isdigit(c))
        {
            std::cout << "Error! \"" << number << "\" is not a valid base-10 number!\n";
            return 1;
        }
    }
    //seperate statements due to possibly varrying order of interpretation 
    std::cout << number << "! = ";
    std::cout << algo_ds::factorial( algo_ds::Number{   std::move(number)   } ).representation << '\n';
}
