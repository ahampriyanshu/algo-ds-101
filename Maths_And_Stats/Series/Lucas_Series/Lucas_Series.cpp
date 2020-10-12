#include <iostream>
using namespace std;

int main() {

    int term_1 = 2;
    int term_2 = 1;
    int next_term;
    
    int num_terms;  
    cout << "Number of terms to be found: ";
    cin >> num_terms;

    cout << "The first " << num_terms << " of the Lucas Series are:\n";

    for (int i = 1; i <= num_terms; i++) {
        cout << term_1 << "\t";
        next_term = term_1 + term_2;
        term_1 = term_2;
        term_2 = next_term;
    }
    
    cout << "\n";
}