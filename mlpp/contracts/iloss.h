#pragma once

class ILoss
{
public:
    virtual double GetLoss() = 0;
protected:
    virtual void Calculate() = 0;
};
