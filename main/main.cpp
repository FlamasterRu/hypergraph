#include <iostream>
#include "hypergraph.h"
#include <iterator>















int main()
{
    std::cout << "Hello World!\n";

    hg::Hypergraphe p;

    auto v1 = p.addVertex();
    auto e1 =p.addEdge();

    std::cout << p << std::endl;

    auto v2 = hg::Vertex::createVertex(p);
    std::cout << p << std::endl;
    auto e2 = hg::Edge::createEdge(p);
    std::cout << p << std::endl;

    auto le = p.getEdgeList();
    auto lv = p.getVertexList();

    for (auto it = lv.begin(); it != lv.end(); ++it)
    {
        (*it).get();
    }

    p.linkVertexAndEdge(v1, e1);
    std::cout << p << std::endl;


    hg::ListVertex l1;
    l1.push_back(hg::Vertex::createVertex(p));
    l1.push_back(hg::Vertex::createVertex(p));

    std::cout << p << std::endl;

    p.linkEdgeToListVertex(e2, l1);
    std::cout << p << std::endl;



    std::cout << "Hello World!\n";
}
