#include <vector>
#include <array>
#include <cstddef>
#include <iostream>
#include <exception>
#include <string>

template<typename T> class Matrix {
    std::vector<std::vector<T>> data;
public:

    Matrix(std::vector<std::vector<T>> dataArray) {
        data = dataArray;
    }

    Matrix(size_t row, size_t col) {
        data = std::vector<std::vector < T >> (row, std::vector<T>(col, 0));
        ;
    }

    T& operator[](std::array<size_t, 2> index) {
        size_t row = index[0];
        size_t column = index[1];
        return data[row][column];
    }

    size_t rowCount() {
        return data.size();
    }

    size_t columnCount() {
        return data[0].size();
    }

    std::string toString() {
        std::string r = "{";
        for (size_t y = 0; y < rowCount(); y++) {
            r += '{';
            for (size_t x = 0; x < columnCount(); x++) {

                r += std::to_string((*this)[{y, x}]);
                if (x != columnCount() - 1)r += ',';
            }
            r+='}';
            if (y != rowCount() - 1)r += ',';
        }
        r += '}';
        return r;
    }
};

template<typename T>
Matrix<T> operator*(Matrix<T> &a, Matrix<T> &b) {
    if (a.columnCount() != b.rowCount()) throw std::invalid_argument("Must be multiplication between matrixes MxN and NxP");
    Matrix<T> r(a.rowCount(), b.columnCount());
    int sharedVal = a.columnCount();
    for (size_t i = 0; i < r.rowCount(); i++)
        for (size_t j = 0; j < r.columnCount(); j++)
            for (size_t n = 0; n < sharedVal; n++) {
                r[{i, j}] += a[{i, n}] * b[{n, j}];
            }
    return r;
}

int main() {
    int m, n, p;
    std::cout << "insert m, n, and p: ";
    std::cout.flush();
    std::cin >> m;
    std::cin >> n;
    std::cin >> p;
    Matrix<float> a(m, n);
    for (size_t y = 0; y < m; y++) {
        for (size_t x = 0; x < n; x++) {
            std::cout << "a(" << y << ',' << x << "): ";
            std::cout.flush();
            std::cin >> a[{y, x}];
        }
    }
    Matrix<float> b(n, p);
    for (size_t y = 0; y < n; y++) {
        for (size_t x = 0; x < p; x++) {
            std::cout << "b(" << y << ',' << x << "): ";
            std::cout.flush();
            std::cin >> b[{y, x}];
        }
    }
    Matrix<float> r = a*b;
    std::cout << "a: " << a.toString() << std::endl;
    std::cout << "b: " << b.toString() << std::endl;
    std::cout << "r: " << r.toString() << std::endl;
}