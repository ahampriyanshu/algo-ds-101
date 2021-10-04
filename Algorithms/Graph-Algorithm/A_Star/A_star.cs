using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

//Please use Wikipedia to see, what A* is and how it works. I will try to point out as much as i can inside
//my comments, but a complete explanation would blow up this file.

//In this implementation, i do not support diagonal movement to reduce a little complexity and
//eliminate the need for a rule about movement through diagonal walls

public class AStar
{
    private readonly IList<Node> _nodes;
    private readonly Point _start;
    private readonly Point _finish;

    public AStar(IList<Node> nodes, Point start, Point finish)
    {
        _nodes = nodes;
        _start = start;
        _finish = finish;
    }

    public IEnumerable<Point> GetPath()
    {
        //select the starting node
        var startNode = _nodes.Single(n => n.Position == _start);
        
        //calculate the path
        if (PathExists(startNode))
        {
            //if a path between start and finish can be found, it can be read via the parentNode
            //properties that now link from finish to start
            //(for this example the order is irrelevant, but for other usecases, the result might
            //have to be reverted to point from start to finish)
            return ReadPath();
        }

        return Enumerable.Empty<Point>();
    }

    private bool PathExists(Node currentNode)
    {
        //uncomment following two lines to see A* in action
        //Tools.PrintMaze(_nodes.ToList(), Enumerable.Empty<Point>().ToList(), _start, _finish,  currentNode.Position);
        //Console.ReadKey();
        
        //set current node state to closed, so that we will not walk back here and create a loop
        currentNode.State = NodeState.Closed;
        
        //get possible next nodes
        var nextNodes =
            GetSurroundingWalkableNodes(currentNode) //get a list of all nodes that should be considered for our next move
                .Select(n => UpdateNodeParameters(n, currentNode)) //update each nodes properties
                .OrderBy(n => n.EstimatedTotalDistance); //check most promising decisions first

        foreach (var nextNode in nextNodes) //iterate through all possible next nodes
        {
            if (nextNode.Position == _finish) //if we reached the finishing point, we're done 
                return true;
            if (PathExists(nextNode)) //otherwise we'll check our moves from this node on
                return true; //if the next node reached the finishing point, we're done. otherwise we continue withe the next foreach iteration
        }
        //if we checked every possible way and did not reach the finishing point, there is no way
        return false;
    }

    private IEnumerable<Node> GetSurroundingWalkableNodes(Node currentNode)
    {
        //first, get all four possibly surrounding points of current node
        //don't worry about nodes that are outside the grid, we'll filter them out next
        var surroundingPoints = GetSurroundingPoints(currentNode);

        return _nodes
            .Where(n => surroundingPoints
                .Contains(n.Position)) //now we have all nodes that exist for surrounding points
            .Where(n => n.IsWalkable) //filter out all that are not walkable
            .Where(n => n.State != NodeState.Closed) //filter out all nodes, that already exist in the current path
            .Where(n =>
            {
                switch (n.State)
                {
                    case NodeState.Untested: //previously untested nodes are always considered for next move
                        return true;
                    case NodeState.Open: //if a node has already been tested, we only consider it, if that new node cannot be reached on a shorter way
                        if (currentNode.MovesFromStart + 1 < n.MovesFromStart)
                            return true;
                        return false;
                    case NodeState.Closed:
                        return false;
                    default:
                        throw new ArgumentOutOfRangeException();
                }
            });
    }

    private IEnumerable<Point> GetSurroundingPoints(Node currentNode)
    {
        yield return new Point(currentNode.Position.X + 1, currentNode.Position.Y);
        yield return new Point(currentNode.Position.X - 1, currentNode.Position.Y);
        yield return new Point(currentNode.Position.X, currentNode.Position.Y - 1);
        yield return new Point(currentNode.Position.X, currentNode.Position.Y + 1);
    }

    private Node UpdateNodeParameters(Node nextNode, Node currentNode)
    {
        //set new parent
        nextNode.Parent = currentNode;
        
        //on this path, this node is one hop further than the parent
        nextNode.MovesFromStart = currentNode.MovesFromStart + 1; 
        
        //calculate the straight line distance to finish point. this will stay the same value on each iteration, 
        //so it only needs to be done once
        if (nextNode.State == NodeState.Untested)
        {
            nextNode.StraightLineDistanceToFinish = StraightLineDistance(nextNode.Position, _finish);
            nextNode.State = NodeState.Open;
        }

        //return updatedNode
        return nextNode;
    }

