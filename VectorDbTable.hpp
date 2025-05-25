//
// Created by parrg on 25/05/2025.
//

#ifndef VECTORDBTABLE_HPP
#define VECTORDBTABLE_HPP

#include "AbstractDbTable.h"
#include<vector>

namespace nwen {

class VectorDbTable:public AbstractDbTable {
    private:
      //need to remember the std:: part ,costing a lot of time
      std::vector<movie> myMovies;

    public:
    int rows()const override;
    movie* get(const int In)const override;
    void add(movie m)override;
    bool update(const int In,movie m)override;
    bool remove(const int In)override;

};

} // nwen

#endif //VECTORDBTABLE_HPP
