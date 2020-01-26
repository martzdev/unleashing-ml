#include "../../lib/UnleashingML.h"
#include "SLR.h"
#include <fstream>

std::ifstream fin("data.txt");

int main() {
    std::vector<float> X, y;
    float a,b;
    while(!fin.eof()) {
        fin >> a >> b;
        X.push_back(a);
        y.push_back(b);
    }
    SLR model;
    model.fit(X, y);
    std::vector<float> test;
    test.push_back(6);
    std::vector<float> yTest= model.predict(test);
    for(int i = 0;i<yTest.size();i++) {
        std::cout << yTest[i] << " ";
    }
    std::cout << "\n";
}