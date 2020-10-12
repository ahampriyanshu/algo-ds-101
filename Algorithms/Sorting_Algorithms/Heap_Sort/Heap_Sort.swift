private extension Int {
  var parent: Int {
    return (self - 1) / 2
  }
  
  var leftChild: Int {
    return (self * 2) + 1
  }
  
  var rightChild: Int {
    return (self * 2) + 2
  }
}

class SortingAlgorithms {
  private init() {}
  
  public static func heapSort<DataType: Comparable>(_ array: inout [DataType]) {
    if array.count < 2 { return }
    buildHeap(&array)
    shrinkHeap(&array)
  }
  
  private static func buildHeap<DataType: Comparable>(_ array: inout [DataType]) {
    for index in 1..<array.count {
      var child = index
      var parent = child.parent
      while child > 0 && array[child] > array[parent] {
        swap(child, with: parent, in: &array)
        child = parent
        parent = child.parent
      }
    }
  }
  
  private static func shrinkHeap<DataType: Comparable>(_ array: inout [DataType]) {
    for index in stride(from: array.count - 1, to: 0, by: -1) {
      swap(0, with: index, in: &array)
      var parent = 0
      var leftChild = parent.leftChild
      var rightChild = parent.rightChild
      while parent < index {
        var maxChild = -1
        if leftChild < index {
          maxChild = leftChild
        } else {
          break
        }
        if rightChild < index && array[rightChild] > array[maxChild] {
          maxChild = rightChild
        }
        guard array[maxChild] > array[parent] else { break }
        
        swap(parent, with: maxChild, in: &array)
        parent = maxChild
        leftChild = parent.leftChild
        rightChild = parent.rightChild
      }
    }
  }
  
  private static func swap<DataType: Comparable>(_ firstIndex: Int, with secondIndex: Int, in array: inout [DataType]) {
    let temp = array[firstIndex]
    array[firstIndex] = array[secondIndex]
    array[secondIndex] = temp
  }
}

var myArray = [3,4,1,2]
SortingAlgorithms.heapSort(&myArray)
print(myArray)
