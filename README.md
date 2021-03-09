# hypergraph
Данный проект представляет собой библиотеку для представления и обработки гиперграфов.

Гиперграф неориентированный.
Гиперграф хранится в классе Hypergraphe. Он состоит из следующих полей:
матрица смежности, список вершин, список рёбер, красно-чёрное дерево из пар индекс-вершина,
красно-чёрное дерево из пар индекс-ребро, количество вершин, количество рёбер.

Данные хранятся в избыточном количестве, то есть один и тот же объект лежит как в списке, так и в дереве, 
это позволяет увеличить скорость доступа и поиска вершины или ребра.

Основная функциональность:
Прежде всего нужно создать гиперграф: hg::Hypergraphe p; или auto p = new hg::Hypergraphe(); в зависимости от предполагаемого размера графа.
Для добавления вершин/рёбер используются методы: addVertex(), addEdge().
Вершину и ребро можно связать напрямую: linkVertexAndEdge(vertex, edge),
Или связать список вершин, при этом будет создано новое ребро: linkListVertex(listVertex), такой же метод есть для списка рёбер.
Можно связать список вершин с существующим ребром: linkEdgeToListVertex(edge, listVertex), такой же метод есть для списка рёбер.
Получить ребро/вершину можно по индексу: getVertexByIndex(int), getEdgeByIndex(int).
Можно получить список всех вершин/рёбер: getVertexList(), getEdgeList().
Метод getAdjacencyMatrix() возвращает матрицу смежности.
Чтобы проверить инцидентность вершины и ребра нужно использовать: isVertexInEdge(vertex, edge).
Дополнительно рёбрам и вершинам можно присвоить вес: vertex.setWeight(int), edge.setWeight(int),
или строку: vertex.setDataString(string), edge.setDataString(string).
Для удобства отладки и изучения библиотеки был перегружен оператор вывода в поток матрицы смежности std::ostream& operator<< (std::ostream& out, Hypergraphe& h);.

Каждая вершина/ребро обёрнуты в std::shared_ptr для удобства передачи в функции, не задумываясь о копиях.

Пример программы:

    std::cout << "Start.\n";

    hg::Hypergraphe p;

    // эквивалентная запись добавления вершины
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

