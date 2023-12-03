#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <stack>
#include <map>
#include <limits>
#include <cmath>

//Выделение константы  под определение бесконечности
double INF = INFINITY;

//Ребро
struct Edge 
{
	int weight;
	int indexTo;
};

//Вершины 
struct Node
{
	int id;
	std::vector<Edge> edges;

	int prevIndex;
	int weihgt;
	bool visited;

};

struct Graph
{
	std::vector<Node> nodes;


	//Очищаем весь граф 
	void clear()
	{
		nodes.clear();
	}

	//Очищаем список рёбер
	void clear_edges()
	{
		for (auto& node : nodes)
		{
			node.edges.clear();
		}
	}

	void init_start_parametrs()
	{
		for (auto& node : nodes)
		{
			node.weihgt = INF;
			node.visited = false;
			node.prevIndex = INF;
		}
	}
	
};

bool read_nodes(std::istream& istream, std::size_t nodes_count, Graph& graph_out)
{
	graph_out.nodes.clear();

	for (std::size_t i = 0; i < nodes_count; i++)
	{
		decltype(Node::id) id;
		istream >> id;
		graph_out.nodes.push_back({ id });
	}

	return true;
}


bool read_edges(std::istream& istream, std::size_t edges_count, Graph& graph_out)
{
	graph_out.clear_edges();

	for (std::size_t i = 0; i < edges_count; i++)
	{
		int start_id, end_id;
		int weight;

		istream >> start_id >> end_id;
		istream >> weight;

		auto& nodes_ref = graph_out.nodes;

		auto start_iter = std::find_if(nodes_ref.begin(), nodes_ref.end(), [start_id](const auto& node) { return node.id == start_id; });
		auto end_iter = std::find_if(nodes_ref.begin(), nodes_ref.end(), [end_id](const auto& node) { return node.id == end_id; });

		if (start_iter == nodes_ref.end() || end_iter == nodes_ref.end())
		{
			graph_out.clear_edges();

			return false;
		}
		std::size_t index = (end_iter - nodes_ref.begin());
		(*start_iter).edges.push_back(Edge{ weight, index });
	}

	return true;
}

Graph read_graph(const std::string& file_path)
{
	Graph graph;
	std::ifstream fin(file_path);
	if (fin)
	{
		std::size_t node_count;
		int edge_count;

		fin >> node_count >> edge_count;

		if (read_nodes(fin, node_count, graph))
		{
			read_edges(fin, edge_count, graph);
		}
	}
	return graph;
}

