#ifndef DLNODE_H_INCLUDED
#define DLNODE_H_INCLUDED
#include "agent.h"
#include "nodeexception.h"
class DLNode {
    private:
        Agent* dataPtr;
        DLNode*prev;
        DLNode*next;

    public:
        DLNode();
        DLNode(Agent&);
        ~DLNode();


        Agent* getDataPtr();
        Agent& getData();
        DLNode* getNext();
        DLNode* getPrev();

        void setDataPtr(Agent*);
        void setData(  Agent&);
        void setNext(  DLNode*);
        void setPrev(  DLNode*);

    };
#endif // DLNODE_H_INCLUDED
