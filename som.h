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
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

namespace pipe
{
    // The default template is set for run 1
    template <typename T = double, size_t InputSize = 2, size_t OutputSizeX = 4, size_t OutputSizeY = 2>
    class kohonen
    {
    private:
        // Some important types
        typedef std::array<T, InputSize>                            input_type;
        typedef std::array<std::array<T, OutputSizeY>, OutputSizeX> output_type;
        typedef std::chrono::system_clock clock;
        
        // State data
        T m_learningRate;
        T m_nbdWidth;
        input_type* m_winningNeuron;
        
        // Constant data
        const T m_lrDecay;
        const T m_nbdWidthDecay;
        
        // Random engine
        std::default_random_engine        m_random;
        std::uniform_real_distribution<T> m_distribute;
        
        // Neural net
        std::vector<input_type> m_input;
        std::vector<output_type> m_output;
        
        // Private member functions
        template <typename Container = input_type>
        T euclidean_distance_squared(const Container& x, const Container& y) const;
        
        T tiny_rand() const;
        T h(const input_type& j) const;
        void decay();
        void adjust_weight();
    public:
        // Constructors
        kohonen(const T& initial_lr = 0.1, const T& lr_decay = 0.001, const T& initial_nbd_width = 2.0, const T& nbd_width_decay = 0.001, const T& min_weight = -0.1, const T& max_weight = 0.1);
        kohonen(std::istream& in, const T& initial_lr = 0.1, const T& lr_decay = 0.001, const T& initial_nbd_width = 2.0, const T& nbd_width_decay = 0.001, const T& min_weight = -0.1, const T& max_weight = 0.1);
        
        // Epoch run
        void run(const int epochs = 5000);
    };
}

#include "som.tem"