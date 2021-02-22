#include <iostream>
#include "hypergraph.h"

int main()
{
    std::cout << "Start.\n";

    hg::Hypergraphe p;

    // Эквивалентная запись добавления вершины
    std::shared_ptr< hg::Vertex > v0 = p.addVertex();
    auto v1 = hg::Vertex::createVertex(p);

    std::shared_ptr< hg::Edge > e0 = p.addEdge();   // Добавляем ребро

    std::cout << p << std::endl;
    p.linkVertexAndEdge(v0, e0);    //Связываем вершину v0 и ребро e0
    std::cout << p << std::endl;
    p.linkVertexAndEdge(v1, e0);    //Связываем вершину v1 и ребро e0, таким образом v1 и v0 связаны ребром e0
    std::cout << p << std::endl;

    hg::ListVertex lv;
    lv.push_back(p.addVertex());
    lv.push_back(p.addVertex());
    lv.push_back(p.addVertex());

    std::cout << p << std::endl;
    p.linkListVertex(lv);   // Связываем список вершин, метод вернёт ребро, которое при выполнении будет создано
    std::cout << p << std::endl;

    hg::ListEdge le;
    le.push_back(p.addEdge());
    le.push_back(p.addEdge());

    std::cout << p << std::endl;
    p.linkVertexToListEdge(v0, le); // Связываем списо рёбер с вершиной
    std::cout << p << std::endl;

    std::cout << v1->getId() << " " << p.getVertexId(v1) << std::endl;  // Два способа получения id вершины, v1->getId() работает быстрее
    std::cout << e0->getId() << " " << p.getEdgeId(e0) << std::endl;
    std::cout << p.isVertexInEdge(v1, e0) << std::endl;     // Проверка инцидентности  v1 и e0

    p.linkVertexToListEdge(p.getVertexByIndex(p.getNumVertex() - 1), le);
    std::cout << p << std::endl;

    std::cout << "End.\n";
}