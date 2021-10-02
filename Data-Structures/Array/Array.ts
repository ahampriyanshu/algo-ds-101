import process from 'process';
import readline from 'readline';

/**
 * Helper function to read input from stdin asynchronously using the `readline` module and promises
 * @param prompt The prompt to show to the user in the terminal
 * @returns A promise that resolves to the user input
 */
function readInput(prompt: string): Promise<string> {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  return new Promise((resolve, reject) => {
    try {
      rl.question(prompt, (answer) => {
        rl.close();
        resolve(answer);
      });
    } catch (error) {
      rl.close();
      reject(error);
    }
  });
}

async function main() {
  // Ask user the number of elements they want to enter
  const n = await readInput('How many elements do you want to enter: ');
  // Create a new array
  const array = new Array(parseInt(n));

  // Ask user to enter up to `n` elements in the array
  // elements will be of type `string`
  for (let i = 0; i < array.length; i++) {
    array[i] = await readInput(`Enter element ${i}: `);
  }

  // Print the array
  console.log(array);
}

main();
