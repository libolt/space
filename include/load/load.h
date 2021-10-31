#ifndef _LOAD_H_
#define _LOAD_H_

#include "pugixml.hpp"

class loadXML
{
public:
    void loadDocument(void);
private:
    pugi::xml_document xmlDoc;
};

#endif // _LOAD_H_
