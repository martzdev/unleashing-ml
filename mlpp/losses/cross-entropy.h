#pragma once

#include "../factories/loss.h"
#include "../utils.h"

class BinaryCrossEntropy : public virtual Loss
{
public:
    BinaryCrossEntropy() {}

protected:
    virtual void Calculate()
    {
        for (unsigned long i = 0; i < y_hat_.size(); i++)
        {
            result_ += y_[i] * log(y_hat_[i]);
        }
        if (result_ != 0)
            result_ = -result_;
    }
};

class CategoricalCrossEntropy : public virtual Loss
{
public:
    CategoricalCrossEntropy() {}

    virtual void SetCategoricalData(mlpp::tensor<double> y_hat, mlpp::tensor<double> y)
    {
        if (y_hat.size() != y.size())
            throw "Loss Error: Predicted size and actual size not matching.";
        c_y_hat_ = y_hat;
        c_y_ = y;
        result_ = 0;
        Calculate();
    }

protected:
    mlpp::tensor<double> c_y_hat_, c_y_;
    virtual void Calculate()
    {
        for (unsigned long i = 0; i < c_y_hat_.size(); i++)
            for (unsigned long j = 0; j < c_y_hat_[i].size(); j++)
            {
                result_ += c_y_[i][j] * log(c_y_hat_[i][j]);
            }
        if (result_ != 0)
            result_ = -result_;
    }

    mlpp::tensor<double> y_hat_;
    mlpp::tensor<double> y_;
};
