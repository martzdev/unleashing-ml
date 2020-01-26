#pragma once
#include <vector>
#include <string>

class IDataset
{
public:
    virtual std::string GetTitle() = 0;
    virtual std::vector<double> GetX() = 0;
    virtual std::vector<double> GetY() = 0;
protected:
    virtual void FetchData() = 0;
};
