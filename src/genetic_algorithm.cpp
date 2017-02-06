/*
 * genetic_algorithm.cpp
 *
 *  Created on: 06-Feb-2017
 *      Author: ajith
 */




#include "genetic_algorithm.h"




char **currentGeneration, **nextGeneration;
char *modelOrganism;
int *organismsFitnesses;
int totalOfFitnesses;





void GeneticAlgorithm::check_genetic_algorithm(){
  int finalGeneration;
  allocate_memory();
  finalGeneration = do_one_run();
  cout <<"The final generation was: "<<finalGeneration<<endl;
}


void GeneticAlgorithm::allocate_memory(void){
  int organism;

  currentGeneration =
    (char**)malloc(sizeof(char*) * NUMBER_ORGANISMS);
  nextGeneration =
    (char**)malloc(sizeof(char*) * NUMBER_ORGANISMS);
  modelOrganism =
    (char*)malloc(sizeof(char) * NUMBER_GENES);
  organismsFitnesses =
    (int*)malloc(sizeof(int) * NUMBER_ORGANISMS);

  for(organism=0; organism<NUMBER_ORGANISMS; ++organism){
    currentGeneration[organism] =
      (char*)malloc(sizeof(char) * NUMBER_GENES);
    nextGeneration[organism] =
      (char*)malloc(sizeof(char) * NUMBER_GENES);
  }
}


int GeneticAlgorithm::do_one_run(void){
  int generations = 1;
  int perfectGeneration = FALSE;

  initialize_organisms();

  while(TRUE){
    perfectGeneration = evaluate_organisms();
    if( perfectGeneration==TRUE ) return generations;
    produce_next_generation();
    ++generations;
  }
}


void GeneticAlgorithm::initialize_organisms(void){
  int organism;
  int gene;


  for(organism=0; organism<NUMBER_ORGANISMS; ++organism){
    for(gene=0; gene<NUMBER_GENES; ++gene){
      currentGeneration[organism][gene] = rand()%ALLELES;
    }
  }


  for(gene=0; gene<NUMBER_GENES; ++gene){
    modelOrganism[gene] = rand()%ALLELES;
  }
}


int GeneticAlgorithm::evaluate_organisms(void){
  int organism;
  int gene;
  int currentOrganismsFitnessTally;

  totalOfFitnesses = 0;

  for(organism=0; organism<NUMBER_ORGANISMS; ++organism){
    currentOrganismsFitnessTally = 0;


    for(gene=0; gene<NUMBER_GENES; ++gene){
      if( currentGeneration[organism][gene]
          == modelOrganism[gene] ){
        ++currentOrganismsFitnessTally;
      }
    }

    organismsFitnesses[organism] =
      currentOrganismsFitnessTally;
    totalOfFitnesses += currentOrganismsFitnessTally;

    if( currentOrganismsFitnessTally == MAXIMUM_FITNESS ){
      return TRUE;
    }
  }
  return FALSE;
}


void GeneticAlgorithm::produce_next_generation(void){
  int organism;
  int gene;
  int parentOne;
  int parentTwo;
  int crossoverPoint;
  int mutateThisGene;


  for(organism=0; organism<NUMBER_ORGANISMS; ++organism){
    parentOne = select_one_organism();
    parentTwo = select_one_organism();
    crossoverPoint  =  rand() % NUMBER_GENES;

    for(gene=0; gene<NUMBER_GENES; ++gene){


      mutateThisGene = rand() % (int)(1.0 / MUTATION_RATE);
      if(mutateThisGene == 0){


        nextGeneration[organism][gene] = rand() % ALLELES;
      } else {

        if (gene < crossoverPoint){
          nextGeneration[organism][gene] =
            currentGeneration[parentOne][gene];
        } else {
          nextGeneration[organism][gene] =
            currentGeneration[parentTwo][gene];
        }
      }
    }
  }


  for(organism=0; organism<NUMBER_ORGANISMS; ++organism){
    for(gene=0; gene<NUMBER_GENES; ++gene){
      currentGeneration[organism][gene] =
        nextGeneration[organism][gene];
    }
  }
}


int GeneticAlgorithm::select_one_organism(void){
  int organism;
  int runningTotal;
  int randomSelectPoint;

  runningTotal = 0;
  randomSelectPoint = rand() % (totalOfFitnesses + 1);

  for(organism=0; organism<NUMBER_ORGANISMS; ++organism){
    runningTotal += organismsFitnesses[organism];
    if(runningTotal >= randomSelectPoint) return organism;
  }
}


