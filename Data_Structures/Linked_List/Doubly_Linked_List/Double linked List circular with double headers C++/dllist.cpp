#include "dllist.h"



DLList::DLList() {
    header = new DLNode;
    if(header == nullptr) {
        throw ListException("Memoria no disponible an inicializar la lista");

        }
    header ->setPrev(header);
    header ->setNext(header);
    }

bool DLList::isEmpty() {

    return header->getNext() == header;
    }


void DLList::print() {
    DLNode* aux = header->getNext();
    while(aux != header) {
        aux->getData().toString();
        aux = aux->getNext();
        }
    }


DLNode* DLList::insertData(DLNode *p, Agent&e) {
    if(p != nullptr && !isValidPos(p)) {

        throw ListException("Posicion invalida al tratar de insertar");
        }
    if(p == nullptr) {

        p = header;
        }
    DLNode* aux;
    try {
        aux= new DLNode(e);
        }
    catch(NodeException ex) {

        throw ListException(ex.what());
        }

    if(aux == nullptr) {
        throw ListException("Memoria no disponible al insertar");
        }
    if(p == nullptr) {
        aux->setPrev(nullptr);
        aux->setNext(header);

        if(header != nullptr) {
            header->setPrev(aux);
            }
        header=aux;
        }
    else {
        aux->setPrev(p);
        aux->setNext(p->getNext());
        if(p->getNext() != nullptr) {
            p->getNext()->setPrev(aux);
            }

        p->setNext(aux);
        }

    return aux;

    }


bool DLList::isValidPos(DLNode* p) {
    if(p == nullptr || isEmpty()) {
        return false;
        }
    DLNode* aux=header;
    do {
        if(aux==p) {
            return true;
            }
        aux = aux->getNext();
        }
    while(aux != header);
    return false;
    }
///*******

DLNode *DLList::getPrevPos(DLNode*p) {
    if(!isValidPos(p)||p==header->getNext()) {
        return nullptr;
        }
    return p->getPrev();

    }

DLNode *DLList::getNextPos(DLNode* p) {
    if(!isValidPos(p)||p==header->getPrev()) {
        return nullptr;
        }
    return p->getNext();
    }

DLNode *DLList::findData(Agent& e) {
    DLNode* aux= header->getNext();
    while(aux!= header) {
        if(aux->getData()== e) {
            return aux;
            }
        aux=aux->getNext();
        }
    return nullptr;

    }

void DLList::deleteData(DLNode*p) {
    if(!isValidPos(p)) {
        throw ListException("Posiccion no valida al tratar de eliminar");
        }
    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());

    delete p;
    }
void DLList::deleteAll() {
    DLNode* aux;
    while(header->getNext()!= header) {
        aux= header->getNext();
        header->setNext(header->getNext()->getNext());

        delete aux;
        }
    header->setNext(header);

    }
DLList::~DLList() {
    deleteAll();
    delete header;
    }

DLList::DLList(DLList& l) : DLList() {
    DLNode* aux= l.header->getNext();
    while(aux != l.header) {
        insertData(getLastPos(), aux->getData());
        aux=aux->getNext();
        }
    }
///*******

DLNode* DLList::getFirstPos() {
    if(isEmpty()) {
        return nullptr;
        }
    return header -> getNext();
    }
DLNode* DLList::getLastPos() {
    if(isEmpty()) {
        return nullptr;
        }
    return header -> getPrev();
    }

Agent& DLList::retrieve(DLNode* p) {
    if(!isValidPos(p)) {
        throw ListException("Posicion invalida al usar retrieve ");
        }
    return p->getData();
    }


void DLList::sortByName() {
    sortByName(getFirstPos(),getLastPos());

    }

void DLList::sortByDepartment() {

    sortByDepartment(getFirstPos(),getLastPos());

    }

void DLList::exchange(DLNode*a, DLNode*b) {

    Agent* aux = a->getDataPtr();
    a->setDataPtr(b->getDataPtr());
    b->setDataPtr(aux);

    }

void DLList::sortByName(DLNode*leftP, DLNode*rightP) {
    if(leftP==rightP) {
        return;
        }

    DLNode* pivot = rightP;
    DLNode* i= leftP;
    DLNode* j= rightP;

    while(i != j) {
        while(i != j && i->getData().getName()<=pivot->getData().getName()) {
            i = i->getNext();
            }
        while(i != j && j->getData().getName()>=pivot->getData().getName()) {
            j = j->getPrev();
            }
        if(i != j) {
            exchange(i,j);
            }

        }
    if(i != pivot) {
        exchange(i,pivot);
        }
    if(i != leftP) {
        sortByName(leftP, i->getPrev());
        }
    if(i != rightP) {
        sortByName(i->getNext(),rightP);
        }

    }
void DLList::sortByDepartment(DLNode*leftP, DLNode*rightP) {
    if(leftP==rightP) {
        return;
        }

    DLNode* pivot = rightP;
    DLNode* i= leftP;
    DLNode* j= rightP;

    while(i != j) {
        while(i != j and i->getData().getDepart()<=pivot->getData().getDepart()) {
            i = i->getNext();
            }
        while(i != j and j->getData().getDepart()>=pivot->getData().getDepart()) {
            j = j->getPrev();
            }
        if(i != j) {
            exchange(i,j);
            }

        }
    if(i != pivot) {
        exchange(i,pivot);
        }
    if(i != leftP) {
        sortByDepartment(leftP, i->getPrev());
        }
    if(i != rightP) {
        sortByDepartment(i->getNext(),rightP);
        }

    }

void DLList::writeToDisk(const std::string& fileName) {
    std::ofstream myFile;

    myFile.open(fileName, myFile.trunc);
    if(!myFile.is_open()) {
        throw ListException("No se pudo Abrir el Archivo"+ fileName + "Para escritura");
        }
    DLNode* aux = header->getNext();
    while(aux != header) {
        myFile << aux->getData()<<std::endl;

        aux->getData().getClientList().writeToDisk(aux->getData().getAgentNum());

        aux=aux->getNext();
        }
    myFile.close();

    }
void DLList::readFromDisk(const std::string& fileName) {
    std::ifstream myFile;
    Agent myAgent;
    DLNode* myPos;

    myFile.open(fileName);
    if(!myFile.is_open()) {
        throw ListException("No se pudo Abrir el Archivo"+ fileName + "Para escritura");
        }

    deleteAll();

    while(myFile>>myAgent) {
        myPos=insertData(getLastPos(), myAgent);

        myPos->getData().getClientList().readFromDisk(myAgent.getAgentNum());
        }
    myFile.close();
    }

