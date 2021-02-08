#pragma once
#include "type.h"
#include "hypergraph.h"


namespace hg
{











	class Vertex
	{
		friend class Hypergraphe;

	protected:
		
		unsigned int v_Id;

		int v_Weight = 1;

		std::string v_Str = "";

		ListEdge v_ListEdge;


	public:

		static const std::shared_ptr<Vertex> createVertex(Hypergraphe& gr);

		const hg::ListEdge& getListEdge();

		Vertex(const Vertex& v) = delete;

		Vertex(const Vertex&& v) = delete;



	private:
		
		Vertex(const unsigned int id);

	};



























}	// namespace hypgr

