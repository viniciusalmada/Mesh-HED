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
        if (i == 0) {
            mSolid.setPrevOfHalfEdge(i, (int) mSolid.mVertices.size());
        } else {
            mSolid.setPrevOfHalfEdge(i, i - 1);
        }
        mSolid.setFaceOfHalfEdge(i, 0);
    }

    for (int i = 0; i < mSolid.mVertices.size(); i++) {
        mSolid.newHalfEdge(i);
        if (i == 0) {
            mSolid.setNextOfHalfEdge(i, i + 1);
            mSolid.setPrevOfHalfEdge(i, 2 * (int) mSolid.mVertices.size() - 1);
        } else if (i == (int) mSolid.mVertices.size() - 1) {
            mSolid.setNextOfHalfEdge(i, (int) mSolid.mVertices.size());
            mSolid.setPrevOfHalfEdge(i, i - 1);
        } else {
            mSolid.setNextOfHalfEdge(i, i + 1);
            mSolid.setPrevOfHalfEdge(i, i - 1);
        }
    }

    for (int i = 0; i < mSolid.mVertices.size(); i++) {
        int he1 = i;
        int he2 = i + (int) mSolid.mVertices.size();
        mSolid.newEdge(he1, he2);
    }

    mSolid.newFace(0);
}

std::map<int, double> Mesh::getInternalBoundary() {

    const int he = mSolid.getHeFromFace(0);
    int heCurr = he;
    do {

    } while (he != heCurr);


    return std::map<int, double>();
}
