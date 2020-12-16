//
// Created by vinic on 15/12/2020.
//

#ifndef TESTEHED_HED_H
#define TESTEHED_HED_H

#include <vector>

namespace Topo {
    class Vertex {
    public:
        double x = 0.0;
        double y = 0.0;
        int he = -1;
    };

    class HalfEdge {
    public:
        int vtx = -1;
        int edge = -1;
        int face = -1;
        int next = -1;
        int prev = -1;
    };

    class Edge {
    public:
        int he1 = -1;
        int he2 = -1;
    };

    class Face {
    public:
        int he = -1;
    };

    class Solid {
    public:
        std::vector<Vertex> mVertices;
        std::vector<HalfEdge> mHalfEdge;
        std::vector<Edge> mEdge;
        std::vector<Face> mFace;

        int newVertex(double x, double y) {
            Vertex vtx{};
            vtx.x = x;
            vtx.y = y;
            mVertices.push_back(vtx);
            return (int) mVertices.size() - 1;
        }

        int newHalfEdge(int vtx) {
            HalfEdge he{};
            he.vtx = vtx;
            mHalfEdge.push_back(he);
            return (int) mHalfEdge.size() - 1;
        }

        int newEdge(int he1, int he2) {
            Edge edge{};
            edge.he1 = he1;
            edge.he2 = he2;
            mEdge.push_back(edge);

            mHalfEdge[he1].edge = (int) mEdge.size() - 1;
            mHalfEdge[he2].edge = (int) mEdge.size() - 1;

            return (int) mEdge.size() - 1;
        }

        int newFace(int he) {
            Face face{};
            face.he = he;
            mFace.push_back(face);

            mHalfEdge[he].face = (int) mFace.size() - 1;

            return (int) mFace.size() - 1;
        }

        void setNextOfHalfEdge(int he, int next) {
            mHalfEdge[he].next = next;
        }

        void setPrevOfHalfEdge(int he, int prev) {
            mHalfEdge[he].prev = prev;
        }

        void setFaceOfHalfEdge(int he, int face) {
            mHalfEdge[he].face = face;
        }

        int getHeFromFace(int face) {
            return mFace[face].he;
        }
    };

}

#endif //TESTEHED_HED_H
