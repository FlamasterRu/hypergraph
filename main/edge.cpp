#include "edge.h"



namespace hg
{

	Edge::Edge(const unsigned int id) :
		e_Id(id)
	{
	}


	const std::shared_ptr<Edge> Edge::createEdge(Hypergraphe& gr)
	{
		return gr.addEdge();
	}


	const hg::ListVertex& Edge::getListVertex() const
	{
		return e_ListVertex;
	}


	unsigned int Edge::getId() const
	{
		return e_Id;
	}


}	// namespace hypgr

