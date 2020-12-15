//
// Created by vinic on 15/12/2020.
//

#include "Mesh.h"

Mesh::Mesh(std::vector<Point>& pts) : mPoints(pts) {

    for (auto& pt : mPoints) {
        mSolid.newVertex(pt.x, pt.y);
    }

    for (int i = 0; i < mSolid.mVertices.size(); i++) {
        mSolid.newHalfEdge(i);
        mSolid.setNextOfHalfEdge(i, (i + 1) % (int) mSolid.mVertices.size());
        mSolid.setFaceOfHalfEdge(i, 0);
    }

    for (int i = 0; i < mSolid.mVertices.size(); i++) {
        mSolid.newHalfEdge(i);
    }

    for (int i = 0; i < mSolid.mVertices.size(); i++) {
        int he1 = i;
        int he2 = i + (int) mSolid.mVertices.size();
        mSolid.newEdge(he1, he2);
    }

    mSolid.newFace(0);
}
