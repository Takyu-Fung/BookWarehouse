#include "HardcoverBook.h"

using namespace std;

HardcoverBook::HardcoverBook(){
    Book::title = "";
    Book::authorcount = 0;
    Book::publisher = "";
    Book::isbn = "";
    Book::yearPublish = 0;
    Book::hardcover = false;
    Book::price = 0;
    Book::copies = 0;
    Book::next = nullptr;
}

HardcoverBook::HardcoverBook(string title, int authorCount, string publisher, string authors[], short yearPublish,
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

string HardcoverBook::getCover() const{
    return "Hardcover";
}