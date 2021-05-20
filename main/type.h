#pragma once
#include <list>
#include <map>
#include <boost/multi_array.hpp>
#include <memory>
#include <vector>
#include <string>


namespace hg
{

	class Hypergraphe;
	class Vertex;
	class Edge;


	typedef boost::multi_array< int, 2 >
		AdjacencyMatrix;

	typedef AdjacencyMatrix::index index;

	typedef std::list< std::shared_ptr<Vertex> >
		ListVertex;

	typedef std::list< std::shared_ptr<Edge> >
		ListEdge;

	typedef std::map< unsigned int, std::shared_ptr<Vertex> >
		VertexByIndex;

	typedef std::map< unsigned int, std::shared_ptr<Edge> >
		EdgeByIndex;

}	// namespace hypgr