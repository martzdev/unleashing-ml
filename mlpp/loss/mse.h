#pragma once
#include <vector>
#include "../contracts/iloss.h";
#include "../utils.h";

class MSE : ILoss
{
public:
    MSE(std::vector<double> y_hat, std::vector<double> y)
    {
        if (y_hat.size() != y.size())
            throw "Loss Error: Predicted size and actual size not matching.";
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
            result_ += (y_hat_[i] - y_[i]) * (y_hat_[i] - y_[i]);

        result_ /= y_hat_.size();
    }
};
