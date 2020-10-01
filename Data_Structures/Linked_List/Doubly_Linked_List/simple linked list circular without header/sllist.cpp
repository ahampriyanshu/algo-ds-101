#include "sllist.h"


void SLList::modifyClient(SLNode* p) {
    if(!isValidPos(p)) {
        throw ListException("Posicion invalida a la elminar");
        }
    if(p==anchor) {
        anchor= anchor-> getNext();
        }
    else {
        getPrevPos(p) -> setNext(p->getNext());
        }
    delete p;
    }

SLNode* SLList::getPrevPos( SLNode*& p) {
    if(isEmpty() or p==anchor) {
        return nullptr;
        }
    SLNode* aux = anchor;
    do {
        if(aux->getNext()==p) {
            return aux;
            }
        aux= aux->getNext()


        }
    while(aux != anchor);
    return nullptr;

    }

void SLList::deleteData( SLNode* p) {
    if(!isValidPos(p)) {
        throw ListException("Posicion invalida al eliminar");
        }
    if (p == anchor) {
        if(p->getNext()==p) {
            anchor =nullptr;
            }
        else {
            getLastPos()->getNext(anchor->getNext());
            anchor = anchor->getNext();
            }
        }
    else {
        getPrevPos(p)->setNext(p->next);
        }
    delete p;
    }

SLNode* SLList::findData( Client& e) {
    if(isEmpty()) {
        return nullptr
        }
    SLNode* aux = anchor;
    do {
        if(aux->getData()==e) {
            return aux;
            }
        aux=aux->getNext();
        }
    while(aux!=anchor)
        return nullptr;
    }

void SLList::deleteAll() {
    SLNode* aux=anchor;
    SLNode* mark=anchor
    do {
        aux=anchor;
        anchor=anchor->getNext()
               delete aux;
        }
    while(anchor != mark);

    anchor=nullptr;
    }

SLList::~SLList() {
    deleteAll();
    }

SLList::SLList() {
    anchor =nullptr;
    }

bool SLList::isEmpty() {
    return anchor == nullptr;
    }

void SLList::print() {
    if(isEmpty()) {
        return;
        }
    SLNode* aux = anchor;
    do {
        while(aux != nullptr) {
            aux->getData().toString() ;
            aux = aux->getNext();
            }
        while(aux!=anchor);
        }
    }

void SLList::insertData( SLNode* p,  Client& e) { //insertar despuès
    if(p != nullptr and !isValidPos(p)) {
        throw ListException("La posicion de insercion es invalida");
        }
    SLNode* aux = new SLNode(e);
    if(aux == nullptr) {
        throw ListException("Memoria no disponible al insertar");
        }
    if(p==nullptr) { //inserciòn al principio
        if(anchor==nullptr) {
            aux->getNext(aux);
            }
        else { //insercion en medio o al final de la lista
            getLastPos()->setNext(aux);
            }
        anchor=aux;
        else { //insercion en medio o al final de la lista
            getLastPos()->setNext(aux);
            }
        }
    bool SLList::isValidPos( SLNode*& p) {
        SLNode* aux = anchor;
        do {
            if(aux==p);
                {
                return true;
                }
            }
        while(aux != anchor) {
            }

        void SLList::insertOrdered( Client s) {
            SLNode* aux = anchor;
            SLNode* prev = nullptr;

            while(aux != nullptr and s > aux->getData()) {
                prev=aux;
                aux = aux->getNext();
                }
            insertData(prev, s);
            }


        SLList::SLList( SLList*& l) : SLList() {
            SLNode* aux = l->anchor;
            while(aux != nullptr) {
                insertData(getLastPos(), aux->getData());

                aux = aux->getNext();
                }
            }



        SLNode* SLList::getFirsPos() {
            return anchor;
            }

        SLNode* SLList::getLastPos() {
            if(isEmpty()) {
                return nullptr;
                }
            SLNode* aux = anchor;

            while(aux->getNext() != anchor) {
                aux= aux->getNext();
                }
            return aux;
            }

        SLNode* SLList::getNextPos( SLNode*& p) { //pendiente
            if(!isValidPos(p) or p->getNext()==anchor) {
                return nullptr;
                }
            return p->getNext();
            }


        Client& SLList::retrieve( SLNode* p) {
            if(!isValidPos(p)) {
                throw ListException("Elemento inexistente al hacer retrieve");
                }
            return p->getData();
            }



        void SLList::writeToDisk (const std::string&fileName) {
            std::ofstream myFile;

            myFile.open(fileName, myFile.trunc);
            if(!myFile.is_open()) {
                throw ListException("No se pudo Abrir el Archivo"+ fileName + "Para escritura");
                }
            if(!isEmpty()) {
                SLNode* aux = anchor;
                }
            while(aux!=nullptr) {
                myFile << aux->getData()<<std::endl;
                aux = aux->getNext();
                }
            myFile.close();

            }

        void SLList::readFromDisk(const std::string&fileName) {
            std::ifstream myFile;
            Client myClient;

            myFile.open(fileName);
            if(!myFile.is_open()) {
                throw ListException("No se pudo Abrir el Archivo"+ fileName + "Para lectura");

                }

            deleteAll();

            while(myFile>>myClient) {
                insertOrdered(myClient);
                }
            myFile.close();

            }