    private double StraightLineDistance(Point a, Point b)
    {
        //simple pythagorean triangle.
        //no need to worry if b.X-a.X might become negative, because we square it anyway 
        return Math.Sqrt(Math.Pow(b.X - a.X, 2) + Math.Pow(b.Y - a.Y, 2));
    }
    
    private IEnumerable<Point> ReadPath()
    {
        yield return _finish;
        
        var node = _nodes.First(n => n.Position == _finish);
        
        while (node.Parent != null)
        {
            yield return node.Parent.Position;
            node = node.Parent;
        }

        yield return _start;
    }
}

public class Node 
{
    public Point Position { get; set; }
    public int MovesFromStart { get; set; }
    public double StraightLineDistanceToFinish { get; set; }
    public double EstimatedTotalDistance => MovesFromStart + StraightLineDistanceToFinish;
    public NodeState State { get; set; }
    public bool IsWalkable { get; set; }
    public Node Parent { get; set; }

    public Node(int x, int y, bool isWalkable)
    {
        Position = new Point(x, y);
        IsWalkable = isWalkable;
    }
}

public enum NodeState
{
    Untested = 0,
    Open = 1,
    Closed = 2
}


//use dotnet-script to run this file without solution
private const char ObstacleChar = 'x';
private const char FreeFieldChar = '.';
private const char StartingPointChar = 's';
private const char FinishingPointChar = 'f';
private const char PathChar = '*';


Console.WriteLine("Enter maze via command line");
Console.WriteLine("S = Start");
Console.WriteLine("F = Finish");
Console.WriteLine("X = Obstacle");
Console.WriteLine(". = Free Field (actually any char but X, S or F will work)");
Console.WriteLine("Empty line will finish maze creation");

var maze = new List<Node>();
Point? start = null;
Point? finish = null;

var input = Console.ReadLine();
var yIndex = 0;
while (!string.IsNullOrEmpty(input))
{
    var chars = input
        .ToLower()
        .ToCharArray();
    var xIndex = 0;
    foreach (var c in chars)
    {
        var walkable = c != ObstacleChar;
        maze.Add(new Node(xIndex, yIndex, walkable));
        if (c == StartingPointChar)
            start = new Point(xIndex, yIndex);
        if (c == FinishingPointChar)
            finish = new Point(xIndex, yIndex);
        xIndex++;
    }

    yIndex++;
    input = Console.ReadLine();
}

if (start == null || finish == null) throw new ArgumentException("Start and Finish need to be set");

var solution = new AStar(maze, start.Value, finish.Value).GetPath().ToList();

Tools.PrintMaze(maze, solution, start, finish);
Console.WriteLine(solution.Any() ? "A* found a path" : "Could not find a path");
    
public static class Tools {
    public static void PrintMaze(List<Node> maze, IList<Point> solution, Point? start, Point? finish, Point? current = null)
    {
        Console.Clear();

        var lines = maze
            .OrderBy(n => n.Position.X)
            .GroupBy(n => n.Position.Y)
            .OrderBy(l => l.Key);

        foreach (var line in lines)
        {
            foreach (var node in line)
            {
                SetConsoleColor(solution, node, current);
                var character = GetCharacter(solution, start, finish, current, node);
                Console.Write(character);
            }
            Console.WriteLine();
        }

    }

    private static char GetCharacter(IList<Point> solution, Point? start, Point? finish, Point? current, Node node)
    {
        var character = ObstacleChar;
        if (node.IsWalkable) character = FreeFieldChar;
        if (solution.Contains(node.Position)) character = PathChar;
        if (node.Position == start) character = StartingPointChar;
        if (node.Position == finish) character = FinishingPointChar;
        if (node.Position == current) character = PathChar;
        return character;
    }

    private static void SetConsoleColor(IList<Point> solution, Node node, Point? current)
    {
        Console.ForegroundColor = ConsoleColor.White;
        if (solution.Contains(node.Position)) Console.ForegroundColor = ConsoleColor.Green;
        if (node.Position == current) Console.ForegroundColor = ConsoleColor.Red;
    }
}