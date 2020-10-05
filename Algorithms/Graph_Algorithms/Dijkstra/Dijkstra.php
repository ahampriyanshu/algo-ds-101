<?php

class Vertex {
    public $edges;

    public function __construct() {
        $this->edges = [];
    }

    public function addEdge($to, $d) {
        $this->edges[$to] = $d;
    }
}

class MinHeap extends SplPriorityQueue {
    public function compare($p1, $p2) {
        parent::compare($p2, $p1);
    }
}

class Graph {
    private $vList;

    public function __construct() {
        $this->vList = [];
    }

    public function insertVertex($label) {
        $this->vList[$label] = new Vertex();
    }

    public function insertEdge($from, $to, $d) {
        $this->vList[$from]->addEdge($to, $d);
    }

    public function dijkstra($from, $destination) {
        $distance = [];
        $prev = [];
        $visited = [$from];
        $pq = new MinHeap();
        $pq->setExtractFlags(SplPriorityQueue::EXTR_BOTH);

        // First we populate the distance and previous matrixes
        // The we insert each node in the priority queue
        foreach ($this->vList as $vid => $vertex) {
            $distance[$vid] = INF;
            $prev[$vid] = null;
        }

        $distance[$from] = 0;
        $pq->insert($from, 0);

        // Then we do the "main loop" where we explore the node with least distance to source
        while(!$pq->isEmpty()) {
            $v_dist = $pq->extract();
            $v = $v_dist['data'];
            $pathdist = $v_dist['priority'];
            $visited[$v] = True;

            foreach($this->vList[$v]->edges as $to=>$edgedist) {
                $tmpdist = $distance[$v] + $edgedist;

                if ($tmpdist < $distance[$to]) {
                    $distance[$to] = $tmpdist;
                    $prev[$to] = $v;
                    $pq->insert($to, $tmpdist);
                }
            }
        } 

        return $this->pathToString($prev, $destination);
    }

    public function pathToString($prev, $destination) {
        $from = $prev[$destination];
        if (is_null($from)) {
            return $destination;
        } else {
            return $this->pathToString($prev, $from).' -'.$this->vList[$from]->edges[$destination].'-> '.$destination;
        }
    }
}

// Hola
$g = new Graph();
$g->insertVertex("a");
$g->insertVertex("b");
$g->insertVertex("c");
$g->insertEdge("a", "b", 8);
$g->insertEdge("b", "c", 4);
$g->insertEdge("a", "c", 200);

echo $g->dijkstra("a", "c").PHP_EOL;

$g2 = new Graph();
$g2->insertVertex("a");
$g2->insertVertex("b");
$g2->insertVertex("c");
$g2->insertVertex("d");
$g2->insertEdge("a", "a", 0);
$g2->insertEdge("a", "b", 5);
$g2->insertEdge("a", "c", 10);
$g2->insertEdge("a", "d", 34);
$g2->insertEdge("b", "c", 3);
$g2->insertEdge("c", "d", 7);

$path = $g2->dijkstra("a", "d").PHP_EOL;

echo $path;
