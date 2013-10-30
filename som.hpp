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

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>


/*/ Forward declarations
template <typename T, size_t I, size_t X, size_t Y, size_t A> class kohonen;

template <typename T, size_t I, size_t X, size_t Y, size_t A>
std::ostream operator<<(std::ostream& os, const kohonen<T, I, X, Y, A>& k);*/

template <typename T, size_t InputSize, size_t X, size_t Y, size_t Area = X * Y>
class kohonen
{
private:
    // Some important typedefs
    typedef std::array<T, InputSize>     input_type;
    typedef std::array<input_type, Area> output_type;
    typedef std::chrono::system_clock    clock;
    
    typedef typename std::vector<input_type>::iterator  input_iterator;
    typedef typename output_type::iterator              output_iterator;
    
    // Data structures
    std::vector<input_type> m_input;
    output_type m_output;
    
    // Constants
    const T m_lrDecay;
    const T m_nbdWidthDecay;
    
    // Variable data
    T m_learningRate;
    T m_nbdWidth;
    
    // Random number generator
    std::default_random_engine m_random;
    std::uniform_real_distribution<T> m_distribution;
    
    // The three processes of SOMs
    std::array<T, Area> compete(input_iterator& x);
    output_iterator cooperate(const std::array<T, Area>& m);
    void adapt(input_iterator& x, output_iterator& winner);
    //void adjust_neighbours(const_input_iterator& x, const output_iterator& winner);
    
    // Some helper functions
    T h(const input_type& input, const input_type& winner);
	output_iterator find_min_element(const std::array<T, Area>& m);
    void decay();
public:
    kohonen(std::istream& is, const T& lr_decay, const T& nbd_width_decay, const T& lr,
            const T& nbd_width);
            
    void train(const size_t epochs);
    
    void print() const;
};

#include "som.tem"