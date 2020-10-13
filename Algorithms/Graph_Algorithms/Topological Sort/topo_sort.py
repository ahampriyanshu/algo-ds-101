
# METHOD - 1 : TRAVERSING FROM DEPENDENCIES TO MATCHING PREREQUISITE JOBS
# O(j+d) T | O(j+d) S


def topologicalSort(jobs, deps):
    jobGraph = createJobGraph(jobs, deps)
    return getOrderedJobs(jobGraph)


def createJobGraph(jobs, deps):
    graph = JobGraph(jobs)
    for prereq, job in deps:
        graph.addPrereq(job, prereq)
    return graph


def getOrderedJobs(graph):
    orderedJobs = []
    nodes = graph.nodes
    while len(nodes):
        node = nodes.pop()
        containsCycle = dft(node, orderedJobs)
        if containsCycle:
            return []
    return orderedJobs


def dft(node, orderedJobs):
    if node.visited:
        return False
    if node.visiting:
        return True
    node.visiting = True
    for prereqNode in node.prereqs:
        containsCycle = dft(prereqNode, orderedJobs)
        if containsCycle:
            return True
    node.visited = True
    node.visiting = False
    orderedJobs.append(node.job)
    return False


class JobGraph:
    def __init__(self, jobs):
        self.nodes = []
        self.graph = {}
        for job in jobs:
            self.addNode(job)

    def addNode(self, job):
        self.graph[job] = JobNode(job)
        self.nodes.append(self.graph[job])

    def getNode(self, job):
        if job not in self.graph:
            self.addNode(job)
        return self.graph[job]

    def addPrereq(self, job, prereq):
        jobNode = self.getNode(job)
        prereqNode = self.getNode(prereq)
        jobNode.prereqs.append(prereqNode)


class JobNode:
    def __init__(self, job):
        self.job = job
        self.prereqs = []
        self.visited = False
        self.visiting = False


# METHOD 2 : TRAVERSING FROM PREREQUISITE JOB TO MATCHING DEPENDENCIES
# O(j+d) T | 0(j+d) S

def topologicalSort(jobs, deps):
    jobGraph = createJobGraph(jobs, deps)
    return getOrderedJobs(jobGraph)


def createJobGraph(jobs, deps):
    graph = JobGraph(jobs)
    for job, dep in deps:
        graph.addDep(job, dep)
    return graph


def getOrderedJobs(graph):
    orderedJobs = []
    nwnp = list(filter(lambda node: node.numOfPrereqs == 0, graph.nodes))
    while len(nwnp):
        node = nwnp.pop()
        orderedJobs.append(node.job)
        removeDeps(node, nwnp)
    graphHasEdges = any(node.numOfPrereqs for node in graph.nodes)
    return [] if graphHasEdges else orderedJobs


def removeDeps(node, nwnp):
    while len(node.deps):
        dep = node.deps.pop()
        dep.numOfPrereqs -= 1
        if dep.numOfPrereqs == 0:
            nwnp.append(dep)


class JobGraph:
    def __init__(self, jobs):
        self.nodes = []
        self.graph = {}
        for job in jobs:
            self.addNode(job)

    def addNode(self, job):
        self.graph[job] = JobNode(job)
        self.nodes.append(self.graph[job])

    def addDep(self, job, dep):
        jobNode = self.getNode(job)
        depNode = self.getNode(dep)
        jobNode.deps.append(depNode)
        depNode.numOfPrereqs += 1

    def getNode(self, job):
        if job not in self.graph:
            self.addNode(job)
        return self.graph[job]


class JobNode:
    def __init__(self, job):
        self.job = job
        self.deps = []
        self.numOfPrereqs = 0
