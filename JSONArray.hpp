#ifndef __jsonarray_hpp_
#define __jsonarray_hpp_

#include "JSONDataObject.hpp"
#include <memory>
#include <fstream>

class JSONArray {
public:
    JSONArray();
    ~JSONArray();
    //std::vector<JSONDataObject *> *listOfDataObjects() { return _listOfDataObjects; }
    std::shared_ptr<std::vector<std::shared_ptr<JSONDataObject>>> listOfDataObjects() { return _listOfDataObjects; }
    virtual std::shared_ptr<JSONDataObject> jsonObjectNode() = 0;
    int numJSONObjects();
    void parseJSONArray(std::fstream &stream);
    virtual void print();

protected:
    //std::vector<JSONDataObject *> *_listOfDataObjects;
    std::shared_ptr<std::vector<std::shared_ptr<JSONDataObject>>> _listOfDataObjects;
};

#endif
