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






















}	// namespace hypgr

