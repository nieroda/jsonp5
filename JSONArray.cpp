#include "JSONArray.hpp"
#include "JSONDataObject.hpp"
#include <vector>

JSONArray::JSONArray() {
    //_listOfDataObjects = std::make_shared<std::vector<std::shared_ptr<JSONDataObject>>>();
    _listOfDataObjects = new std::vector<JSONDataObject *>;
}



JSONArray::~JSONArray() {
    //std::cout << "Destructor was called" << std::endl;
}

int JSONArray::numJSONObjects() {
    return _listOfDataObjects->size();
}

void JSONArray::parseJSONArray(std::fstream &stream) {
    char cc[2], prev = ' ';
    cc[1] = '\0';
    if( !(stream >> cc[0] || cc[0] != '['))
        std::exit(1);

    do {
      //auto jsitem = std::make_shared<JSONDataItem>();
      //JSONDataItem *jsitem = new JSONDataItem();
      //std::make_shared<Album>(*album)
      auto a = jsonObjectNode();
      a->parseFromJSONstream(stream);
      //auto a = std::make_shared<JSONDataObject>(*jsitem);
      _listOfDataObjects->push_back(a);



      /*
        auto jsitem = std::make_shared<JSONDataObject>();
        //sJSONDataObject *jsitem = new JSONDataObject();
        jsitem->parseFromJSONstream(stream);
        _listOfDataObjects->push_back(jsitem);
*/
        if( !(stream >> cc[0]) )
            std::exit(1);

        if( cc[0] != ']' && cc[0] != ',')
            std::exit(1);
    } while( cc[0] != ']' );
}

void JSONArray::print() {
  std::cout << "Print in JSONArray is being called" << std::endl;
  for ( auto i : *_listOfDataObjects )
    i->print();
}
