#pragma once
#include <vector>
class GenericAlgorithm {
public:
	std::vector<GenericAlgorithm> Collection;
	
	double Score = 0;
	double X = 0;
	double Y = 0;
	double Z = 0;

	void Fitness();
	void EvaluateFitnesses();
	void SortCollection();
	void PrintCollection();
	void CreateSolutions(int count);
	void Run(GenericAlgorithm gen,int count);
private:

};