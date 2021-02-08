#include "vertex.h"



namespace hg
{

	Vertex::Vertex(const unsigned int id) :
		v_Id(id)
	{
	}




	const std::shared_ptr<Vertex> Vertex::createVertex(Hypergraphe& gr)
	{
		return gr.addVertex();
	}



	const hg::ListEdge& Vertex::getListEdge() const
	{
		return v_ListEdge;
	}





}	// namespace hypgr

