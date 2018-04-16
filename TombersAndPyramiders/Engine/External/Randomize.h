#pragma once

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>


class Randomize {
    private:
        static boost::mt19937 gen;
        const static int MAX_INT = 2147483647;
    
    public:

    static void SetSeed(int seed) {
        gen.seed(seed);
        //rng.distribution().reset();
    }

    static int Random(int min = 0, int max = MAX_INT) {
        boost::random::uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }
};

boost::mt19937 Randomize::gen;
