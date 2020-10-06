// Nothing Special

#include <iostream>
#include <cinttypes>

int main() {
    std::ios_base::sync_with_stdio(false) , std::cin.tie(nullptr);

    int32_t t1 = 0 , t2 = 1 , next_term;
    
    int32_t n;  std::cin >> n;

    puts("Fibonacci Series ...");

    for (int32_t i = 0; i <= n; i++) {
        std::cout << t1 << "\t";
        next_term = t1 + t2;
        t1 = t2;
        t2 = next_term;
    }
    std::cout << std::endl;
    return 0;
}
