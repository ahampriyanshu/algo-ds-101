#ifndef SLNODE_H_INCLUDED
#define SLNODE_H_INCLUDED
#include "client.h"


class SLNode {
    private:
        Client data;
    public:
        SLNode*next;
        SLNode();
        SLNode( Client&);
        Client& getData();
        SLNode* getNext();
        void setData(   Client&);
        void setNext(  SLNode*);
    };
#endif // SLNODE_H_INCLUDED
