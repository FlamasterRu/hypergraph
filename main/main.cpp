#include <iostream>
#include "hypergraph.h"
#include <locale>
#include <queue>
#include <stack>

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Start.\n";

    hg::Hypergraphe p;
    // Ввод гиперграфа
    hg::ListVertex lv;
    lv.push_back(p.addVertex());
    lv.push_back(p.addVertex());
    lv.push_back(p.addVertex());
    p.linkListVertex(lv);

    lv.pop_front();
    lv.pop_front();
    lv.push_back(p.addVertex());
    lv.push_back(p.addVertex());

    auto e2 = p.addEdge();
    p.linkVertexAndEdge(p.getVertexByIndex(1), e2);
    p.linkVertexAndEdge(p.addVertex(), e2);

    p.linkListVertex(lv);

    p.addVertex();
    p.addVertex();

    auto e4 = p.addEdge();
    p.linkVertexAndEdge(p.getVertexByIndex(4), e4);
    p.linkVertexAndEdge(p.getVertexByIndex(6), e4);

    lv.clear();
    for (int i = 4; i < p.getNumVertex(); ++i)
    {
        lv.push_back(p.getVertexByIndex(i));
    }
    p.linkListVertex(lv);
    ///

    std::cout << "Все индексы вершин: ";
    hg::ListVertex listVertex = p.getVertexList();
    for (auto vertex : listVertex)
    {
        std::cout << vertex->getId() << " ";
    }
    std::cout << std::endl;

    // Обход в ширину начиная с нулевой вершины
    std::queue<int> que;
    que.push(0);
    p.getVertexByIndex(0)->setDataString("passed");
    std::cout << "Обход в ширину: ";
    while (que.size() != 0)
    {
        int currentVertex = que.front();
        que.pop();
        std::cout << currentVertex << " ";

        hg::ListEdge listEdge = p.getVertexByIndex(currentVertex)->getListEdge();
        for (auto edge : listEdge)
        {
            hg::ListVertex l = edge->getListVertex();
            for (auto vertex : l)
            {
                if (vertex->getDateString() != "passed")
                {
                    que.push(vertex->getId());
                    vertex->setDataString("passed");
                }
            }
        }
    }
    std::cout << std::endl;

    // стираем отметки о прохождении
    for (auto vertex : listVertex)
    {
        vertex->setDataString("");
    }

    // Обход в глубину начиная с нулевой вершины
    std::stack<int> st;
    st.push(0);
    p.getVertexByIndex(0)->setDataString("passed");
    std::cout << "Обход в глубину: ";
    while (st.size() != 0)
    {
        int currentVertex = st.top();
        st.pop();
        std::cout << currentVertex << " ";

        hg::ListEdge listEdge = p.getVertexByIndex(currentVertex)->getListEdge();
        for (auto edge : listEdge)
        {
            hg::ListVertex l = edge->getListVertex();
            for (auto vertex : l)
            {
                if (vertex->getDateString() != "passed")
                {
                    st.push(vertex->getId());
                    vertex->setDataString("passed");
                }
            }
        }
    }
    std::cout << std::endl;

    std::cout << "End.\n";
}