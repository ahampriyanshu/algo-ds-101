func ShellSort(_ items: [Int]) -> [Int] {
        var result = items
        
        let length = result.count
        var h = 1
        
        while h < length / 3 {
            h = 3 * h + 1
        }
        
        while h >= 1 {
            for i in h..<length {
                for j in stride(from: i, to: h - 1, by: -h) {
                    if result[j] < result[j - h] {
                        result.swapAt(j,j-h)
                    } else {
                        break
                    }
                }
            }
            h /= 3
        }
        
        return result
    }

var data:[Int] = [22, 7, 2, -5, 8, 4]
print(ShellSort(data)) // [-5, 2, 4, 7, 8, 22]

