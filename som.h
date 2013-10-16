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
    // This class is able to support many types and many dimensions
    // The class supports both an input type and an output type, in case a discrete value is desired
    // as the output type
    // Some things may not be implemented as they are beyond the scope of the assignment.
    // I am planning on expanding this class after semester.
    template <typename InputType = double, typename OutputType = InputType, unative_t InputSize = 2,
              unative_t OutputSizeX = 2, unative_t OutputSizeY = 2>
    class self_organising_map
    {
    private:
		typedef std::array<InputType, InputSize> input_vector;
	
		static const int rand_max = 1000000;
        std::mt19937 m_rand;
        const double m_initialLR;
        const double m_lrRateDecay;
        const double m_initialNbdWidth;
        const double m_nbdWidthDecay;
        std::vector<input_vector> m_input;
        std::vector<input_vector> m_weight;
        std::array<std::array<OutputType, OutputSizeY>, OutputSizeX> m_output;
		
		// private member functions
		double small_random() const;
		double h() const;
		double euclidean_distance() const;
		void adjust_weight();
    public:
        // Constructor, and copy control (i.e. copying and moving)
        self_organising_map(const double& = 0.5, const double& = 0.5, const double& = 0.5,
                          const double& = 0.5);
        self_organising_map(std::istream);
        
        // Element access
        std::array<InputType, InputSize> get_input() const;
        std::array<InputType, InputSize> get_weight() const;
        
    };
}

#include "som.tem"