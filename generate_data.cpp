#include <fstream>
#include <iostream>
#include <random>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "TurnipPrices.cpp"

int main(int argc, char **argv) {
    unsigned int pattern, num_iterations, seed;
    TurnipPrices turnips;
    
    if (argc == 2) {
        num_iterations = atoi(argv[1]);
    } else {
        printf("Usage: %s <number of iterations>\n", argv[0]);
        return 0;
    }
    
    // adapted from https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    
    std::uniform_int_distribution<unsigned int> pattern_distribution(0, 3); // pattern generator
    std::uniform_int_distribution<unsigned int> seed_distribution(0, 100000); // seed generator
    
    std::ofstream output_file;
    output_file.open("data/generated_data.csv");
    
    output_file << "seed," << "previous_pattern," << "pattern," << "base_price,";
    // 1 to 12 = Monday AM, Monday PM, ... Saturday AM, Saturday PM
    for (int i = 1; i < 12; i++) {
        output_file << i << ',';
    }
    output_file << 12 << '\n'; 
    
    for (unsigned int j = 0; j < num_iterations; j++) {
        pattern = pattern_distribution(gen);
        seed = seed_distribution(gen);
        
        turnips.whatPattern = pattern;
        turnips.rng.init(seed);
        turnips.calculate();
        
        // seed, previous pattern, pattern, base price, selling prices ...
        output_file << seed << ','; 
        output_file << pattern << ','; 
        output_file << turnips.whatPattern << ',';
        output_file << turnips.basePrice << ',';
        
        for (int k = 2; k < 13; k++) {
            output_file << turnips.sellPrices[k] << ',';
        }
        
        output_file << turnips.sellPrices[13] << '\n';
    }
    
    output_file.close();
    
    printf("%d iterations complete.", num_iterations);
    return 0;
}