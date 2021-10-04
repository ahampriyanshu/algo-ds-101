#include <iostream>
#include <ctime>
#include <chrono>
#include <cmath>

#include "leftistHeap.h"
#include "WDGraph.h"

const float INF = 10e6;
WDGraph g;
std::vector<VertexNode*> vertices;
std::vector<EdgeNode*> EdgesToNeightbours;
LeftistHeap h;

void readGraph(WDGraph &g);
void createGraph(int N_VERTICES, int MAX_WEIGHT, float EDGE_CHANCE, long unsigned int &edges);
void dijkstra(WDGraph g, int src);

int main(int argc, char **argv) {
    srand(time(NULL));
	long unsigned int edges = 0;
    if (argc != 4){
        std::cerr << "Wrong # of arguments\n";
        std::cerr << "Correct arguments are: (int) N_VERTICES, (int) MAX_WEIGHT, (float) EDGE_CHANCE\n";
        return 1;
    }
    std::cerr << "Generating a graph with: " << '\n';
    std::cerr << "     " << argv[1] << " N_VERTICES\n";
    std::cerr << "     " << argv[2] << " MAX_WEIGHT\n";
    std::cerr << "     " << std::stod(argv[3])*100 << "% EDGE_CHANCE\n";
	std::cerr << "-------------------------\n";
	std::cerr << std::pow(std::stoi(argv[1]), 2)*std::stod(argv[3]) << " expected edges (aprox)\n";
	// readGraph(g);		// Descomentar para leer el grafo (./dijkstra < inputFile)
    createGraph(std::stoi(argv[1]), std::stoi(argv[2]), std::stod(argv[3]), edges);	// Comentar si se desea leer el grafo en lugar de generarlo
	// g.printGraph();		// Descomentar para imprimir las listas de adyacencia del grafo generado o leido
	std::cerr << "Executing dijkstra...\n";
	auto start = std::chrono::steady_clock::now();
	dijkstra(g, 0);
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration<double, std::milli>(end - start).count()	<< "\n";
	std::cerr << std::chrono::duration<double, std::milli>(end - start).count()	<< " ms - Total time\n";
	std::cerr << edges/std::chrono::duration<double, std::milli>(end - start).count() << " edges/ms\n";
	// g.printGraphvertices();	// Descomentar para imprimir los datos de todos los vertices tras la ejecucion del algoritmo
	return 0;
}

void dijkstra(WDGraph g, int src) {
	std::pair<float, int> minElem;
	VertexNode *minElemVertex;
	vertices.clear();
	g.getvertices(vertices);
	// Modificamos la distancia del nodo de inicio a 0
	g.changeVertexDistance(src, 0);
	// Insertamos todos los vertices en el monticulo, tienen distancia INF, no estan visitados y no tienen nodo previo
	for (int i = 0; i < g._nVertex; i++)
		h.insert(std::make_pair(vertices[i]->_dist, vertices[i]->_elem));
	// Mientras el monticulo no este vacio, operamos de la siguiente manera
	while (!h.isEmpty()) {
		// Extraemos el minimo elemento y conseguimos acceso a su nodo mediante el la funcion getVertex(), tambien eliminamos dicho elemento del monticulo ya que ya ha sido visitado
		h.deleteMin(minElem);
		minElemVertex = g.getVertex(minElem.second);
		// Si el nodo visitado tiene una distancia distinta a INF, implica que ha sido visitado por el algoritmo
		if (minElemVertex->_dist != INF)
			g.visitVertex(minElem.second);
		EdgesToNeightbours.clear();
		// Extraemos la lista de adyacencia del vertice a tratar en esta iteraccion
		g.getNeightbours(minElemVertex->_elem, EdgesToNeightbours);
		for (long unsigned int i = 0; i < EdgesToNeightbours.size(); i++) {
			// Para cada vecino al vertice a tratar comprobamos que no haya sido visitado (y eliminado del monticulo) y si la distancia desde le nodo actual mejora la distancia obtenida por el camino anterior
			if (!(g.getVertex(EdgesToNeightbours[i]->_dst)->_visited) 
				&& (minElemVertex->_dist + EdgesToNeightbours[i]->_weight < g.getVertex(EdgesToNeightbours[i]->_dst)->_dist)) {
				// Modificamos la distancia de llegada al vecino a traves de su padre
				g.changeVertexDistance(EdgesToNeightbours[i]->_dst, minElemVertex->_dist + EdgesToNeightbours[i]->_weight);
				// Indicamos al vecino que el vertice actual es su padre en el camino minimo
				g.getVertex(EdgesToNeightbours[i]->_dst)->_parentOnMinPath = minElemVertex;
				// Decrecemos la  clave de dicho vecino a su nuevo valor en el monticulo
				// Cabe destacar que esta funcion es un tanto extrana, ya que recibe el ELEMENTO del vertice para modificar su DISTANCIA, esta funcionalidad ha sido implementada
				// 		en la funcion decrecerClave() en el archivo leftistHeap.cpp. Dicho monticulo contiene un mapa que relaciona elemento - puntero al nodo correspondiente. 
				h.decreaseKey(g.getVertex(EdgesToNeightbours[i]->_dst)->_elem, g.getVertex(EdgesToNeightbours[i]->_dst)->_dist);
			}
		}
	}
}

void readGraph(WDGraph &g) {
	int src;
	int dst;
	float weight;
	while ((std::cin >> src) && (std::cin >> dst) && (std::cin >> weight)) {
		g.addEdge(src, dst, weight);
	}
}

void createGraph(int N_VERTICES, int MAX_WEIGHT, float EDGE_CHANCE, long unsigned int &edges){
	float r;
    float f;
    for (int row = 0; row < N_VERTICES; row++){
		for (int col = 0; col < N_VERTICES; col++){
			if (row != col){
				r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				if (r <= EDGE_CHANCE){
					f = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                    g.addEdge(row, col, f*MAX_WEIGHT);
					std::cerr.flush();
					std::cerr << edges++  << " edges generated\r";
                }
			}
		}
	}
	std::cerr << '\n';
}