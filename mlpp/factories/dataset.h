#pragma once

#include <vector>
#include "../contracts/idataset.h"

class Dataset : public virtual IDataset
{
public:
    virtual std::string GetTitle()
    {
        return title_;
    }
    virtual std::vector<std::vector<double>> GetX() = 0;
    virtual std::vector<std::vector<double>> GetY() = 0;

protected:
    std::string title_;
    virtual void FetchData() = 0;
};
