#ifndef __JSONDataItem__
#define __JSONDataItem__

#include <string>
#include <fstream>
#include <iostream>

class JSONDataItem {
public:
    JSONDataItem();
    ~JSONDataItem();
    void parseJSONItem(std::fstream &stream);
    std::string attribute()    { return _attribute; }
    int integerValue()         { return _ivalue;    }
    std::string stringValue()  { return _svalue;    }
    bool isNumber()            { return _isNumber;  }
    void print();  // purely for debugging -- any format you want
    
private:
    std::string _attribute{""}, _svalue{""};
    int _ivalue{0};
    bool hasReadAnItem{false}, _isNumber{false};
    
    std::string readQuotedString(std::fstream &stream);
};

#endif

