#pragma once

#include "../contracts/iloss.h"
#include "../utils.h"

class Loss : public virtual ILoss
{
public:
    virtual double GetLoss()
    {
        return result_;
    }

    virtual void SetData(std::vector<double> y_hat, std::vector<double> y)
    {
        if (y_hat.size() != y.size())
            throw "Loss Error: Predicted size and actual size not matching.";
        y_hat_ = y_hat;
        y_ = y;
        result_ = 0;
        Calculate();
    }

    virtual void SetCategoricalData(mlpp::tensor<double> y_hat, mlpp::tensor<double> y) {};

protected:
    std::vector<double> y_hat_, y_;
    double result_ = 0;
    virtual void Calculate() = 0;
};
