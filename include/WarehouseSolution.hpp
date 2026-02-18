#ifndef WAREHOUSESOLUTION_HPP
#define WAREHOUSESOLUTION_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "WarehouseInstance.hpp"

using namespace std;

/**
 * @struct WarehouseSolution
 */
struct WarehouseSolution {
    WarehouseInstance data;
    vector<int> assignment;

    WarehouseSolution(); // default constructor

    /**
     * @brief Solution constructor
     */
    WarehouseSolution(const WarehouseInstance& data_, const std::vector<int>& assignment_);

    /**
     * @brief Writes the solution in the given file in the correct format
     * @param filename The file in which to write the solution
     */
    void write(const std::string& filename);

    /**
     * @brief Prints the solution in the terminal
     */
    void print();
};

#endif