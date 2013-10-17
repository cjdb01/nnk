/*
 * Christopher Di Bella <chrisdb@cse.unsw.edu.au>
 *
 * 1 November, 2013
 *
 * som.h
 * The self-organising map interface file.
 *
 * This data structure is intrinsically designed to reflect the STL. The following conventions are
 * used throughout all files:
 *
 *          Type                    Convention              Example
 *      local variales,
 *      static data members,
 *      static globals*,
 *      constants,
 *      new scope**,
 *      functions, and
 *      arguments             underscore notation         max_value
 *
 *      shared globals        hungarian & camel case      g_maxVale*
 *      data members          hungarian & camel case      m_maxValue
 *      template parameters***
 *      enumerations          Pascal case                 MaxValue
 *
 *      * The two types of globals discussed above are as follows:
 *              - Static globals, which are global to a particular file, but unseen elsewhere
 *              - Shared globals, which are global to the whole program (i.e. extern should  used)
 *
 *        Static globals are placed inside an unnamed namespace, and are always preceded by the
 *        scope operator (::). This is the equivalent of the `static' keyword in C (the same applies
 *        to local functions).
 *
 *        A shared global has no such restriction. Thus it is preceded by the `g_' notation to
 *        assert that it is a global variable (should be none anyway, but this is the convention
 *        documented in case there is one).
 *
 *      ** New scope refers to the introduction of a new scope. This includes class/struct/union,
 *        enum/enum class, and namespace identifiers.
 *
 *      *** Template parameters are identified by the `typename' keyword, unless a class/struct is
 *          explicitly expected.
 *
 *      iterators are often expressed as `it', const_iterators are often expressed as `cit',
 *		reverse_iterators as `rit', and reverse_const_iterators as `rcit'
 *
 * Note that this is a C++11 file, subject to GCC 4.7.2, as on the CSE machines
 *
 * Copyright (c) Christopher 2013, under the MIT License.
 * All rights reserved.
 */
 
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

#include "typedef.h" // This file is NOT subject to the above coding convention, as it was written
				     // well before this convention is drafted. It is an early version of it :)

namespace pipe
{
    // The default template is set for run 1
    template <typename T = double, unative_t InputSize = 2, unative_t OutputSizeX = 4, 
              unative_t OutputSizeY = 2, T InitialLR = 0.1, T LRDecay = 0.001,
              T InitialNbdWidth = 2.0, T NbdWidthDecay = 0.001
             >
    class self_organising_map
    {
    private:
        // State data
        T m_learningRate;
        T m_nbdWidth;
        
        // Random engine
        const int m_randMax;
        std::mt19937 m_random;
        
        // Neural net
        std::vector<std::array<T, InputSize>> m_input;
        std::vector<std::array<std::array<T, OutputSizeY>, OutputSizeX> m_output;
        
        // Private member functions
        template <typename Container = std::array<T, InputSize>>
        T euclidean_distance(Container& x, Container& y) const;
        
        T tiny_random() const;
        T h() const;
        void adjust_weight();
        
        template <typename RandomAccessIterator>
        void randomise(RandomAccessIterator& first, RandomAccessIterator& last);
    public:
        // Constructors
        self_organising_map(const int rand_max = 1000);
        self_organising_map(std::istream&);
        
        // Epoch run
        void run(const int epochs = 5000);
    };
}
