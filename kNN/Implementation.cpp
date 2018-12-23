#include "kNN.h"
#include <fstream>
#include <iostream>
#include <algorithm>

std::ifstream fin("dataset.txt");

void getReq(int &features, int &neighbors, int &size) {
    std::cout << "Numeric features: ";
    std::cin >> features;
    std::cout << "Number of neighbors: ";
    std::cin >> neighbors;
    std::ifstream lines("dataset.txt");
    size = std::count(std::istreambuf_iterator<char>(lines), std::istreambuf_iterator<char>(), '\n')+1;
    lines.close();
}

void readData(datapoint data[], int size, int features) {
    for(int i = 0;i<size;i++) {
        for(int j = 0;j<features;j++) {
            fin >> data[i].features[j];
        }
        fin >> data[i].className;
    }
}

void testModel(float point[], int features) {
    for(int i = 0;i<features;i++) {
        std::cin >> point[i];
    }
}


int features, neighbors, size;
datapoint train[256];
float testPoint[256];
char prediction[256];

int main() {
    getReq(features,neighbors,size);

    readData(train, size, features);
    KNearestNeighbors model;
    model.fit(train,features,size,neighbors);

    testModel(testPoint,features);
    
    strcpy(prediction,model.predict(testPoint));
    std::cout << prediction << std::endl;
}