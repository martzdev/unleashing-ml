#pragma once

class ILoss
{
public:
    virtual double GetLoss() = 0;
    virtual void SetData(std::vector<double> y_hat, std::vector<double> y) = 0;

protected:
    virtual void Calculate() = 0;
};
