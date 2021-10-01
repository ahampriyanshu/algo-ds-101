#ifndef SLLIST_H_INCLUDED
#define SLLIST_H_INCLUDED
#include <iostream>
#include <fstream>
#include "listexception.h"
#include "sllist.h"
#include"slnode.h"
class SLList {
    private:
        SLNode* anchor;
        bool isValidPos( SLNode*&);
    public:
        SLList();
        SLList( SLList*&);
        ~SLList();
        bool isEmpty();
        void insertData( SLNode*, Client&);
        void insertOrdered( Client);
        void deleteData( SLNode*);
        void modifyClient(SLNode*);
        SLNode* getFirsPos();
        SLNode* getLastPos();
        SLNode* getPrevPos( SLNode*&);
        SLNode* getNextPos( SLNode*&);
        SLNode* findData(Client&);
        Client& retrieve(SLNode*);
        void print();
        void deleteAll();
        void writeToDisk(const std::string&);
        void readFromDisk(const  std::string&);
    };
#endif // SLLIST_H_INCLUDED
