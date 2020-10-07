def calcManhattanDist(x1, y1, x2, y2) -> float:
    return abs(x1 - x2) + abs(y1 - y2)

def main():
    print(calcManhattanDist(2, 5, 10, 14))

if __name__ == "__main__":
    main()