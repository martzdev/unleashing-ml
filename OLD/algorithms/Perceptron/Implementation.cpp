#include "../../lib/UnleashingML.h"
#include "Perceptron.h"

int main() {
	CSVReader csv;
	auto data = csv.readCSV("data.csv");
	auto splittedData = csv.splitData(data, 3);
	auto unconvertedX = std::get<0>(splittedData);
	auto unconvertedy = std::get<1>(splittedData);
	auto X = csv.convertToFloat(unconvertedX);
    std::vector<std::vector<std::string>> fillery;
    fillery.push_back(unconvertedy);
    auto y = csv.convertToFloat(fillery)[0];
    Perceptron network;
    network.compile(X,y,0.001);
	network.train(3);
}
