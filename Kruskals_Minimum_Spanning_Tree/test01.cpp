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
	Graph()=default;

	void add(int src, int dst, int weight){
		Edge e;
		e.src = src;
		e.dst = dst;
		e.weight = weight;
		map.push_back(e);
	}

	void kruskalMST(){
		int m = 0;
		std::sort(map.begin(), map.end(), [](Edge &a, Edge &b){
			return a.weight < b.weight;
		});
		
		for(int i = 0; i < map.size(); ++i){
			if(map[i].group==-1){
				map[i].group=;
				
			}
		}


		for(int i = 0; i < map.size(); ++i){
			std::cout << map[i].weight<< "\n";
		}
	}

	
private:
	std::vector<Edge> map;
};


int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	Graph g;
	for(int i = 0; i < n; ++i){
		int src, dst, weight;
		std::cin >> weight >> src >> dst;
		g.add(src, dst, weight);
	}
	g.kruskalMST();
	return 0;
}
