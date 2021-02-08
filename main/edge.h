#pragma once
#include "type.h"
#include "hypergraph.h"


namespace hg
{



	class Edge
	{
		friend class Hypergraphe;

	protected:

		///////
		unsigned int e_Id;

		int e_Weight = 1;

		std::string e_Str = "";

		ListVertex e_ListVertex;
		///////


	public:

		static const std::shared_ptr<Edge> createEdge(Hypergraphe& gr);

		const hg::ListVertex& getListVertex() const;

		Edge(const Edge& e) = delete;

		Edge(const Edge&& e) = delete;


	private:

		Edge(const unsigned int id);

	};



}	// namespace hypgr













