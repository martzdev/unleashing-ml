#pragma once

class ILoss
{
public:
    virtual double GetLoss() = 0;
protected:
    double y_hat_, y_, result_;
    virtual void Calculate() = 0;
};
