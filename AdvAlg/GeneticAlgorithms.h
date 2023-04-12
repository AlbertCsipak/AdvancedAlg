#pragma once
#include <vector>
#include <random>
#include "TravellingSalesman.h"

class GenericAlgorithm {
public:
	std::vector<GenericAlgorithm> Collection;
	std::vector<GenericAlgorithm> BestCollection;

	int BatchSize = 10000;
	int SampleSize = BatchSize / 100;

	double Score = 0;
	double X = 0;
	double Y = 0;
	double Z = 0;

	void Fitness();
	void EvaluateFitnesses();
	void SortCollection();
	void PrintCollection();
	void Crossover();
	void CreateSolutions();
	void TakeBestSolutions();
	void MutateSolutions(double percentage);

};