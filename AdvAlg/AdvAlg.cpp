// AdvAlg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "ImageSegmentation.h"
#include "PathFinding.h"
#include "TravellingSalesman.h"

#include "GeneticAlgorithms.h"
#include "GeneticProgramming.h"
#include "KMEANS.h"

int main()
{
    std::cout << "Hello GeneticAlgorithms!\n";
    int genCount = 0;

    GenericAlgorithm gen;

    gen.BatchSize = 100000;
    gen.CreateSolutions();
    ;
    while (true)
    {
        genCount++;
        gen.EvaluateFitnesses();
        gen.SortCollection();
        system("CLS");
        std::cout <<"Generation: " << genCount << "\nTop 10:";
        gen.PrintCollection();
        gen.TakeBestSolutions();
        gen.MutateSolutions(0.4);
        gen.Crossover();
        ;
    }
}