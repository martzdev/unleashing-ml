#include <math.h>
#include <cstring>

// creating a structure to hold our dependent and independent variables
struct datapoint {
    // X
    float features[256];
    // y
    char className[245];
};

// structuring everything in a class
class KNearestNeighbors {
    public:
        // dataset fitting function
        void fit(datapoint data[], int features, int samples, int neighbors) {
            k = neighbors;
            trainSize = samples;
            dataFeatures = features;
            // assign given data in a private 'datapoint'
            for(int i = 0;i<trainSize;i++) {
                for(int j = 0;j<dataFeatures;j++) {
                    trainData[i].features[j] = data[i].features[j];
                }
                strcpy(trainData[i].className,data[i].className);
            }
        }
        // predicting function
        char* predict(float newPoint[]) {
            // creating a 'neighbors' datapoint array
            datapoint kNN[256];
            // save the euclidean distance between all data points and the unknown point
            for(int i = 0;i<trainSize;i++) {
                for(int j = 0;j<dataFeatures;j++) {
                    kNN[i].features[0] = euclideanDistance(trainData[i].features, newPoint);
                }
                strcpy(kNN[i].className,trainData[i].className);
            }
            // sort everything 
            for(int i = 0;i<trainSize-1;i++) {
                for(int j = i+1;j<trainSize;j++) {
                    if(kNN[i].features[0]>kNN[j].features[0]) {
                        datapoint aux = kNN[i];
                        kNN[i] = kNN[j];
                        kNN[j] = aux;
                    }
                }
            }
            char prediction[256];
            // count 'votes' from the first K neighbors
            strcpy(prediction,countVotes(kNN));
            // add the newly predicted point to the dataset
            addToDataset(prediction,newPoint);
            // return predictions
            return prediction;
        }
    private:
        // variables to save hyperparams
        int k;
        int dataFeatures;
        int trainSize;
        datapoint trainData[256];

        // euclidean distance
        float euclideanDistance(float p1[], float p2[]) {
            float sum = 0;
            for(int i = 0;i<=dataFeatures;i++)
                sum += (p1[i]-p2[i])*(p1[i]-p2[i]);
            return sqrt(sum);
        }

        // counting 'votes' for the first K neighbors
        char* countVotes(datapoint neighbors[]) {
            datapoint votes[256];
            for(int i = 0;i<k;i++) {
                if(strcmp(votes[i].className,neighbors[i].className)==0) {
                    votes[i].features[0]++;
                } else {
                    strcpy(votes[i].className,neighbors[i].className);
                    votes[i].features[0]++;
                }
            }
            for(int i = 0;i<k-1;i++) {
                for(int j = i+1;j<k;j++) {
                    if(votes[i].features[0]>votes[j].features[0]) {
                        datapoint aux = votes[i];
                        votes[i] = votes[j];
                        votes[j] = aux;
                    }
                }
            }
            return votes[0].className;
        }
        // append point to dataset
        void addToDataset(char className[], float features[]) {
            datapoint newP;
            strcpy(newP.className,className);
            for(int i = 0;i<dataFeatures;i++) {
                newP.features[i] = features[i];
            }
            trainData[++trainSize] = newP;
        }
};
