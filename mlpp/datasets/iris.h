#pragma once

#include <fstream>
#include <string>
#include "../factories/dataset.h"

class IrisData : public Dataset
{
public:
    IrisData(bool local = false, std::string path = "")
    {
        if (local)
        {
            // TODO: implement local logic
        }
        else
        {
            // TODO: implement request logic
        }
    }
    virtual std::vector<std::vector<double>> GetX() {}
    virtual std::vector<std::vector<double>> GetY() {}

protected:
    std::string title_ = "Iris Flower Dataset";
    virtual void FetchData() {
        // TODO: implement data fetching
    }
};
