//
// Created by parrg on 24/05/2025.
//

#ifndef ABSTRACTDBTABLE_H
#define ABSTRACTDBTABLE_H

#include <string>
#include "abstractdb.hpp"

namespace nwen {
class AbstractDbTable {
	private:


    public:
      virtual int rows()const =0;
      virtual movie* get(const int In)const =0;
      virtual void add(movie m)=0;
      virtual bool update(const int In,movie m)=0;
      virtual bool remove(const int In)=0;
      virtual bool loadCSV(const std::string In);
      virtual bool saveCSV(const std::string In);
	virtual ~AbstractDbTable() = default;
};

} // nwen

#endif //ABSTRACTDBTABLE_H
