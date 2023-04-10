// AdvAlg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "ImageSegmentation.h"
#include "PathFinding.h"
#include "TravellingSalesman.h"

#include "GeneticAlgorithms.h"
#include "GeneticProgramming.h"
#include "KMEANS.h"

int main()
{
    std::cout << "Hello World!\n";

    GenericAlgorithm gen;
    gen.Run(gen, 10000);

}