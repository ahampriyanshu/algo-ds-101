function getPermutations(input) {
    // Input should be a string.
    if (!input || typeof input !== "string") {
        return "Input must be a string."
    }

    // No permutation.
    if (input.length < 2) {
        return [input];
    }
    var output = [];
    var counter = 0;
    for (counter = 0; counter < input.length; counter++) {
        var computeChar = input[counter];
        // No character repetitions allowed.
        if (input.indexOf(computeChar) != counter)
            continue;
        var characterYetToBeComputed = input.slice(0, counter) + input.slice(counter + 1, input.length);
        // For...of is supported in ECMAScript 5 and higher.
        for (var permutation of getPermutations(characterYetToBeComputed)) {
            output.push(computeChar + permutation);
        }
    }
    return output;
}
