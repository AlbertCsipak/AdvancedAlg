#include "GeneticAlgorithms.h"
#include "Random.h"
#include <math.h>
#include <iostream>
#include <algorithm>
#include <random>

void GenericAlgorithm::Run(GenericAlgorithm gen, int count) {
	gen.CreateSolutions(count);
	gen.EvaluateFitnesses();
	gen.SortCollection();
	gen.PrintCollection();
}

void GenericAlgorithm::Fitness() {
	double ans = (6 * X + -Y + std::pow(Z, 200)) - 25;
	Score = std::abs(1 / ans);
}

void GenericAlgorithm::EvaluateFitnesses() {
	for (auto& c : Collection)
	{
		c.Fitness();
	}
}

void GenericAlgorithm::SortCollection() {
	std::sort(Collection.begin(), Collection.end(), [](const auto& left, const auto& right)
		{
			return left.Score > right.Score;
		});
}

void GenericAlgorithm::PrintCollection() {
	std::for_each(Collection.begin(), Collection.begin() + 10, [](const auto& c) {
		std::cout << std::fixed << "\nScore: " << c.Score << "\n x: " << c.X << " y: " << c.Y << " z: " << c.Z << "\n";
	});
}

void GenericAlgorithm::CreateSolutions(int count) {
	std::random_device rd;
	std::uniform_real_distribution<double> dis(-100, 100);

	for (size_t i = 0; i < count; i++)
	{
		GenericAlgorithm tmp;
		tmp.Score = 0;
		tmp.X = dis(rd);
		tmp.Y = dis(rd);
		tmp.Z = dis(rd);

		Collection.push_back(tmp);
	}
}