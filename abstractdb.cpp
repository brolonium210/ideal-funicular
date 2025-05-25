/**
 * abstractdb.cpp
 * C++ source file that should contain implementation for member functions
 * - loadCSV()
 * - saveCSV()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Tasks 4 and 5)
 */ 

#include "abstractdb.hpp"

#include <cstring>
#include<string>
#include<fstream>
#include <sstream>



namespace nwen {

    //-----------------------------------------------------------------------------------------
    // Load
    bool AbstractDbTable::loadCSV(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile.is_open()) {
            return false; // File couldn't be opened
        }

        std::string line;
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string idStr, title, yearStr, director;

            // Read ID
            if (!std::getline(ss, idStr, ',')) return false;

            // Read Title
            if (!std::getline(ss, title, ',')) return false;
            if (title.front() == '"' && title.back() == '"') {
                title = title.substr(1, title.size() - 2); // Remove quotes
            }

            // get Year
            if (!std::getline(ss, yearStr, ',')) return false;

            // get Director
            if (!std::getline(ss, director)) return false;
            if (director.front() == '"' && director.back() == '"') {
                director = director.substr(1, director.size() - 2); // Remove quotes
            }

            // Ensure Id and Year are ints
            int id, year;
            try {
                id = std::stoi(idStr);
                year = std::stoi(yearStr);
            } catch (const std::exception&) {
                return false;
            }

            // Build movie object ,requires us to switch the data types again
            // movie m = { id, title, year, director };
            movie m;
            std::copy(title.begin(), title.end(), m.title);
            m.title[std::min(title.size(), sizeof(m.title) - 1)] = '\0';

            std::copy(director.begin(), director.end(), m.director);
            m.director[std::min(director.size(), sizeof(m.director) - 1)] = '\0';
            if (!this->add(m)) {
                continue;
            }
        }

        inFile.close();
        return true;
    }


    //--------------------------------------------------------------------------------
    //Save

    bool AbstractDbTable::saveCSV(const std::string& filename) {
        std::ofstream outFile(filename, std::ios::out);
        if (!outFile.is_open()) {
            return false;
        }
            for (int i = 0; i < this->rows(); ++i) {
        movie* m = this->get(i);
        if (m == nullptr) continue;

        outFile << m->id << ","
                << "\"" << m->title << "\"" << ","
                << m->year << ","
                << "\"" << m->director << "\"" << "\n";

        if (outFile.fail()) {
            outFile.close();
            return false;
        }
    }

    outFile.close();
    return true;
}



} // nwen

