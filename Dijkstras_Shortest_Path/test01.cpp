#include <iostream>
#include <vector>
#include <algorithm>

struct Edge{
	int src;
	int dst;
	int weight;
};



class Graph{
public:
	Graph(int _n)
		:n(_n)
	{}

	void add(int src, int dst, int weight){
		Edge e;
		e.src = src;
		e.dst = dst;
		e.weight = weight;
		connections.push_back(e);
	}

	std::vector<Edge> dijkstra(int start){
		for(int i=0; i < connections.size(); ++i){
			
		}


	}

	
private:
	std::vector<Edge> connections;
	int n;
};


int main(int argc, char *argv[]){
	int n, nodes;
	std::cin >> n >> nodes;
	Graph g(nodes);
	for(int i = 0; i < n; ++i){
		int src, dst, weight;
		std::cin >> weight >> src >> dst;
		g.add(src, dst, weight);
	}
	std::vector<Edge> mst= g.kruskalMST();
	std::cout << "MST is:\n";
	for(int i = 0; i < mst.size(); ++i){
		std::cout << mst[i].weight<< " "<<  mst[i].src<<" " <<mst[i].dst << "\n";
	}

	return 0;
}

