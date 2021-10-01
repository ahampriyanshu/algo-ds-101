function solveHanoi(
    counting: number,
    from: string,
    to: string,
    other: string,
    move: (from: string, to: string) => void
)
{
    if (counting > 0) {
        solveHanoi(counting - 1, from, other, to, move)
        move(from, to)
        solveHanoi(counting - 1, other, to, from, move)
    }
}
 
// Example: six discs
var moveCounting = 0
solveHanoi(6, "Left", "Right", "Middle", (from , to) => {
    ++moveCounting
    console.log(moveCounting + ": Move from " + from + " to " + to + ".")
})
