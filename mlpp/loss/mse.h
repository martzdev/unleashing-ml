#pragma once
#include "../contracts/iloss.h";

class MSE : ILoss
{
public:
    MSE(double y_hat, double y)
    {
        y_hat_ = y_hat;
        y_ = y;
        Calculate();
    }
    
    double GetLoss() {
        return result_;
    }

protected:
    double y_hat_, y_, result_;
    void Calculate()
    {
        result_ = (y_hat_ - y_) * (y_hat_ - y_);
        result_ /= 2;
    }
};
