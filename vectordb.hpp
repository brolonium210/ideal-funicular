/**
 * vectordb.hpp
 * C++ header file that should contain declaration for
 * - VectorDbTable class
 * 
 * You need to modify this file to declare VectorDbTable class 
 * as specified in the hand-out (Task 2)
 */ 





#ifndef __VECTOR_DB_HPP__
#define __VECTOR_DB_HPP__

#include "abstractdb.hpp"
#include<vector>

namespace nwen {

    class VectorDbTable:public AbstractDbTable {
    private:
        //need to remember the std:: part ,costing a lot of time
        std::vector<movie> myMovies;

    public:
        int rows()const override;
        movie* get(const int In)const override;
        bool add(movie m)override;
        bool update(const int In,movie m)override;
        bool remove(const int In)override;

    };

} // nwen

#endif
