#pragma once

#include <vector>
#include <math.h>
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

class CategoricalCrossEntropy : ILoss
{
    // TODO: Implemet categorical cross entropy
};
