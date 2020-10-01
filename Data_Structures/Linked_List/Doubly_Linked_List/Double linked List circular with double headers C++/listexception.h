#ifndef ListException_H_INCLUDED
#define ListException_H_INCLUDED
#include <exception>
#include <string>

class ListException : public std::exception {
    private:
        std::string msg;
    public:
        explicit ListException(const char* message) : msg(message) {}
        explicit ListException(const std::string& message) : msg(message) {}
        ~ListException() throw () {}
        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };
template <class T, int arraySize = 1024>
class List {
    private:
        T data[arraySize];
        int last;
        bool isPosValidate(int);
    public:
        List();
    };
#endif // ListException_H_INCLUDED

