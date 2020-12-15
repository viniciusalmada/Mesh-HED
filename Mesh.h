//
// Created by vinic on 15/12/2020.
//

#ifndef TESTEHED_MESH_H
#define TESTEHED_MESH_H


#include <vector>
#include "hed.h"
#include "Point.h"


class Mesh {
    std::vector<Point> mPoints;

    Topo::Solid mSolid{};

public:
    explicit Mesh(std::vector<Point>& pts);

};


#endif //TESTEHED_MESH_H
