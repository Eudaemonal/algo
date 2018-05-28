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


	std::vector<int> dijkstra(int start){
		std::vector<int> dist(n, INT_MAX);
		setds.insert(setds.begin(), std::make_pair(start, 0));
		dist[start] = 0;
		while(!setds.empty()){
			std::sort(setds.begin(), setds.end(), [](auto &a, auto &b){
				return a.second < b.second;
			});

			std::pair<int, int> tmp = *(setds.begin());
			setds.erase(setds.begin());
			std::cout <<"erase("<< tmp.first << " "<< tmp.second << ")\n";

			int u = tmp.first;
			for(int i=0; i < connections.size(); ++i){
				if(connections[i].src==u){
					int v = connections[i].dst;
					int w = connections[i].weight;
					if(dist[v] > dist[u] + w){
						dist[v] = dist[u] + w;
						setds.insert(setds.begin(), std::make_pair(v, dist[v] ));
						std::cout <<"insert("<< v << " "<< dist[v] << ")\n";
					}
				}else if(connections[i].dst==u){
					int v = connections[i].src;
					int w = connections[i].weight;
					if(dist[v] > dist[u] + w){
						dist[v] = dist[u] + w;
						setds.insert(setds.begin(), std::make_pair(v, dist[v]));
						std::cout <<"insert("<< v << " "<< dist[v] << ")\n";

					}
				}

			}
		}
		return dist;
	}


	
private:
	std::vector<Edge> connections;
	std::vector<std::pair<int, int>> setds;
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
	std::vector<int> distances= g.dijkstra(0);
	std::cout << "Shotest path is:\n";
	for(int i = 0; i < distances.size(); ++i){
		std::cout <<"Node: " << i << " Distance: " << distances[i] << "\n";
	}

	return 0;
}

