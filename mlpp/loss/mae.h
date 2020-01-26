#pragma once
#include "../contracts/iloss.h";
#include "../utils.h";

class MAE : ILoss
{
public:
    MAE(double y_hat, double y)
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
        result_ = mlpp::abs<double>(y_hat_ - y_);
    }
};
