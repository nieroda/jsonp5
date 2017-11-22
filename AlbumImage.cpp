#include "AlbumImage.hpp"

AlbumImage::AlbumImage() {}
AlbumImage::~AlbumImage() { std::cout << "Called Destructor" << std::endl; }

std::string AlbumImage::height() {
    if ( cachedheight )
        return _height;
    cachedheight = true;
    return _height = valueForStringAttribute("height");
}

std::string AlbumImage::type() {
    if ( cachedtype )
        return _type;
    cachedtype = true;
    return _type = valueForStringAttribute("type");
        
}

std::string AlbumImage::uri() {
    if ( cacheduri )
        return _uri;
    cacheduri = true;
    return _uri = valueForStringAttribute("uri");
}

int AlbumImage::width() {
    if ( cachedwidth )
        return _width;
    cachedwidth = true;
    return _width = valueForIntegerAttribute("width");
    
}

int AlbumImage::album_id() {
    if ( cachedalbumid )
        return _albumID;
    cachedalbumid = true;
    return _albumID = valueForIntegerAttribute("album_id");
}
