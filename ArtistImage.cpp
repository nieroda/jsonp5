#include "ArtistImage.hpp"

#define o std::cout
#define e std::endl;

ArtistImage::ArtistImage() {}
ArtistImage::~ArtistImage() {}

int ArtistImage::height() {
    if ( cachedheight )
        return _height;
    cachedheight = true;
    return _height = valueForIntegerAttribute("height");
}

int ArtistImage::artistID() {
    if ( cachedartist_id )
        return _artist_id;
    cachedartist_id = true;
    return _artist_id = valueForIntegerAttribute("artist_id");
}

int ArtistImage::width() {
    if ( cachedwidth )
        return _width;
    cachedwidth = true;
    return _width = valueForIntegerAttribute("width");
}

std::string ArtistImage::uri() {
    if ( cached_uri )
        return _uri;
    cached_uri = true;
    return _uri = valueForStringAttribute("uri");
}

std::string ArtistImage::type() {
    if ( cachedtype )
        return _type;
    cachedtype = true;
    return _type = valueForStringAttribute("type");
}

void ArtistImage::print() {
  o << "Called print in artist image" << e;
  o << "Height: " << height() << e;
  o << "Artist ID " << artistID() << e;
  o << "Width: " << width() << e;
  o << "URI: " << uri() << e;
  o << "Type: " << type() << e;
}

std::string ArtistImage::htmlString() {
  std::string html;
  html += "<img class='image' height='" + std::to_string(height()) + "' ";
  html += "src='" + uri() + "' ";
  html += "width='" + std::to_string(width()) + "'>";
  return html;
}
