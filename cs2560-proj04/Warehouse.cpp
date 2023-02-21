#include "Book.h"
#include "Warehouse.h"
#include "LinkedList.h"
#include "PaperbackBook.h"
#include "HardcoverBook.h"
#include <iostream>
#include <fstream>
#include <string>

istream& operator >> (istream& is, Warehouse& warehouse){
    Book* current;
    while(!is.eof()){
        if(warehouse.head == nullptr){
            current = warehouse.newBook(is);
            warehouse.head = current;           //assigns to the head of the linked list
        }else  
            current = warehouse.newBook(is);    //traverses to the next position of the linked list

        warehouse.bookCount++;
        warehouse.list_.enqueue(current);
    }
        return is;
}

ostream& operator << (ostream& os, Warehouse& warehouse){
    warehouse.list();
    return os;
}

Warehouse::Warehouse(){
    bookCount = 0;
    head = nullptr;
}

void Warehouse::list(){
    Book* current = list_.getHead();

    while(current->getNext() != nullptr){
        current = list_.dequeue();
        cout << *current;
        current = current->getNext();
    }
}

Book* Warehouse::find (string isbn){
    Book* current = list_.getHead();

    while(current->getNext() != nullptr){
        current = list_.dequeue();
        if(isbn.compare(current->getISBN()) == 0)
            return current;
    }
        return nullptr;
}

Book* Warehouse::newBook(istream& is){
    string title, trash;
    string authors[Book::MAX_AUTHORS];
    int authorcount;
    string publisher;
    string isbn;
    short yearPublish;
    bool hardCover;
    float price;
    long copies;

    getline(is, title);

    is >> authorcount;
    getline(is, trash);

    for(int i = 0; i< authorcount; i++)
        getline(is,authors[i]);
    
    getline(is, publisher);

    is >> yearPublish;
    getline(is,trash);

    is >> hardCover;
    getline(is,trash);

    is >> price;
    getline(is, trash);

    is >> isbn;
    getline(is, trash);

    is >> copies;
    getline(is, trash);

    //paperback
    if(hardCover == 0){
        PaperbackBook* book = new PaperbackBook(title, authorcount, publisher, authors, yearPublish,
        hardCover, price, isbn, copies);
        return book;
    }
    //hardcover
    else{
        HardcoverBook* book = new HardcoverBook(title, authorcount, publisher, authors, yearPublish,
        hardCover, price, isbn, copies);
        
        return book;
    }
}