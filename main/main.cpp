#include <iostream>
#include "hypergraph.h"
#include <iterator>















int main()
{
    std::cout << "Start.\n";

    hg::Hypergraphe p;


    // эквивалентная запись добавления
    std::shared_ptr< hg::Vertex > v0 = p.addVertex();
    auto v1 = hg::Vertex::createVertex(p);


    std::shared_ptr< hg::Edge > e0 = p.addEdge();

    std::cout << p << std::endl;
    p.linkVertexAndEdge(v0, e0);
    std::cout << p << std::endl;
    p.linkVertexAndEdge(v1, e0);
    std::cout << p << std::endl;


    hg::ListVertex lv;
    lv.push_back(p.addVertex());
    lv.push_back(p.addVertex());
    lv.push_back(p.addVertex());

    std::cout << p << std::endl;
    p.linkListVertex(lv);
    std::cout << p << std::endl;

    hg::ListEdge le;
    le.push_back(p.addEdge());
    le.push_back(p.addEdge());

    std::cout << p << std::endl;
    p.linkVertexToListEdge(v0, le);
    std::cout << p << std::endl;

    std::cout << v1->getId() << " " << p.getVertexId(v1) << std::endl;
    std::cout << e0->getId() << " " << p.getEdgeId(e0) << std::endl;
    std::cout << p.isVertexInEdge(v1, e0) << std::endl;

    p.linkVertexToListEdge(p.getVertexByIndex(p.getNumVertex() - 1), le);
    std::cout << p << std::endl;

    std::cout << "End.\n";
}






// Добавить конструктор гиперграфа из матрицы смежности
// Добавить mutex и noexept для работы с графом из нескольких потоков







