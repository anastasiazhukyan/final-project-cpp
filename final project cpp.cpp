#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <stack>
#include <map>


//Выделение константы  под определение бесконечности
const int INF = std::numeric_limits<int>::max;

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
		}
	}
	
};