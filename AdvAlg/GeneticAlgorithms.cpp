#include "GeneticAlgorithms.h"
#include "Random.h"
#include <math.h>
#include <iostream>
#include <algorithm>
#include <random>

//fitness generálás
void GenericAlgorithm::Fitness() {
	double ans = (6 * X + -Y + std::pow(Z, 200)) - 25;
	Score = std::abs(1 / ans);
}


//fitness kiértékelés
void GenericAlgorithm::EvaluateFitnesses() {
	for (auto& c : Collection)
	{
		c.Fitness();
	}
}

//sort
void GenericAlgorithm::SortCollection() {
	std::sort(Collection.begin(), Collection.end(), [](const auto& left, const auto& right)
		{
			return left.Score > right.Score;
		});
}

//kiiratás
void GenericAlgorithm::PrintCollection() {
	std::for_each(Collection.begin(), Collection.begin() + 10, [](const auto& c) {
		std::cout << std::fixed << "\nScore: " << c.Score << "\n x: " << c.X << " y: " << c.Y << " z: " << c.Z << "\n";
		});
}

//random létrehozás
void GenericAlgorithm::CreateSolutions() {
	std::random_device rd;
	std::uniform_real_distribution<double> dis(-1000, 1000);

	for (size_t i = 0; i < BatchSize; i++)
	{
		GenericAlgorithm tmp;
		tmp.Score = 0;
		tmp.X = dis(rd);
		tmp.Y = dis(rd);
		tmp.Z = dis(rd);

		Collection.push_back(tmp);
	}
}

//legjobb n átmásolása
void GenericAlgorithm::TakeBestSolutions() {

	BestCollection.clear();
	std::copy(Collection.begin(), Collection.begin() + SampleSize, std::back_inserter(BestCollection));

	Collection.clear();
	for (size_t i = 0; i < SampleSize; i++)
	{
		Collection.push_back(BestCollection[i]);
	}
}

//mutálás
void GenericAlgorithm::MutateSolutions(double percentage) {
	std::random_device rd;
	std::uniform_real_distribution<double> dis(1 - percentage, 1 + percentage);

	std::for_each(BestCollection.begin(), BestCollection.end(), [&](auto& c)
		{
			c.X *= dis(rd);
			c.Y *= dis(rd);
			c.Z *= dis(rd);
		});
}

//crossover
void GenericAlgorithm::Crossover() {
	std::random_device rd;
	std::uniform_real_distribution<double> dis(0, SampleSize - 1);

	for (size_t i = SampleSize; i < BatchSize; i++)
	{
		GenericAlgorithm tmp;
		tmp.Score = 0;
		tmp.X = BestCollection[dis(rd)].X;
		tmp.Y = BestCollection[dis(rd)].Y;
		tmp.Z = BestCollection[dis(rd)].Z;

		Collection.push_back(tmp);
	}

}