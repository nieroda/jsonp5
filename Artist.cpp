#include "Artist.hpp"


Artist::Artist() {}

Artist::~Artist() {
    //delete _primaryImage;
    //delete _secondaryImage;
    //delete _albums;
}

std::string Artist::profile() {
    if( cachedProfile )
        return _profile;
    cachedProfile = true;
    return _profile = valueForStringAttribute("profile");
}

std::string Artist::artistName() {
    if ( cachedName )
        return _name;
    cachedName = true;
    return _name = valueForStringAttribute("artist_name");
}

std::string Artist::realName() {
    if ( cachedRealName )
        return _realName;
    cachedRealName = true;
    return _realName = valueForStringAttribute("real_name");
}

std::string Artist::numImages() {
    if ( cachedNumImages )
        return _numImages;
    cachedNumImages = true;
    return _numImages = valueForStringAttribute("num_images");
}

int Artist::artistID() {
    if ( cachedArtistID )
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}


void Artist::setArtistImages(ArtistImages *ai) {
  auto images = ai->imageswithID(artistID());
  for (auto i : *images->listofArtistImages()) {
    if (i->type() == "primary")
      _primaryImage = i;
    else if (i->type() == "secondary") {
      _secondaryImage = i;
    }
  }
}

void Artist::print() {
  std::cout << "Print has been called in ARTIST!" << std::endl;
  std::cout << "ArtistID: " << artistID() << std::endl;
  std::cout << "Profile: " << profile() << std::endl;
  std::cout << "ArtistName(): " << artistName() << std::endl;
  std::cout << "RealName() : " << realName() << std::endl;
  std::cout << "numImages()" << numImages() << std::endl;

  if (_albums) {
    std::cout << "We have an albums calling runAsserts" << std::endl;
    for (auto i : *_albums->listofAlbums()) {
      std::cout << "Before print" << std::endl;
      i->print();
      std::cout << "After print" << std::endl;
    }

  } else {
    std::cout << "We have no album :( " << std::endl;
  }

  if (_primaryImage) {
    std::cout << "\n\nWe have a primary image! Calling print" << std::endl;
    _primaryImage->print();
  } else {
    std::cout << "No primary image" << std::endl;
  }

  if (_secondaryImage) {
    std::cout << "\n\nWe have a secondary image! Calling print" << std::endl;
    _secondaryImage->print();
  } else {
    std::cout << "No secondary image " << std::endl;
  }
}

void Artist::setAlbums(Albums *albums) {
  _albums = albums;
}

std::string Artist::htmlString() {
  std::string html;

  if (_primaryImage) {
    html += _primaryImage->htmlString();
  } else if (_secondaryImage) {
    html += _secondaryImage->htmlString();
  }

  html += "<table class='artistInfo'>\n";
  html += "\t<tr>\n";
  html += "\t\t<td class='tagName'>Number of Images:</td>\n";
  html += "\t\t<td class='value'>" + numImages() + "</td>\n";
  html += "\t</tr>\n";
  html += "\t<tr>\n";
  html += "\t\t<td>Profile</td>\n";
  html += "\t\t<td class='value'>" + profile() + "</td>\n";
  html += "\t</tr>\n";
  html += "</table>\n";
  html += "<div class='clear'> \n \t &nbsp; \n </div>\n";
  html += "<ol>";
  html += _albums->htmlString();
  html += "</ol>";
  return html;
}

/*
2:34 pouring outside
*/
