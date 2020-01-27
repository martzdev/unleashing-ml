#pragma once

#include <vector>
#include "../contracts/iloss.h"

class Loss : public virtual ILoss
{
public:
    virtual double GetLoss() {
        return result_;
    }

    virtual void SetData(std::vector<double> y_hat, std::vector<double> y)
    {
        if(y_hat.size()!=y.size()) throw "Loss Error: Predicted size and actual size not matching.";
        y_hat_ = y_hat;
        y_ = y;
        result_ = 0;
        Calculate();
    }
    
protected:
    std::vector<double> y_hat_, y_;
    double result_ = 0;
    virtual void Calculate() = 0;
};
