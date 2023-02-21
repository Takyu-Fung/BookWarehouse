#ifndef PAPERBACKBOOK_H
#define PAPERBACKBOOK_H

#include "Book.h"
#include <string>

using namespace std;

class PaperbackBook : public Book{
    public:
        PaperbackBook();
        PaperbackBook(string title, int authorCount, string publisher, string authors[], short yearPublish,
	        bool hardcover, float price, string isbn, long copies);

    protected:
        virtual string getCover() const override;
};

#endif