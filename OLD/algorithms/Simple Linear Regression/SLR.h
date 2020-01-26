#pragma once
#include <math.h>
#include "../../lib/UnleashingML.h"

class SLR
{
public:
    void fit(std::vector<float> inputs, std::vector<float> outputs)
    {
        if (X.size() != y.size())
        {
            printf("X and y must have the same sizes");
            return;
        }
        X = inputs;
        y = outputs;

        mean_x = mean(X);
        mean_y = mean(y);

        r = calculate_r();
        b = calculate_b();
        a = calculate_a();
    }

    std::vector<float> predict(std::vector<float> inputs)
    {
        std::vector<float> results;
        for (int i = 0; i < inputs.size(); i++)
        {
            int data = a + (b * inputs[i]);
            results.push_back(a + b * inputs[i]);
        }
        return results;
    }

private:
    float mean(std::vector<float> v)
    {
        int sum=0;
        for (int i = 0; i < v.size(); i++)
            sum += v[i];

        return sum / v.size();
    }

    float calculate_r()
    {
        float numerator = 0, denominator = 0;
        for (int i = 0; i < X.size(); i++)
        {
            numerator += (X[i] - mean_x) * (y[i] - mean_y);
            denominator += (X[i] - mean_x) * (X[i] - mean_x) * (y[i] - mean_y) * (y[i] - mean_y);
        }
        return numerator / sqrt(denominator);
    }

    float calculate_b()
    {
        float std_x;
        float std_y;
        for (int i = 0; i < X.size(); i++)
        {
            std_x += X[i] - mean_x;
            std_y += y[i] - mean_y;
        }
        std_x = sqrt(std_x / X.size());
        std_y = sqrt(std_y / X.size());
        return r * (std_x / std_y);
    }

    float calculate_a()
    {
        return mean_y - (b * mean_x);
    }

    std::vector<float> X;
    std::vector<float> y;
    float mean_x = 0;
    float mean_y = 0;
    float a = 0;
    float b = 0;
    float r = 0;
};

//