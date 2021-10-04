var parent = [Int]()

func findParent (inp: Int) -> Int {
    var i = inp
    while (parent[i] != i) {
        i = parent[i]
    }
    return i
}

func createSharedParent(i: Int, j: Int) {
    let a = findParent(inp: i)
    let b = findParent(inp: j)
    parent[a] = b
}

func kruskal (_ matrix : [[Int]]) {
    var minCost = 0
    for i in 0..<matrix.count {
        parent.append(i)
    }
    var edge_count = 0
    while edge_count < matrix.count - 1 {
        var min = Int.max
        var a = -1
        var b = -1
        for i in 0..<matrix.count {
            for j in 0..<matrix.count {
                if ( findParent(inp: i) != findParent(inp: j) && matrix[i][j] < min ) {
                    min = matrix[i][j]
                    a = i
                    b = j
                }
            }
        }
        createSharedParent(i: a, j: b)
        minCost += min
        print ("Edge \(edge_count): \(a) \(b), cost: \(min)")
        edge_count += 1
    }
    print ("Minimum cost = ", minCost)
}

let input = [
    [Int.max,2,1,Int.max,Int.max],
    [2,Int.max,3,8,4],
    [1,3,Int.max,6,4],
    [Int.max,8,6,Int.max,5],
    [Int.max,4,4,5,Int.max]
]