//
// Created by parrg on 25/05/2025.
//

#include "VectorDbTable.hpp"
#include<stdexcept>

namespace nwen {

    int VectorDbTable::rows()const {
        return myMovies.size();
    }
    const movie* VectorDbTable::get(const int In)const {
      try{
          return &myMovies.at(In);
      }catch(const std::out_of_range& e){
          return nullptr;
      }
    }
    void VectorDbTable::add(movie m){
      myMovies.push_back(m);

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
            if(currMovie.id == m.id){
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