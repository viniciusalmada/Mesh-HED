//
// Created by vinic on 15/12/2020.
//

#ifndef TESTEHED_MESH_H
#define TESTEHED_MESH_H


#include <vector>
#include <map>
#include "hed.h"
#include "Point.h"


class Mesh {
    std::vector<Point> mPoints;

    Topo::Solid mSolid{};

    int vertexPivot = -1;

    std::map<int, double> getInternalBoundary();

public:

    explicit Mesh(std::vector<Point>& pts);

};


#endif //TESTEHED_MESH_H
