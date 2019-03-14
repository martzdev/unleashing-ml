#pragma once
#include "UnleashingML.h"

class KNearestNeighbors {
public:
	void fit(std::vector<std::vector<float>> X, std::vector<std::string> y, int num_neighbors) {
		neighbors = num_neighbors;
		if (X.size() == y.size()) {
			for (size_t i = 0; i < X.size(); i++) {
				appendToDataset(X[i], y[i]);
			}	
		}
		else {
			printf("ERROR: X and y must have the same sizes.\n");
		}
	}

	std::string predict(std::vector<float> X) {
		if (data.size() > 0) {
			if (data[0].values.size() == X.size()) {
				std::vector<datapoint> distances;
				for (size_t i = 0; i < data.size(); i++) {
					datapoint distanceToNewPoint;
					distanceToNewPoint.label = data[i].label;
					distanceToNewPoint.values.push_back(euclideanDistance(X, data[i].values));
					distances.push_back(distanceToNewPoint);
				}
				std::sort(distances.begin(), distances.end(), compare_values());
				std::string predictedLabel = countVotes(distances);
				appendToDataset(X, predictedLabel);
				return predictedLabel;
			}
			else {
				printf("ERROR: Data's shape does not match the shape encountered in training.\n");
				return "ERR";
			}
		}
		else {
			printf("ERROR: You must fit a dataset first.\n");
			return "ERR";
		}
	}
private:
	void appendToDataset(std::vector<float> X, std::string y) {
		datapoint newDatapoint;
		newDatapoint.values = X;
		newDatapoint.label = y;
		data.push_back(newDatapoint);
	}
	float euclideanDistance(std::vector<float> firstPoint, std::vector<float> secondPoint) {
		float sum = 0;
		for (size_t i = 0; i < firstPoint.size(); i++) {
			sum += (firstPoint[i] - secondPoint[i])*(firstPoint[i] - secondPoint[i]);
		}
		return sqrt(sum);
	}
	std::string countVotes(std::vector<datapoint> distances) {
		std::map<std::string, int> votes;
		if (distances.size() > neighbors) {
			for (int i = 0; i < neighbors; i++)
				votes[distances[i].label]++;
			std::string finalLabel;
			int maxVotes=-1;
			for (auto const &x : votes) {
				if (x.second > maxVotes) {
					finalLabel = x.first;
					maxVotes = x.second;
				}
			}
			return finalLabel;
		}
		else {
			printf("ERROR: The dataset fitted is too small.\n");
			return "ERR";
		}
	}

	int neighbors;
	std::vector<datapoint> data;
};