#pragma once
#include "../../lib/UnleashingML.h"

struct Neuron {
    float data;
    float weight;
    struct Neuron *next;
};

class Perceptron {
    public:
    void init(std::vector<std::vector<float>> X, std::vector<float> y, float lr) {
        srand(time(NULL));
		learningRate = lr;
		if (X.size() == y.size()) {
			for (size_t i = 0; i < X.size(); i++) {
				appendToDataset(X[i], y[i]);
			}	
		}
		else {
			printf("ERROR: X and y must have the same sizes.\n");
		}
	}
    void train() {
        for(size_t i; i<inputLayer.size();i++) {    
            float result = forwardPropagate(inputLayer[i]);
        }
    }
    private:
    void forwardPropagate() {
        return;
    }
    void appendToDataset(std::vector<float> point, float label) {
        if(inputSize==0) inputSize = point.size();
        else if(inputSize!=point.size()) { 
            printf("WAR: Input size is not constant.\n");
            return;
        }
        std::vector<Neuron> inputVector;
        for(size_t i = 0;i< point.size();i++) {
            Neuron instance;
            instance.data = point[i];
            instance.weight = rand();
            instance.next = NULL;
            inputVector.push_back(instance);
        }
        trueOutputs.push_back(label);
    }
    float learningRate;
    int inputSize = 0;
    std::vector<std::vector<Neuron>> inputLayer;
    std::vector<float> trueOutputs;
    Neuron outputLayer;
};
