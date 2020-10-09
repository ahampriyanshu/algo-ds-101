#include"slnode.h"
SLNode::SLNode() {
    next = nullptr;
    }
SLNode::SLNode( Client&s): SLNode() {
    data = s;
    }
Client& SLNode::getData() {
    return data;
    }
SLNode* SLNode::getNext() {
    return next;
    }
void SLNode::setData( Client&s) {
    data=s;
    }
void SLNode::setNext(SLNode*p) {
    next=p;
    }
