/*
 * Christopher Di Bella
 * <chrisdb@cse.unsw.edu.au>
 *
 * 1 November, 2013
 *
 * som.cpp
 * The instantiation file for som.tem
 *
 * Do not attempt to compile this file.
 * Instead run som.sh to fix the template parameters
 */

#include "som.hpp"
#include <cstdlib>
#include <fstream>

int main()
{
    typedef double type;
    const type lr_decay = 0.001;
    const type nbdw_decay = 0.001;
    const type lr = 0.1;
    const type nbdw = 2.0;

    std::ifstream file("ASED", std::ios::in);
    kohonen<type, BSED, CSED, DSED> som(file, lr_decay, nbdw_decay, lr, nbdw);
    som.train(ESED);
    som.print();

    return EXIT_SUCCESS; // Even though this is C++, I still like to do this :)
}
