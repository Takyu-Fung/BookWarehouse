#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Book.h"

template <class T>
class LinkedList{
    public:
        LinkedList();

        void enqueue(Book* book);
        Book* dequeue();
        Book* getHead();
        int length() const;
    
    private:
        Book* head;
        Book* tail;
        int size;
};

template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
void LinkedList<T>::enqueue(Book* book){
    Book* node = book;
    if(tail == nullptr){
        head = node;
        tail = node;
    }

    tail->setNext(node);
    tail = node;
}

template <class T>
Book* LinkedList<T>::dequeue(){
    if(head == nullptr){
        return nullptr;
    }

    Book* temp = head;
    head = head->getNext();

    if(head == nullptr)
        tail = nullptr;

    return temp;
}

template <class T>
Book* LinkedList<T>::getHead(){
    return head;
}
#endif /* LINKEDLIST_H */