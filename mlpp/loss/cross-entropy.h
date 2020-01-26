#pragma once
#include <vector>
#include <math.h>
#include "../contracts/iloss.h";
#include "../utils.h";

class BinaryCrossEntropy : ILoss
{
public:
    BinaryCrossEntropy(std::vector<double> y_hat, std::vector<double> y)
    {
        if (y_hat.size() != y.size())
        {
            throw std::logic_error("Loss Error: Predicted size and actual size not matching.");
        }
        y_hat_ = y_hat;
        y_ = y;
        Calculate();
    }

    double GetLoss()
    {
        return result_;
    }

protected:
    std::vector<double> y_hat_, y_;
    double result_ = 0;
    void Calculate()
    {
        for (int i = 0; i < y_hat_.size(); i++)
        {
            result_ += y_[i] * log(y_hat_[i]);
        }
        if (result_ != 0)
            result_ = -result_;
    }
};

class CategoricalCrossEntropy : ILoss {
    // TODO: Implemet categorical cross entropy
};