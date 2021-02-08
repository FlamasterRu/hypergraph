#include "hypergraph.h"

namespace hg
{


	//////////////////// constructor and destructor
	Hypergraphe::Hypergraphe()
	{
		h_AdjacencyMatrixInt.resize(boost::extents[0][0]);
	}


	Hypergraphe::~Hypergraphe()
	{

	}
	///////////////////////////////////////////////////////






	////////////////////	add 
	const std::shared_ptr<Vertex> Hypergraphe::addVertex()
	{
		h_IsAdjacencyMatrixActual = false;

		std::shared_ptr<Vertex> temp(new Vertex(h_NumOfVertex));

		h_ListVertex.push_back(temp);
		h_Index_Vertex.insert(std::pair< unsigned int, std::shared_ptr<Vertex> >(h_NumOfVertex, temp));

		++h_NumOfVertex;
		return temp;
	}


	const std::shared_ptr<Edge> Hypergraphe::addEdge()
	{
		h_IsAdjacencyMatrixActual = false;

		std::shared_ptr<Edge> temp(new Edge(h_NumOfEdge));

		h_ListEdge.push_back(temp);
		h_Index_Edge.insert(std::pair< unsigned int, std::shared_ptr<Edge> >(h_NumOfEdge, temp));

		++h_NumOfEdge;
		return temp;
	}
	///////////////////////////////////////////////////////






	////////////////////	get
	const std::shared_ptr<Vertex> Hypergraphe::getVertexByIndex(const unsigned int index) const
	{
		return (*h_Index_Vertex.find(index)).second;
	}


	const std::shared_ptr<Edge> Hypergraphe::getEdgeByIndex(const unsigned int index) const
	{
		return (*h_Index_Edge.find(index)).second;
	}


	const ListVertex& Hypergraphe::getVertexList() const
	{
		return const_cast<const ListVertex&>(h_ListVertex);
	}


	const ListEdge& Hypergraphe::getEdgeList() const
	{
		return const_cast<const ListEdge&>(h_ListEdge);
	}


	unsigned int Hypergraphe::getNumEdge() const
	{
		return h_ListEdge.size();
	}


	unsigned int Hypergraphe::getNumVertex() const
	{
		return h_ListVertex.size();
	}


	const AdjacencyMatrix& Hypergraphe::getAdjacencyMatrix()
	{
		if (h_IsAdjacencyMatrixActual)
		{
			return h_AdjacencyMatrixInt;
		}
		else
		{
			h_AdjacencyMatrixInt.resize(boost::extents[0][0]);
			h_AdjacencyMatrixInt.resize(boost::extents[h_NumOfVertex][h_NumOfEdge]);
			for (auto it1 = h_ListVertex.begin(); it1 != h_ListVertex.end(); ++it1)
			{
				for (auto it2 = (*it1).get()->getListEdge().begin(); it2 != (*it1).get()->getListEdge().end(); ++it2)
				{
					h_AdjacencyMatrixInt[(*it1).get()->v_Id][(*it2).get()->e_Id] = 1;
				}
			}
			h_IsAdjacencyMatrixActual = true;
		}
	}
	///////////////////////////////////////////////////////






	////////////////////	link vertex and edge
	bool Hypergraphe::linkVertexAndEdge(const std::shared_ptr<Vertex> v, const std::shared_ptr<Edge> e)
	{
		h_IsAdjacencyMatrixActual = false;

		v.get()->v_ListEdge.push_back(e);
		e.get()->e_ListVertex.push_back(v);

		return true;
	}


	bool Hypergraphe::linkVertexToListEdge(const std::shared_ptr<Vertex> v, const hg::ListEdge& e)
	{
		h_IsAdjacencyMatrixActual = false;

		for (auto it = e.begin(); it != e.end(); ++it)
		{
			v.get()->v_ListEdge.push_back(*it);
			(*it).get()->e_ListVertex.push_back(v);
		}

		return true;
	}


	bool Hypergraphe::linkEdgeToListVertex(const std::shared_ptr<Edge> e, const hg::ListVertex& v)
	{
		h_IsAdjacencyMatrixActual = false;

		for (auto it = v.begin(); it != v.end(); ++it)
		{
			e.get()->e_ListVertex.push_back(*it);
			(*it).get()->v_ListEdge.push_back(e);
		}

		return true;
	}


	bool Hypergraphe::linkListVertex(const hg::ListVertex& v)
	{
		h_IsAdjacencyMatrixActual = false;

		auto temp = this->addEdge();
		this->linkEdgeToListVertex(temp, v);

		return true;
	}


	bool Hypergraphe::linkListEdge(const hg::ListEdge& e)
	{
		h_IsAdjacencyMatrixActual = false;

		auto temp = this->addVertex();
		this->linkVertexToListEdge(temp, e);

		return true;
	}
	///////////////////////////////////////////////////////








	std::ostream& operator<< (std::ostream& out, Hypergraphe& h)
	{
		h.getAdjacencyMatrix();
		for (int i = 0; i < h.h_NumOfVertex; ++i)
		{
			for (int j = 0; j < h.h_NumOfEdge; ++j)
			{
				out.width(4);
				if (j == h.h_NumOfEdge - 1)
				{
					out << h.h_AdjacencyMatrixInt[i][j];
				}
				else
				{
					out << h.h_AdjacencyMatrixInt[i][j] << " ";
				}
			}
			out << "\n";
		}
		return out;
	}











}	// namespace hypgr



























































