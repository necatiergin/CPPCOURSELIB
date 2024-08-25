#pragma once

//header-only library for testing C++ standard library components

#include <random>


/**
 * @class Irand
 * @brief A class for generating random integers within a specified range.
 *
 * The `Irand` class encapsulates a random number generator that produces
 * integers within a specified range using the Mersenne Twister engine.
 */

class Irand {
public:
    /**
     * @brief Default constructor for the `Irand` class.
     *
     * Constructs an `Irand` object without initializing the distribution range.
     */
    Irand() = default;

    /**
     * @brief Constructs an `Irand` object with a specified range.
     *
     * @param min The lower bound (inclusive) of the range.
     * @param max The upper bound (inclusive) of the range.
     *
     * Initializes the random number generator to produce values in the range [min, max].
     */
    Irand(int min, int max) : m_dist{ min, max } {}

    /**
     * @brief Provides access to the underlying random number generator.
     *
     * This function returns a reference to a static Mersenne Twister engine,
     * ensuring that the generator is only seeded once per application run.
     *
     * @return A reference to a `std::mt19937` random number generator.
     */
    static std::mt19937& urng()
    {
        static std::mt19937 eng{ std::random_device{}() };
        return eng;
    }

    /**
     * @brief Generates a random integer within the specified range.
     *
     * This function overloads the function call operator to produce a random integer
     * within the range [min, max] specified during the construction of the `Irand` object.
     *
     * @return A random integer within the range [min, max].
     */
    int operator()()
    {
        return m_dist(urng());
    }

private:
    std::uniform_int_distribution<int> m_dist;  /**< The distribution used to generate random integers within a specified range. */
};
