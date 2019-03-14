#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <tuple>

struct datapoint {
	std::vector<float> values;
	std::string label;
};


struct compare_values
{
	inline bool operator() (const datapoint& struct1, const datapoint& struct2)
	{
		return (struct1.values[0] < struct2.values[0]);
	}
};

struct dataset {
	std::vector < std::vector<float> > X;
	std::vector< std::string > y;
};

class CSVReader {
public:
	std::vector<std::vector<std::string>> readCSV(std::string filename, bool hasHeaders = false) {
		std::ifstream file(filename);
		std::vector<std::vector<std::string>> data;
		std::string rawLine;

		size_t iter = 0;
		while (std::getline(file, rawLine)) {
			if (hasHeaders && iter == 0) {
				iter++;
				continue;
			}
			else
				data.push_back(processLine(rawLine, ","));
			iter++;
		}
		return data;
	}

	std::tuple<std::vector<std::vector<std::string>>, std::vector<std::string>> splitData(std::vector<std::vector<std::string>> data, size_t XEnd) {
		if (data.size() > 0 && data[0].size() > XEnd) {
			std::vector<std::vector<std::string>> X;
			std::vector<std::string> y;

			for (size_t i = 0; i < data.size(); i++) {
				std::vector<std::string> XLine;
				for (size_t j = 0; j < data[i].size(); j++) {
					if (j <= XEnd)
						XLine.push_back(data[i][j]);
					else
						y.push_back(data[i][j]);
				}
				X.push_back(XLine);
			}
			return std::make_tuple(X, y);
		}
		else {
			printf("The dataset you passed is too small.");
			std::tuple<std::vector<std::vector<std::string>>, std::vector<std::string>> empty;
			return empty;
		}
	}

	std::vector<std::vector<float>> convertToFloat(std::vector<std::vector<std::string>> data) {
		std::vector<std::vector<float>> converted;

		for (size_t i = 0; i < data.size(); i++) {
			std::vector<float> convertedLine;
			for (size_t j = 0; j < data[i].size(); j++) {
				convertedLine.push_back(std::stof(data[i][j]));
			}
			converted.push_back(convertedLine);
		}

		return converted;
	}

private:
	std::vector<std::string> processLine(std::string raw, std::string delimiter) {
		std::vector<std::string> tokenVector;

		size_t pos = 0;
		while ((pos = raw.find(delimiter)) != std::string::npos) {
			tokenVector.push_back(raw.substr(0, pos));
			raw.erase(0, pos + delimiter.length());
		}
		tokenVector.push_back(raw);

		return tokenVector;
	}
};

