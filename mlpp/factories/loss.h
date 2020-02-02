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

    virtual void SetData(mlpp::tensor<1,double>::type y_hat, mlpp::tensor<1,double>::type y)
    {
        if (y_hat.size() != y.size())
            throw "Loss Error: Predicted size and actual size not matching.";
        y_hat_ = y_hat;
        y_ = y;
        result_ = 0;
        Calculate();
    }

    virtual void SetCategoricalData(mlpp::tensor<2,double>::type y_hat, mlpp::tensor<2,double>::type y) {};

protected:
    mlpp::tensor<1,double>::type y_hat_, y_;
    double result_ = 0;
    virtual void Calculate() = 0;
};
