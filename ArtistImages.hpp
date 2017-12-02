#ifndef __artistImages_hpp
#define __artistImages_hpp

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "ArtistImage.hpp"
#include "JSONArray.hpp"

class ArtistImages: public JSONArray {
public:
  ArtistImages();
  ~ArtistImages();

  int numArtistImages();
  void addArtistImage(ArtistImage *aimage);
  ArtistImages* imageswithID(int aID);
  void loadArtistImagesFromFile(std::string fileName);
  std::string htmlString();
  JSONDataObject *jsonObjectNode() { return new ArtistImage(); }
  std::vector<ArtistImage *> *listofArtistImages() { return (std::vector<ArtistImage *>*) _listOfDataObjects; }
  void runAsserts();
};

#endif

/*
{"height": 600, "uri": "http://cWolf.cs.sonoma.edu/~cs315/projects/project5/images/A-82730-1419714988-9675.jpeg",
"artist_id": 82730, "width": 600, "type": "primary"}
*/
