#include "PaperbackBook.h"
#include <string>

using namespace std;

PaperbackBook::PaperbackBook(){
    title = "";
    authorcount = 0;
    publisher = "";
    isbn = "";
    yearPublish = 0;
    hardcover = false;
    price = 0;
    copies = 0;
    next =nullptr;
}

PaperbackBook::PaperbackBook(string title, int authorCount, string publisher, string authors[], short yearPublish,
	    bool hardcover, float price, string isbn, long copies){
    Book::title = title;
    Book::authorcount = authorCount;
    Book::publisher = publisher;
    for (int i = 0; i < authorCount; i++)
        Book::authors[i] = authors[i];
    Book::yearPublish = yearPublish;
    Book::hardcover = hardcover;
    Book::price = price;
    Book::isbn = isbn;
    Book::copies = copies;
}

string PaperbackBook::getCover() const{
    return "Paperback";
}