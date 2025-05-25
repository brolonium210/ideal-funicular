/**
 * vectordb.cpp
 * C++ source file that should contain implementation for member functions
 * - rows()
 * - get()
 * - add()
 * - update()
 * - remove()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Task 3)
 */ 

#include "vectordb.hpp"

#include<stdexcept>

namespace nwen {

    int VectorDbTable::rows()const {
        return myMovies.size();
    }

    movie* VectorDbTable::get(const int In)const {
      try{
//          return &myMovies.at(In);
//def need to figure out why this works
          return const_cast<movie*>(&myMovies.at(In));
      }catch(const std::out_of_range& e){
          return nullptr;
      }
    }
    bool VectorDbTable::add(movie m){
        for (int i = 0; i < myMovies.size(); i++){
            movie currMovie = myMovies.at(i);
            if(currMovie.id == m.id){
                return false;
            }
        }
      myMovies.push_back(m);
      return true;
    }
//You’re passed an id and a movie m.
//
//You need to find a movie in the vector with that same id.
//
//If found, replace it with m, return true.
//
//If not found, return false.


    bool VectorDbTable::update(const int In,movie m){
        for (int i = 0; i < myMovies.size(); i++){
            movie currMovie = myMovies.at(i);
            if(currMovie.id == In){
                myMovies.at(i) = m;
                return true;
            }
        }
        return false;
    }

    bool VectorDbTable::remove(const int In){
        for (auto it = myMovies.begin(); it != myMovies.end(); ++it) {
            if (it->id == In) {
                myMovies.erase(it);
                return true;
            }
        }
        return false;
    }


} // nwen