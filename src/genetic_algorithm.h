/*
 * genetic_algorithm.h
 *
 *  Created on: 06-Feb-2017
 *      Author: ajith
 */

#ifndef GENETIC_ALGORITHM_H_
#define GENETIC_ALGORITHM_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define NUMBER_ORGANISMS 100
#define NUMBER_GENES     20
#define ALLELES          4
#define MUTATION_RATE    0.001

#define MAXIMUM_FITNESS NUMBER_GENES
#define FALSE 0
#define TRUE  1


class GeneticAlgorithm
{
public:
	// function declarations
	void check_genetic_algorithm(void);
	void allocate_memory(void);
	int do_one_run(void);
	void initialize_organisms(void);
	int evaluate_organisms(void);
	void produce_next_generation(void);
	int select_one_organism(void);
};



#endif /* GENETIC_ALGORITHM_H_ */
