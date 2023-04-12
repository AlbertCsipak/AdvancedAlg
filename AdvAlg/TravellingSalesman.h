#pragma once
#include <vector>
#include <iostream>

class Town
{
public:
	float x;
	float y;
	int id;
};

class TravellingSalesmanProblem
{
public:
	std::vector<Town> towns;
	float objective(std::vector<Town> solution);
	void loadTownsFromFile(std::string fileName);
	void saveTownsToFile(std::string fileName, std::vector<Town> townVector);
};
