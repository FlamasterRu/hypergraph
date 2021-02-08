#pragma once
#include "type.h"
#include "edge.h"
#include "vertex.h"


namespace hg
{





	class Hypergraphe
	{

	protected:

		AdjacencyMatrix h_AdjacencyMatrixInt;

		ListVertex h_ListVertex;

		ListEdge h_ListEdge;

		VertexByIndex h_VertexIndex;

		EdgeByIndex h_EdgeIndex;

		bool h_IsAdjacencyMatrixActual = false;

		unsigned int h_VertexId = 0;

		unsigned int h_EdgeId = 0;


	public:

		Hypergraphe();

		const std::shared_ptr<Vertex> addVertex();

		const std::shared_ptr<Edge> addEdge();

		const AdjacencyMatrix& getAdjacencyMatrix();

		bool linkVertexAndEdge(const std::shared_ptr<Vertex> v, const std::shared_ptr<Edge> e);

		bool linkVertexToListEdge(const std::shared_ptr<Vertex> v, const hg::ListEdge& e);

		bool linkEdgeToListVertex(const std::shared_ptr<Edge> e, const hg::ListVertex& v);

		bool linkListVertex(const hg::ListVertex& v);

		bool linkListEdge(const hg::ListEdge& e);

		const ListEdge& getEdgeList() const;

		const ListVertex& getVertexList() const;

		unsigned int getNumVertex() const;

		unsigned int getNumEdge() const;

		const std::shared_ptr<Vertex> getVertexByIndex(const unsigned int index);

		const std::shared_ptr<Edge> getEdgeByIndex(const unsigned int index);

		friend std::ostream& operator<< (std::ostream& out, const Hypergraphe& h);

		~Hypergraphe();



	};



















}	// namespace hypgr





















