#include "WDGraph.h"

#define INF 10e6;

// EdgeNode methods

EdgeNode::EdgeNode(int src, int dst, float weight, EdgeNode *next) {
	_src = src;
	_dst = dst;
	_weight = weight;
	_next = next;
}

// VertexNode methods

VertexNode::VertexNode(int elem, VertexNode *next, EdgeNode *edges) {
	_elem = elem;
	_dist = INF;
	_nodesPointed = 0;
	_visited = 0;
	_parentOnMinPath = NULL;
	_next = next;
	_edges = edges;
}

// WDGraph methods

WDGraph::WDGraph() {
	_head = NULL;
	_nVertex = 0;
	_map = new std::unordered_map<int, VertexNode*>;
}

void WDGraph::addEdge(int src, int dst, float weight) {
	// Se encarga de anadir las aristas al grafo, si alguno de los vertices mencionados en la arista no forma parte del grafo, lo anade tambien
	if (_head == NULL) {
		EdgeNode *edge1 = new EdgeNode(src, dst, weight, NULL); // Creamos la arista src -> dst
		VertexNode *aux = new VertexNode(dst, NULL, NULL); // Creamos el vertice dst
		_head = new VertexNode(src, aux, edge1); // Creamos el vertice src y lo asignamos a _head
		_head->_nodesPointed++;
		_map->insert(std::make_pair(src, _head));
		_map->insert(std::make_pair(dst, aux));
		_nVertex += 2; // Aumentamos el # de vertices
	} else {
		EdgeNode *aux = NULL;
		VertexNode *vAux = NULL;
		std::unordered_map<int, VertexNode*>::iterator iter = _map->find(src);
		if (iter != _map->end()) {
			aux = iter->second->_edges;
			iter->second->_edges = new EdgeNode(src, dst, weight, aux);
			iter->second->_nodesPointed++;
		} else {
			EdgeNode *eAux = new EdgeNode(src, dst, weight, NULL);
			vAux = _head;
			_head = new VertexNode(src, vAux, eAux);
			_head->_nodesPointed++;
			_map->insert(std::make_pair(src, _head));
			_nVertex++;
		}
		iter = _map->find(dst);
		if (iter == _map->end()) {
			vAux = _head;
			_head = new VertexNode(dst, vAux, NULL);
			_map->insert(std::make_pair(dst, _head));
			_nVertex++;
		}
	}
}

void WDGraph::printGraph() {
	// DEBUG
	VertexNode *vertex = _head;
	for (int i = 0; i < _nVertex; i++) {
		std::cerr << "Adyacency list of: " << vertex->_elem << '\n';
		EdgeNode *edge = vertex->_edges;
		while (edge) {
			std::cerr << " -> " << edge->_dst << " (" << edge->_weight << ')';
			edge = edge->_next;
		}
		std::cerr << '\n';
		vertex = vertex->_next;
	}
}

void WDGraph::printGraphvertices() {
	// DEBUG
	VertexNode *vertex = _head;
	for (int i = 0; i < _nVertex; i++) {
		std::cerr << "Vertex: " << vertex->_elem << '\n';
		std::cerr << "   # of pointed nodes: " << vertex->_nodesPointed << '\n';
		std::cerr << "   visited: "
				<< (vertex->_visited ? "True\n" : "False\n");
		std::cerr << "   distance: " << vertex->_dist << '\n';
		if (vertex->_parentOnMinPath != NULL)
			std::cerr << "   parentOnShortestPath: "
					<< vertex->_parentOnMinPath->_elem << '\n';
		std::cerr << '\n';
		vertex = vertex->_next;
	}
}

void WDGraph::getvertices(std::vector<VertexNode*> &ret) {
	VertexNode *vertex = _head;
	for (int i = 0; i < _nVertex; i++) {
		ret.push_back(vertex);
		vertex = vertex->_next;
	}
}

void WDGraph::changeVertexDistance(int e, float newDist) {
	std::unordered_map<int, VertexNode*>::iterator iter = _map->find(e);
	if (iter != _map->end()) {
		iter->second->_dist = newDist;
	} else {
		std::cerr << e << " is not currently in the graph.\n";
	}
}

void WDGraph::changeParent(int e, VertexNode *parent) {
	std::unordered_map<int, VertexNode*>::iterator iter = _map->find(e);
	if (iter != _map->end()) {
		iter->second->_parentOnMinPath = parent;
	} else {
		std::cerr << e << " is not currently in the graph.\n";
	}
}

void WDGraph::visitVertex(int e) {
	std::unordered_map<int, VertexNode*>::iterator iter = _map->find(e);
	if (iter != _map->end()) {
		iter->second->_visited = 1;
	} else {
		std::cerr << e << " is not currently in the graph.\n";
	}
}

void WDGraph::getNeightbours(int e, std::vector<EdgeNode*> &ret) {
	std::unordered_map<int, VertexNode*>::iterator iter = _map->find(e);
	EdgeNode *aux;
	if (iter != _map->end()) {
		aux = iter->second->_edges;
		for (int i = 0; i < iter->second->_nodesPointed; i++) {
			if (!getVertex(aux->_dst)->_visited)
				ret.push_back(aux);
			aux = aux->_next;
		}
	} else {
		std::cerr << e << " is not currently in the graph.\n";
	}
}

int WDGraph::getNumberOfNeightbours(int e) {
	std::unordered_map<int, VertexNode*>::iterator iter = _map->find(e);
	if (iter != _map->end()) {
		return iter->second->_nodesPointed;
	} else {
		std::cerr << e << " is not currently in the graph.\n";
	}
	return -1;
}

VertexNode* WDGraph::getVertex(int e) {
	std::unordered_map<int, VertexNode*>::iterator iter = _map->find(e);
	if (iter != _map->end()) {
		return iter->second;
	} else {
		std::cerr << e << " is not currently in the graph.\n";
	}
	return NULL;
}
