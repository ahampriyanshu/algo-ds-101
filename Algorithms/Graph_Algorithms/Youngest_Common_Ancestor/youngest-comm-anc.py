
# O(d) T | O(1)S


class AncestralTree:
    def __init__(self, name):
        self.name = name
        self.ancestor = None


def getYoungestCommonAncestor(topAncestor, descendantOne, descendantTwo):
    depOne = getDescDep(descendantOne, topAncestor)
    depTwo = getDescDep(descendantTwo, topAncestor)
       if depOne > depTwo:
            return youngCommon(descendantOne, descendantTwo, depOne-depTwo)
        else:
            return youngCommon(descendantTwo, descendantOne, depTwo-depOne)


def getDescDep(desc, top):
    depth = 1
    while desc != top:
        depth += 1
        desc = desc.ancestor
    return depth

def youngCommon(lowerDesc, higherDesc, diff):
    while diff > 0:
        lowDesc = lowerDesc.ancestor
        diff -= 1

    while higherDesc != lowerDesc:
        higherDesc = higherDesc.ancestor
        lowerDesc = lowerDesc.ancestor
    return lowerDesc
