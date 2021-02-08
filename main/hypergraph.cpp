#include "hypergraph.h"

namespace hg
{

	Hypergraphe::Hypergraphe()
	{
		h_AdjacencyMatrixInt.resize(boost::extents[0][0]);
	}



	Hypergraphe::~Hypergraphe()
	{

	}




	const std::shared_ptr<Vertex> Hypergraphe::addVertex()
	{
		h_IsAdjacencyMatrixActual = false;

		std::shared_ptr<Vertex> temp(new Vertex(h_VertexId));

		h_ListVertex.push_back(temp);
		h_VertexIndex.insert(std::pair< unsigned int, std::shared_ptr<Vertex> >(h_VertexId, temp));

		++h_VertexId;
		return temp;
	}



	const std::shared_ptr<Edge> Hypergraphe::addEdge()
	{
		h_IsAdjacencyMatrixActual = false;

		std::shared_ptr<Edge> temp(new Edge(h_EdgeId));

		h_ListEdge.push_back(temp);
		h_EdgeIndex.insert(std::pair< unsigned int, std::shared_ptr<Edge> >(h_EdgeId, temp));

		++h_EdgeId;
		return temp;
	}




	const std::shared_ptr<Vertex> Hypergraphe::getVertexByIndex(const unsigned int index)
	{
		return (*h_VertexIndex.find(index)).second;
	}


	const std::shared_ptr<Edge> Hypergraphe::getEdgeByIndex(const unsigned int index)
	{
		return (*h_EdgeIndex.find(index)).second;
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


	const AdjacencyMatrix& Hypergraphe::getAdjacencyMatrix()
	{
		if (h_IsAdjacencyMatrixActual)
		{
			return h_AdjacencyMatrixInt;
		}
		else
		{
			h_AdjacencyMatrixInt.resize(boost::extents[0][0]);
			h_AdjacencyMatrixInt.resize(boost::extents[h_VertexId][h_EdgeId]);
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



	std::ostream& operator<< (std::ostream& out, const Hypergraphe& h)
	{
		const_cast<Hypergraphe&>(h).getAdjacencyMatrix();
		for (int i = 0; i < h.h_VertexId; ++i)
		{
			for (int j = 0; j < h.h_EdgeId; ++j)
			{
				out.width(4);
				if (j == h.h_EdgeId - 1)
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


	bool Hypergraphe::linkListVertex(const hg::ListVertex& v)
	{
		auto temp = this->addEdge();
		this->linkEdgeToListVertex(temp, v);
		return true;
	}



	bool Hypergraphe::linkListEdge(const hg::ListEdge& e)
	{
		auto temp = this->addVertex();
		this->linkVertexToListEdge(temp, e);
		return true;
	}



















}	// namespace hypgr



























































