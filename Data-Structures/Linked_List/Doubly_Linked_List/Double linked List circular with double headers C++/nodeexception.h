#ifndef NODEEXCEPTION_H_INCLUDED
#define NODEEXCEPTION_H_INCLUDED
#include <exception>
#include <string>
class NodeException : public std::exception {
    private:
        std::string msg;
    public:
        explicit NodeException(const char* message) : msg(message) {}
        explicit NodeException(const std::string& message) : msg(message) {}
        NodeException() throw () {}
        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };
template <class T, int arraySize = 1024>
class Node {
    private:
        T data[arraySize];
        int last;
        bool isPosValidate(int);
    public:
        Node();
    };



#endif // NODEEXCEPTION_H_INCLUDED
