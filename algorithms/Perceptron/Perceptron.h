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
        int correct;
        if(epochs<1) epochs = 1;
        for(size_t it=1;it<=epochs;it++) {
            for(size_t i=0; i<inputLayer.size();i++) {
                assignNode(i);
                float result = forwardPropagate(inputLayer[i]);
                backPropagate(i,result,trueOutputs[i]);
                if(result >= 0.5 && trueOutputs[i]==1) correct++;
                unassignNode(i);
            }
            printf("Epoch %i - ACC:%2.5f\n",it,calculateAcc(correct));
        }
        
    }
    private:
    float calculateError(float outpt, float trueOutpt) {
        return abs(outpt-trueOutpt);
    }
    float calculateAcc(int &good) {
        float acc = ((inputLayer.size()-good)/inputLayer.size())*100;
        good = 0;
        return acc;
    }
    void assignNode(size_t poz) {
        outputLayer = new Neuron();
        for(size_t i=0;i<inputLayer[poz].size();i++) {
            inputLayer[poz][i].next = outputLayer;
        }
    }
    void unassignNode(size_t poz) {
        outputLayer->data = 0;
        for(size_t i=0;i<inputLayer[poz].size();i++) {
            inputLayer[poz][i].next = NULL;
        }
    }
    void backPropagate(int poz, float outpt, float trueOutpt) {
        for(int i = 0;i<inputLayer[poz].size();i++) {
            inputLayer[poz][i].weight += learningRate*(trueOutpt-outpt);
        }
    }
    float forwardPropagate(std::vector<Neuron> inpt) {
        for(size_t i=0;i<inpt.size();i++) {
            inpt[i].next->data += inpt[i].data*inpt[i].weight;
        }
        return outputLayer->data;

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
            instance.weight = (rand()%100+1)/1000;
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
