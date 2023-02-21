#include "Book.h"
#include "Warehouse.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    //Warehouse* warehouse = new Warehouse();
    //Warehouse* temp = warehouse;

    Warehouse warehouse;
    ifstream inputFile;
    
    if(argc == 1){
        cout << "./proj02 <input file> find <id>\n"
             << "./proj02 <input file> list\n";
        return 0;
    }

    string file = argv[1];
    inputFile.open(file);

    if(inputFile.fail()){
        cout << "Error, file does not exist.\n";
        return -1;
    }

    inputFile >> warehouse;
    string str = argv[2];
    if((argc == 3) && (str.compare("list") == 0)){
        warehouse.list();
    }
    else if((argc == 4) && (str.compare("find")==0)){
        Book* current;
        string isbn = argv[3];

        current = warehouse.find(isbn);

        if(current == nullptr)
            cout << "ISBN: " << isbn << " -- NOT FOUND" << endl;
        else{
            cout << "ISBN: " << isbn << " -- FOUND" << endl;
            cout << *current;
        }
    }
    else
    	cout << "Invalid input";
}
