/*
 * =====================================================================================
 *
 *       Filename:  load.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/2020 12:10:43 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include "load/load.h"

void loadXML::loadDocument()
{
    pugi::xml_parse_result result = xmlDoc.load_file("data/arthurkl.xml");

    std::cout << "Load result: " << result.description() << ", mesh name: " << xmlDoc.child("mesh").attribute("name").value() << std::endl;
}
