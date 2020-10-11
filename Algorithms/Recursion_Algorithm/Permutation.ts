class Permutation {
    getPermutations(input: string): string | string[] {
        // No permutation.
        if (input.length < 2) {
            return input;
        }

        const output: string[] = [];
        let counter: number = 0;
        for (counter = 0; counter < input.length; counter++) {
            const computeChar = input[counter];

            // No character repetitions allowed.
            if (input.indexOf(computeChar) != counter)
                continue;

            const characterYetToBeComputed = input.slice(0, counter) + input.slice(counter + 1, input.length);

            // For...of is supported in ECMAScript 5 and higher.
            for (const permutation of this.getPermutations(characterYetToBeComputed)) {
                output.push(computeChar + permutation);
            }
        }
        return output;
    }
}
