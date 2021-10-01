import kotlin.collections.ArrayList

class Node<T>(val value: T) {
    val neighbors = ArrayList<Node<T>>()
    fun addNeighbor(node: Node<T>) = neighbors.add(node)
    override fun toString(): String = value.toString()
}

class Graph<T> {
    private val nodes = HashSet<Node<T>>()

    fun addNode(value: T) {
        val newNode = Node(value)
        nodes.add(newNode)
    }

    fun getNode(reference: T): Node<T>? {
        return nodes.firstOrNull { it.value == reference }
    }

    fun addVertex(from: T, to: T) {
        getNode(to)?.let { getNode(from)?.addNeighbor(it) }
    }
}

fun <T> Graph<T>.bfs(reference: T): List<T> {
    getNode(reference)?.let { referenceNode ->
        val visited = ArrayList<Node<T>>()
        val queue = ArrayList<Node<T>>()
        queue.add(referenceNode)

        while (queue.isNotEmpty()) {
            val node = queue.removeAt(0)
            if (!visited.contains(node)) {
                visited.add(node)
                node.neighbors
                        .filter { !visited.contains(it) }
                        .forEach { queue.add(it) }
            }
        }
        return visited.map { it.value }
    }
    return emptyList()
}

fun <T> Graph<T>.dfs(reference: T): List<T> {
    getNode(reference)?.let { referenceNode ->
        val visited = ArrayList<Node<T>>()
        val stack = ArrayList<Node<T>>()
        stack.add(referenceNode)

        while (stack.isNotEmpty()) {
            val node = stack.removeAt(stack.lastIndex)
            if (!visited.contains(node)) {
                visited.add(node)
                node.neighbors
                        .filter { !visited.contains(it) }
                        .forEach { stack.add(it) }
            }
        }
        return visited.map { it.value }
    }
    return emptyList()
}

fun main() {
    val namesGraph = Graph<String>()

    namesGraph.addNode("Minato")
    namesGraph.addNode("Obito")
    namesGraph.addVertex("Minato", "Obito")
    namesGraph.addNode("Kakashi")
    namesGraph.addVertex("Minato", "Kakashi")
    namesGraph.addNode("Rin")
    namesGraph.addVertex("Minato", "Rin")
    namesGraph.addNode("Naruto")
    namesGraph.addVertex("Kakashi", "Naruto")
    namesGraph.addNode("Sakura")
    namesGraph.addVertex("Kakashi", "Sakura")
    namesGraph.addNode("Sasuke")
    namesGraph.addVertex("Kakashi", "Sasuke")

    print(namesGraph.bfs("Minato"))
    print(namesGraph.dfs("Minato"))
}
