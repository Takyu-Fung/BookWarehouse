#ifndef HARDCOVERBOOK_H
#define HARDCOVERBOOK_H

#include "Book.h"
#include <string>

using namespace std;

class HardcoverBook : public Book{
    public:
        HardcoverBook();
        HardcoverBook(string title, int authorCount, string publisher, string authors[], short yearPublish,
	     bool hardcover, float price, string isbn, long copies);

    protected:
        virtual string getCover() const override;
};

#endif /* Hardcoverbook.h */