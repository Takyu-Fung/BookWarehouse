#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <string>
#include "Book.h"
#include "LinkedList.h"

using namespace std;

class Warehouse {
 /**
 *  @param is the input stream
 *  @param warehouse the warehouse object reference
 *  @return the input stream
 */
    friend istream& operator >> (istream& is, Warehouse& warehouse);
 
 /**
 *  @param os the output stream
 *  @param warehouse the warehouse object reference
 *  @return the output stream
 */
    friend ostream& operator << (ostream& os, Warehouse& warehouse);
public:
    Warehouse();
 /**
 * @param isbn the ISBN number to search for
 * @return pointer to the Book object, if found. Otherwise, return NULL
 */
    Book* find (string isbn);
/**
 * Prints the inventory of the Warehouse (i.e. list all the books)
 */
    void list();

protected:
    Book* newBook(istream& is);

private:
    Book* head;
    int bookCount;
    LinkedList<Book*> list_;
};
#endif /* WAREHOUSE_H */