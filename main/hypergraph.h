#pragma once
#include "type.h"
#include "edge.h"
#include "vertex.h"


namespace hg
{





	class Hypergraphe
	{

	protected:

		///////
		AdjacencyMatrix h_AdjacencyMatrixInt;	// ������� ��������� boost::multi_array< int, 2 >

		ListVertex h_ListVertex;

		ListEdge h_ListEdge;

		VertexByIndex h_Index_Vertex;			// std::map< unsigned int, std::shared_ptr<Vertex> >

		EdgeByIndex h_Index_Edge;				// std::map< unsigned int, std::shared_ptr<Edge> >

		bool h_IsAdjacencyMatrixActual = false;

		unsigned int h_NumOfVertex = 0;	// ��������� ������ � 0

		unsigned int h_NumOfEdge = 0;		// ��������� ����� � 0
		///////


	public:

		/////// constructor and destructor
		Hypergraphe();

		~Hypergraphe();
		////////////////////////



		///////		add 
		const std::shared_ptr<Vertex> addVertex();

		const std::shared_ptr<Edge> addEdge();
		////////////////////////



		///////		get
		const AdjacencyMatrix& getAdjacencyMatrix();

		const ListEdge& getEdgeList() const;
		const ListVertex& getVertexList() const;

		unsigned int getNumVertex() const;
		unsigned int getNumEdge() const;

		unsigned int getVertexId(const std::shared_ptr<Vertex>& v) const;
		unsigned int getEdgeId(const std::shared_ptr<Edge>& e) const;

		const std::shared_ptr<Vertex> getVertexByIndex(const unsigned int index) const;
		const std::shared_ptr<Edge> getEdgeByIndex(const unsigned int index) const;
		////////////////////////



		///////		link vertex and edge
		bool linkVertexAndEdge(const std::shared_ptr<Vertex>& v, const std::shared_ptr<Edge>& e);

		bool linkVertexToListEdge(const std::shared_ptr<Vertex>& v, const hg::ListEdge& e);

		bool linkEdgeToListVertex(const std::shared_ptr<Edge>& e, const hg::ListVertex& v);

		bool linkListVertex(const hg::ListVertex& v);

		bool linkListEdge(const hg::ListEdge& e);
		////////////////////////





		///////		
		friend std::ostream& operator<< (std::ostream& out, Hypergraphe& h);

		bool isVertexInEdge(const std::shared_ptr<Vertex> v, const std::shared_ptr<Edge> e) const;
		////////////////////////


	};



















}	// namespace hypgr





















