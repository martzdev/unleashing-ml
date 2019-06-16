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
		if(lr>0 && lr<1) learningRate = lr;
		if (X.size() == y.size()) {
			for (size_t i = 0; i < X.size(); i++) {
				appendToDataset(X[i], y[i]);
			}	
		}
		else {
			printf("ERROR: X and y must have the same sizes.\n");
		}
        assignNodes();
	}
    void train(int epochs) {
        if(epochs<1) epochs = 1;
        for(size_t it=1;it<=epochs;it++) {
            printf("Epoch %i - ",it);
            float mae = 0;
            for(size_t i=0; i<inputs.size();i++) {
                giveData(inputs[i]);
                float result = forwardPropagate();
                backPropagate(result,trueOutputs[i]);
                mae = calculateError(result,trueOutputs[i]);
            }
            printf("MAE: %.3f\n",mae/inputs.size());
        }
        
    }
    private:
    float calculateError(float predicted, float actual) {
        return abs(predicted-actual);
    }
    void assignNodes() {
        srand(time(NULL));
        outputNode = new Neuron();
        for(size_t i = 0;i<inputSize;i++) {
            Neuron node;
            node.weight = (rand()%100+1)/1000;
            node.next = outputNode;
            inputLayer.push_back(node);
        }
    }
    void giveData(std::vector<float> inpt) {
        if(inpt.size()>inputSize || inpt.size() < inputSize) return;
        for(size_t i = 0;i<inputSize;i++) {
            inputLayer[i].data = inpt[i];
        }
        outputNode->data = 0;
    }
    void backPropagate(float outpt,float trueOutpt) {
        for(size_t i = 0;i<inputLayer.size();i++) {
            inputLayer[i].weight += learningRate*(trueOutpt-outpt);
        }
    }
    float forwardPropagate() {
        for(size_t i=0;i<inputLayer.size();i++) {
            inputLayer[i].next->data += inputLayer[i].data*inputLayer[i].weight;
        }
        return outputNode->data;
    }
    void appendToDataset(std::vector<float> point, float label) {
        if(inputSize==0) inputSize = point.size();
        else if(inputSize!=point.size()) { 
            printf("ERR: Input size is not constant.\n");
            return;
        }
        std::vector<float> inputVector;
        for(size_t i = 0;i< point.size();i++) {
            inputVector.push_back(point[i]);
        }
        trueOutputs.push_back(label);
        inputs.push_back(inputVector);
    }
    float learningRate;
    int inputSize = 0;
    std::vector<std::vector<float>> inputs;
    std::vector<float> trueOutputs;
    std::vector<Neuron> inputLayer;
    Neuron* outputNode;
};
