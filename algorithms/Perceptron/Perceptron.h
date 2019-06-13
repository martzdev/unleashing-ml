#pragma once
#include "../../lib/UnleashingML.h"

class Neuron {
    public:
    float data;
    float weight;
    Neuron *next;
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
    void train(int epochs) {
        if(epochs<1) epochs = 1;
        for(size_t it=1;it<=epochs;it++) {
            for(size_t i=0; i<inputLayer.size();i++) {
                assignNode(i);    
                float result = forwardPropagate(inputLayer[i],trueOutputs[i]);
                printf("Result = %.3f",result);
            }
        }
    }
    private:
    void assignNode(size_t poz) {
        outputLayer = new Neuron();
        for(size_t i=0;i<inputLayer[poz].size();i++) {
            inputLayer[poz][i].next = outputLayer;
        }
    }
    float forwardPropagate(std::vector<Neuron> inpt,float yHat) {
        for(size_t i=0;i<inpt.size();i++) {
            inpt[i].next->data += inpt[i].data*inpt[i].weight;
        }
        float error = pow(outputLayer->data - yHat,2)/2;
        return error;

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
        inputLayer.push_back(inputVector);
    }
    float learningRate;
    int inputSize = 0;
    std::vector<std::vector<Neuron>> inputLayer;
    std::vector<float> trueOutputs;
    Neuron* outputLayer = NULL;
};
