#ifndef DLLIST_H_INCLUDED
#define DLLIST_H_INCLUDED
#include <iostream>
#include <fstream>
#include "listexception.h"
#include"dlnode.h"
#include"agent.h"
class DLList {
    private:
        DLNode* header;
        bool isValidPos(DLNode*);
        void exchange(DLNode*, DLNode*);
        void sortByName(DLNode*, DLNode*);
        void sortByDepartment(DLNode*, DLNode*);

    public:
        DLList();
        DLList(DLList&);
        ~DLList();

        bool isEmpty();

        DLNode* insertData(DLNode*,Agent&);
        void deleteData(  DLNode*);

        DLNode*  getFirstPos();
        DLNode*  getLastPos();
        DLNode*  getPrevPos( DLNode*);
        DLNode*  getNextPos( DLNode*);
        DLNode*  findData(Agent&);
        void deleteAll();

        Agent& retrieve( DLNode*);

        void sortByName();
        void sortByDepartment();

        void print();
        void writeToDisk(const std::string&);
        void readFromDisk(const  std::string&);

    };

#endif // DLLIST_H_INCLUDED
