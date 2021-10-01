/// this is a node js script to calcualate permuatations and combinations
/// this is built by github.com/ahmeddrawy for hacktoberfest 2020 
/// hope this helps you 

/// to run open terminal and run 
/// node <filename> [option 1] [option 2] [option 3]
// example "node permutation_combination.js c 100 40"

/// this is a self-invoked  function
(function run(){
   /// check if the input size is right node <filename> [option 1] [option 2] [option 3]
   let inputSize = process.argv.length === 5 ;
   /// validate first option to be <p> or <c>
   let validateFirstInput = (process.argv[2]).toLowerCase() ==='p' || (process.argv[2]).toLowerCase() ==='c';  
   /// validate that options 3 and 4 are not a not a number (this is a double negation lol :'D )  
   let validateSecondAndThirdInput = !isNaN( process.argv[3])  && !isNaN( process.argv[4]);
  
   const permutationOrCombination = process.argv[2].toLowerCase();
   const N = parseInt( process.argv[3]);
   const R = parseInt( process.argv[4]);
   let nGreaterthanR = N > R;
   let greaterThanZero = N>0 && R > 0
   /// the input must meet all above constraints anded together so if not we output the menu then return 
   if(!(inputSize && validateFirstInput  &&  validateSecondAndThirdInput  && nGreaterthanR && greaterThanZero)){
      promoptForInput();
      return ;
   }
   if(permutationOrCombination ==='p'){
      console.log(`permutation ${N}P${R} =` , permutation(N,R));
   }
   else {
      console.log(`Combination ${N}C${R} =` , permutation(N,R));

   }
})();
/// this is the simplest implementation for nPr and nCr 
/// but not the most efficient one 
/// this is the first release so I will improve it in future if I have time
function permutation(N , R){
   return Factorial(N)/Factorial(N-R);
}
function permutation(N , R){
   return Factorial(N)/Factorial(N-R);
}
function combination(N, R){
   return Factorial(N)/(Factorial(N-R) * Factorial(R));
   
}
function Factorial(N){
   if(N<=1) return 1 ;  
   return N* Factorial(N-1);
}
/// this function is a guide for input style
function promoptForInput(){
   console.log('this is a node js script to calcualate permuatations (nPr) and combinations (nCr)');
   console.log('please provide options like this from ');
   console.log('node <filename> [option 1] [option2] [option3]');
   console.log('where\n\t[option 1] is P or C where P is for permutation and C is for Combination ');
   console.log('\t[option 2] is ( N ) where N is for nCr or nPr ');
   console.log('\t[option 3] is ( R ) where R is for nCr or nPr ');
   console.log('Conditions :');
   console.log('\t N must be larger than R and both are larger than Zero');
   console.log('Examples :');
   console.log('\tnode permutation_combination.js c 10 4');
   console.log('\tnode permutation_combination.js p 10 4');
}