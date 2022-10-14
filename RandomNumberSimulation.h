//
// Created by Aihua on 2020-07-22.
//

#ifndef BLACKJACKCARDGAME_RANDOMNUMBERSIMULATION_H
#define BLACKJACKCARDGAME_RANDOMNUMBERSIMULATION_H

#include <random> // for std::mt19937_64
#include <ctime> // for std::time

using MTSeedType = std::mt19937_64::result_type;

namespace randomNumberGenerator {
    // Initialize our mersenne twister with a random seed based on the clock
    // (once at system startup)
    std::mt19937_64 mersenne{ static_cast<MTSeedType>(std::time(nullptr))};
}

#endif //BLACKJACKCARDGAME_RANDOMNUMBERSIMULATION_H
