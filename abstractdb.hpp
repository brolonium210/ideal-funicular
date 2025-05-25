/**
 * abstractdb.hpp
 * C++ header file that should contain declaration for
 * - struct movie (given)
 * - AbstractDbTable abstract class
 * 
 * You need to modify this file to declare AbstractDbTable abstract class 
 * as specified in the hand-out (Task 1)
 */ 



#ifndef __ABSTRACT_DB_HPP__
#define __ABSTRACT_DB_HPP__

#include <string>
#include <sstream>

namespace nwen 
{
    struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };

    class AbstractDbTable {
    private:


    public:
        virtual int rows()const =0;
        virtual movie* get(const int In)const =0;
        virtual bool add(movie m)=0;
        virtual bool update(const int In,movie m)=0;
        virtual bool remove(const int In)=0;
        virtual bool loadCSV(const std::string& filename);
        virtual bool saveCSV(const std::string& filename);
        virtual ~AbstractDbTable() = default;
    };


}

#endif /* __ABSTRACT_DB_HPP__ */
