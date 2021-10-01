#include "dlnode.h"
DLNode::DLNode() {
    prev = next = nullptr;
    dataPtr = nullptr;
    }
DLNode::~DLNode(){
    delete dataPtr;
}


DLNode::DLNode(Agent& s):DLNode() {
    dataPtr = new Agent(s);

    if(dataPtr == nullptr) {
        throw NodeException("Memoria no disponible al inicializar nodo");
        }
    }

Agent* DLNode::getDataPtr() {
    return dataPtr;
    }

Agent& DLNode::getData() {
    if(dataPtr==nullptr) {
        throw NodeException("Dato Inexistente, o memoria no disponible")
        }

    return *dataPtr;
    }

DLNode* DLNode::getPrev() {
    return prev;
    }

DLNode* DLNode::getNext() {
    return next;
    }
void DLNode::setDataPtr(Agent*p) {
    dataPtr = p;
    }


void DLNode::setData(Agent&s) {
    if(dataPtr == nullptr) {
        dataPtr = new Agent(s);
        if(dataPtr == nullptr) {
            throw NodeException("Memoria no disponible al inicializar nodo");
            }
        }

    else {
        *dataPtr = s;
        }
    }
void DLNode::setPrev( DLNode*p) {
    prev = p;
    }
void DLNode::setNext( DLNode*n) {
    next = n;
    }

