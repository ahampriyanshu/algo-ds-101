# O(N) T | O(d) S
#numIP = numberOfImportantReports
#lcm = lowestCommonManager

def getLowestCommonManager(topManager, reportOne, reportTwo):
    return getOrgInfo(topManager, reportOne, reportTwo).lcm


def getOrgInfo(manager, reportOne, reportTwo):
    numIP = 0
    for dirRep in manager.directReports:
        orgInfo = getOrgInfo(dirRep, reportOne, reportTwo)
        if orgInfo.lcm is not None:
            return orgInfo
        numIP += orgInfo.numIP
    if manager == reportOne or manager == reportTwo:
        numIP += 1
    lcm = manager if numIP == 2 else None
    return OrgInfo(lcm, numIP)


class OrgInfo:
    def __init__(self, lcm, numIP):
        self.lcm = lcm
        self.numIP = numIP

# This is an input class. Do not edit.


class OrgChart:
    def __init__(self, name):
        self.name = name
        self.directReports = []
