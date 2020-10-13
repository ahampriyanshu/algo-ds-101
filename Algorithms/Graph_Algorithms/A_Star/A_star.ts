/* GraphNode clas for A* Pathfinding 
 parent is parent of the current Node
 position is current psition of the Node in the maze
 g is cost from start to current Node
 h is heuristic based estimated cost for current Node to end Node
 f is total cost of present node: i.e. : f = g + h
*/
class GraphNode {
    public g: number;
    public h: number;
    public f: number;
    public position: Position;
    public parent: GraphNode | undefined;
    constructor(position: Position);
    constructor(position: Position, parent: GraphNode);
    constructor(position: Position, parent?: GraphNode) {
        this.g = 0;
        this.h = 0;
        this.f = 0;
        this.position = position;
        this.parent = parent;
    }

    isEqual(other: Position): boolean {
        return this.position.x == other.x && this.position.y == other.y;
    }
}

// Check if node is within the graph
const isValid = (grid: number[][], row: number, col: number): boolean => {
    return row >= 0 && row < grid.length && col >= 0 && col < grid[0].length;
};

// Check if node is not blocked node
const isUnBlocked = (grid: number[][], row: number, col: number) => {
    return grid[row][col] == 1;
};

const reachedDestination = (src: Position, dst: Position) => {
    return src.x == dst.x && src.y == dst.y;
};

const inList = (child: GraphNode, list: GraphNode[]): null | GraphNode => {
    for (let node of list) {
        if (node.isEqual(child.position)) {
            return node;
        }
    }
    return null;
};

const aStarSearch = (grid: number[][], src: Position, dst: Position) => {
    // If source is invalid
    if (!isValid(grid, src.x, src.y)) {
        console.log("Source is invalid");
        return;
    }
    // If destionation is invalid
    if (!isValid(grid, dst.x, dst.y)) {
        console.log("Destination is invalid");
    }

    // Check if the source and destination node code is blocked
    if (!isUnBlocked(grid, src.x, src.y) || !isUnBlocked(grid, dst.x, dst.y)) {
        console.log("Source or the destination is blocked");
    }

    //Check the destination node is the same as the source cell
    if (reachedDestination(src, dst)) {
        console.log("Destination is already reached ");
    }

    // Initialize startNode and endNode
    let startNode = new GraphNode(src);
    let endNode = new GraphNode(dst);

    console.log(startNode);
    console.log(endNode);

    // Initialize both open and closed list
    let openList: GraphNode[] = [];
    let closedList: GraphNode[] = [];

    // Add the start node to open list
    openList.push(startNode);

    while (openList.length > 0) {
        // Get the current node
        let currentNode = openList[0];
        let currentIndex = 0;
        for (let i = 0; i < openList.length; i++) {
            if (openList[i].f < currentNode.f) {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        // Pop current off open list, add to closed list
        openList.splice(currentIndex, 1);
        closedList.push(currentNode);

        // if the destination node is reached
        if (currentNode.isEqual(endNode.position)) {
            let path = [];
            let current: GraphNode | undefined = currentNode;
            while (current != undefined) {
                path.push(current.position);
                current = current.parent;
            }
            return path.reverse();
        }

        // Generate children
        let children = [];
        let neighbours = [
            new Position(0, -1),
            new Position(0, 1),
            new Position(-1, 0),
            new Position(1, 0),
            new Position(-1, -1),
            new Position(-1, 1),
            new Position(1, -1),
            new Position(1, 1),
        ];

        for (let position of neighbours) {
            // Get node postion
            let nodePosition = new Position(
                currentNode.position.x + position.x,
                currentNode.position.y + position.y
            );

            // Make sure within the range
            if (!isValid(grid, nodePosition.x, nodePosition.y)) {
                continue;
            }

            if (!isUnBlocked(grid, nodePosition.x, nodePosition.y)) {
                continue;
            }

            let newNode = new GraphNode(nodePosition, currentNode);
            children.push(newNode);

            // Loop through children
            for (let child of children) {
                if (inList(child, closedList)) {
                    continue;
                }

                child.g = currentNode.g + 1;
                child.h =
                    (child.position.x - endNode.position.x) ** 2 +
                    (child.position.y - endNode.position.y) ** 2;
                child.f = child.g + child.h;

                let openNode = inList(child, openList);
                if (openNode && child.g > openNode.g) {
                    continue;
                }

                // Add the child to the open list
                openList.push(child);
            }
        }
    }
};

class Position {
    constructor(public x: number, public y: number) {}
}

// 1--> The cell is not blocked
// 0--> The cell is blocked
let grid: number[][] = [
    [1, 0, 1, 1, 1, 1, 0, 1, 1, 1],
    [1, 1, 1, 0, 1, 1, 1, 0, 1, 1],
    [1, 1, 1, 0, 1, 1, 0, 1, 0, 1],
    [0, 0, 1, 0, 1, 0, 0, 0, 0, 1],
    [1, 1, 1, 0, 1, 1, 1, 0, 1, 0],
    [1, 0, 1, 1, 1, 1, 0, 1, 0, 0],
    [1, 0, 0, 0, 0, 1, 0, 0, 0, 1],
    [1, 0, 1, 1, 1, 1, 0, 1, 1, 1],
    [1, 1, 1, 0, 0, 0, 1, 0, 0, 1],
];

let src = new Position(8, 0);

let dst = new Position(0, 0);

let path = aStarSearch(grid, src, dst);
console.log(path);
