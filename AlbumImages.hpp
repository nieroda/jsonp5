#ifndef __albumImages_hpp
#define __albumImages_hpp

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "AlbumImage.hpp"
#include "JSONArray.hpp"

class AlbumImages: public JSONArray {
public:
  AlbumImages();
  ~AlbumImages();

  int numAlbumImage();
  void addAlbumImage(AlbumImage *aimage);
  AlbumImages* albumImagewithID(int aID);
  void loadAlbumImagesFromFile(std::string fileName);
  std::string htmlString();
  JSONDataObject *jsonObjectNode() { return new AlbumImage(); }
  std::vector<AlbumImage *> *listOfAlbumImages() { return (std::vector<AlbumImage *> *) _listOfDataObjects; }
  void runAsserts();

};

#endif

/*
{"height": 505, "type": "primary",
"uri": "http://cWolf.cs.sonoma.edu/~cs315/projects/project5/images/R-1789539-1356465446-1930.jpeg",
"width": 500, "album_id": 45574}
*/

/*
{"height": 505, "type": "primary", "uri": "http://cWolf.cs.sonoma.edu/~cs315/projects/project5/images/R-1789539-1356465446-1930.jpeg", "width": 500, "album_id": 45574}
*/
