/*
 * Christopher Di Bella <chrisdb@cse.unsw.edu.au>
 *
 * 1 November, 2013
 *
 * som.h
 * The self-organising map implementation file.
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
 * Note that this is a C++11 file, subject to GCC 4.7.2, as on the CSE machines
 */
 
#include <array>
#include <iostream>
#include <vector>

namespace pipe
{
    // This class is able to support many types and many dimensions
    // The class supports both an input type and an output type, in case a discrete value is desired
    // as the output type
    // Some things may not be implemented as they are beyond the scope of the assignment.
    // I am planning on expanding this class after semester.
    template <typename InputType = double, typename OutputType = InputType,
                                                                         unsigned int InputSize = 2>
    class self_ordering_map
    {
    private:
        std::vector<std::array<InputType, InputSize>> m_input;
        std::vector<std::array<InputType, InputSize>>
        const InputType initial_learning_rate;
        InputType learning_rate_decay;
    public:    
        // Constructor, and copy control (i.e. copying and moving)
        self_ordering_map();
        self_ordering_map(std::istream);
        self_ordering_map(const self_ordering_map& o) = default;
        self_ordering_map(self_ordering_map&& o) = default;
        
        self_ordering_map& operator=(const self_ordering_map& o) = default;
        self_ordering_map& operator=(self_ordering_map&& o) = default;
        
        ~self_ordering_map() = default;
        
        // Element access
        
        
        // SOM specifics
        void adjust_weights();
        value_type euclidean_distance(const_reference j, const_reference r) const;  
    };
}
