package main

import (
	"container/heap"
	"fmt"
)

// A PriorityQueue implements heap.Interface (Golang standard library)
type PriorityQueue struct {
	items    []Vertex
	index    map[Vertex]int // value to index
	priority map[Vertex]int // value to priority
}

func (pq *PriorityQueue) Len() int {
	return len(pq.items)
}

func (pq *PriorityQueue) Less(i, j int) bool {
	return pq.priority[pq.items[i]] < pq.priority[pq.items[j]]
}

func (pq *PriorityQueue) Swap(i, j int) {
	pq.items[i], pq.items[j] = pq.items[j], pq.items[i]
	pq.index[pq.items[i]] = i
	pq.index[pq.items[j]] = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(pq.items)
	item := x.(Vertex)
	pq.index[item] = n
	pq.items = append(pq.items, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := pq.items
	n := len(old)
	item := old[n-1]
	pq.index[item] = -1
	pq.items = old[0 : n-1]
	return item
}

func (pq *PriorityQueue) update(item Vertex, priority int) {
	pq.priority[item] = priority
	heap.Fix(pq, pq.index[item])
}

func (pq *PriorityQueue) addWithPriority(item Vertex, priority int) {
	heap.Push(pq, item)
	pq.update(item, priority)
}

// Graph is the interface so that this algorithm can run on.
type Graph interface {
	Vertices() []Vertex
	Neighbors(v Vertex) []Vertex
	Weight(u, v Vertex) int
}

// Vertex is type alias int
type Vertex int

// DijkstraGraph is a graph of strings that satisfies the Graph interface.
// this graph has label and index, so you can customize the label and the index
type DijkstraGraph struct {
	ids   map[string]Vertex
	names map[Vertex]string
	edges map[Vertex]map[Vertex]int
}

// NewDijkstraGraph is a constructor to DijkstraGraph struct
func NewDijkstraGraph(ids map[string]Vertex) DijkstraGraph {
	dg := DijkstraGraph{ids: ids}
	dg.names = make(map[Vertex]string, len(ids))
	for k, v := range ids {
		dg.names[v] = k
	}
	dg.edges = make(map[Vertex]map[Vertex]int)
	return dg
}
func (dg DijkstraGraph) edge(u, v string, w int) {
	if _, ok := dg.edges[dg.ids[u]]; !ok {
		dg.edges[dg.ids[u]] = make(map[Vertex]int)
	}
	dg.edges[dg.ids[u]][dg.ids[v]] = w
}
func (dg DijkstraGraph) path(v Vertex, path map[Vertex]Vertex) (s string) {
	s = dg.names[v]
	for path[v] >= 0 {
		v = path[v]
		s = dg.names[v] + s
	}
	return s
}
func (dg DijkstraGraph) Vertices() []Vertex {
	vertices := make([]Vertex, 0, len(dg.ids))
	for _, v := range dg.ids {
		vertices = append(vertices, v)
	}
	return vertices
}
func (dg DijkstraGraph) Neighbors(u Vertex) []Vertex {
	vertices := make([]Vertex, 0, len(dg.edges[u]))
	for v := range dg.edges[u] {
		vertices = append(vertices, v)
	}
	return vertices
}
func (dg DijkstraGraph) Weight(u, v Vertex) int { return dg.edges[u][v] }

const (
	Infinity      = int(^uint(0) >> 1)
	Uninitialized = -1
)

// Dijkstra function will receive Graph interface and the source and output the distance and the path
func Dijkstra(g Graph, source Vertex) (dist map[Vertex]int, path map[Vertex]Vertex) {
	vertices := g.Vertices()
	dist = make(map[Vertex]int, len(vertices))
	path = make(map[Vertex]Vertex, len(vertices))
	s := source
	dist[s] = 0
	q := &PriorityQueue{
		items:    make([]Vertex, 0, len(vertices)),
		index:    make(map[Vertex]int, len(vertices)),
		priority: make(map[Vertex]int, len(vertices)),
	}
	for _, v := range vertices {
		if v != s {
			dist[v] = Infinity
		}
		path[v] = Uninitialized
		q.addWithPriority(v, dist[v])
	}
	for len(q.items) != 0 {
		u := heap.Pop(q).(Vertex)
		for _, v := range g.Neighbors(u) {
			alt := dist[u] + g.Weight(u, v)
			if alt < dist[v] {
				dist[v] = alt
				path[v] = u
				q.update(v, alt)
			}
		}
	}
	return dist, path
}

func main() {
	g := NewDijkstraGraph(map[string]Vertex{
		"a": 1,
		"b": 2,
		"c": 3,
		"d": 4,
		"e": 5,
		"f": 6,
	})
	g.edge("a", "b", 8)
	g.edge("a", "c", 9)
	g.edge("a", "f", 13)
	g.edge("b", "c", 9)
	g.edge("b", "d", 14)
	g.edge("c", "d", 11)
	g.edge("c", "f", 2)
	g.edge("d", "e", 7)
	g.edge("e", "f", 9)

	dist, path := Dijkstra(g, g.ids["a"])
	fmt.Println("From a =")
	fmt.Printf("Distance to %s: %d, Path: %s\n", "e", dist[g.ids["e"]], g.path(g.ids["e"], path))
	fmt.Printf("Distance to %s: %d, Path: %s\n", "f", dist[g.ids["f"]], g.path(g.ids["f"], path))
}
