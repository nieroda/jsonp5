#ifndef __albums_hpp_
#define __albums_hpp_

#include "Album.hpp"
#include <memory>
#include "JSONArray.hpp"
#include <iostream>
#include <fstream>
#include <string>

class Albums : public JSONArray {
public:
  Albums();
  ~Albums();

  int numAlbums();
  void addAlbum(Album *album);
  void loadAlbumsFromFile(std::string fileName);
  std::string htmlString();
   //set track for album, set track for image
   std::shared_ptr<std::vector<std::shared_ptr<JSONDataObject>>> listofAlbums() { return _listOfDataObjects; }
   //std::vector<std::shared_ptr<Albums>> listovAlbums() { return _listOfDataObjects.get(); }
   //std::shared_ptr<std::vector<std::shared_ptr<reinterpret_cast<Album *>(_listOfDataObjects.get())>>> listovAlbums() { return _listOfDataObjects; }
   std::shared_ptr<JSONDataObject> jsonObjectNode() { return std::make_shared<Album>(); }
  void runAsserts();  // used for checking the integrity of this class.
};

#endif
