//
// Created by parrg on 25/05/2025.
//

#include<iostream>
#include "vectordb.hpp"
#include <string>
#include "abstractdb.hpp"
#include "AbstractDbTable.h"
#include "VectorDbTable.hpp"

using namespace std;
using namespace nwen;


struct movie movies[] = {
    { 13, "The Shawshank Redemption", 1994, "Frank Darabont" },
    { 25, "The Godfather", 1972, "Francis Ford Coppola" },
    { 31, "The Dark Knight", 2008, "Christopher Nolan" },
    { 40, "The Godfather: Part II", 1974, "Francis Ford Coppola" },
    { 55, "The Lord of the Rings: The Return of the King", 2003, "Peter Jackson" },
    { 72, "Pulp Fiction", 1994, "Quentin Tarantino" }
};


int main(){
    VectorDbTable *db;
    bool r;

    cout << "Instantiating VectorDbTable..." << endl;
    db = new VectorDbTable();


}
