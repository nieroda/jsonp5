#include "Artist.hpp"
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>

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

std::string Artist::htmlString() {
    std::string additional;
    additional += "\t<li><p>" + artistName() + "</p>\n";
    additional += "\t\t<ul>\n";
    additional += "\t\t\t<li><p>ID: " + std::to_string(artistID()) + "</p></li>\n";
    additional += "\t\t\t<li><p>Number of Images: " + numImages() + "</p></li>\n";
    additional += "\t\t\t<li><p>Profile: " + profile() + "</p></li>\n";
    additional += "\t\t\t<li><p>Real Name: " + realName() + "</p></li>\n";
    additional += "\t\t</ul>\n";
    additional += "\t</li>\n";
    
    return additional;
}


