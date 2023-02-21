#include "Book.h"
#include <iostream>

/*
istream& operator >> (istream& is, Book& book){
    int tempInt;
    string tempStr;
    long tempLong;
    bool tempBool;
    short tempShort;
    float tempFloat;
    string trash;
    Book temp;

    book.setNext(new Book());

    getline(is,tempStr);
    book.setTitle(tempStr);

    is >> tempInt;
    book.setAuthorcount(tempInt);
    getline(is,trash);

    for(int i=0; i<book.getAuthourCount(); ++i){
        getline(is,tempStr);
        book.setAuthors(tempStr,i);
    }
    getline(is, tempStr);
    book.setPublisher(tempStr);

    is >> tempShort;
    book.setYearPublish(tempShort);
    getline(is,trash);

    is >> tempBool;
    book.setHardcover(tempBool);
    getline(is,trash);

    is >> tempFloat;
    book.setPrice(tempFloat);
    getline(is,trash);

    is >> tempStr;
    book.setISBN(tempStr);
    getline(is,trash);
    
    is >> tempLong;
    book.setCopies(tempLong);
    getline(is,trash);

    return is;
}*/

ostream& operator << (ostream& os, const Book& book){
    os << "Title: " << book.title << endl;
    for(int i = 0; i < book.authorcount; i++){
        os << "Author: " << book.authors[i] << endl;
    }
    os << "Publisher: " << book.publisher << endl;
    os << "Year: " << book.yearPublish << endl;
    os << "Cover: " << book.getCover() << endl;
    os << "Price: $" << book.price << endl;
    os << "ISBN: " << book.isbn << endl;
    os << "Copies: " << book.copies << endl << endl;

    return os;
}

Book::Book(){
    title = "";
    authorcount = 0;
    publisher = "";
    yearPublish = 0;
    hardcover = false;
    price = 0;
    isbn = "";
    copies = 0;
    next = nullptr;
}

Book::Book(string title, string authors[], int authorCount, string publisher,
         short yearPublish, bool hardcover, float price, string isbn, long copies){
    Book::title = title;
    Book::authorcount = authorCount;
    for(int i = 0; i<authorCount; i++)
        Book::authors[i] = authors[i];
    Book::publisher = publisher;
    Book::yearPublish = yearPublish;
    Book::hardcover = hardcover;
    Book::price = price;
    Book::isbn = isbn;
    Book::copies = copies;
}

Book::Book(Book* next){
    Book::next = next;
}

Book* Book::getNext() const{
    return this->next;
}

void Book::setNext(Book* next){
    this->next = next;
}

void Book::setTitle(string title){
    this->title = title;
}

string Book::getTitle(){
    return title;
}

void Book::setAuthors(string name, int num){
    this->authors[num] = name;
}

string Book::getAuthors(int pos){
    return this->authors[pos];
}

void Book::setAuthorcount(int authorcount){
    this->authorcount = authorcount;
}

int Book::getAuthourCount(){
    return this->authorcount;
}

void Book::setPublisher(string publisher){
    this->publisher = publisher;
}

string Book::getPublisher(){
    return this->publisher;
}

void Book::setYearPublish(short yearPublish){
    this->yearPublish = yearPublish;
}

short Book::getYearPublish(){
    return this->yearPublish;
}

void Book::setHardcover(bool hardcover){
    this->hardcover = hardcover;
}

bool Book::getHardcover(){
    return this->hardcover;
}

void Book::setPrice(float price){
    this->price = price;
}

float Book::getPrice(){
    return this->price;
}

void Book::setISBN(string isbn){
    this->isbn = isbn;
}

string Book::getISBN(){
    return this->isbn;
}

void Book::setCopies(long copies){
    this->copies = copies;
}

long Book::getCopies(){
    return this->copies;
}