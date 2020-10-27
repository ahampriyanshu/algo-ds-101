'use strict'

test();

function buildLPSArray(pattern, M) {
  let lps = [0];
  let prefixIndex = 0;
  let suffixIndex = 1;

  while(suffixIndex < M) {
    if(pattern[prefixIndex] === pattern[suffixIndex]){
      prefixIndex++;
      lps[suffixIndex] = prefixIndex;
      suffixIndex++;
    } else if (prefixIndex === 0){
      lps[suffixIndex] = 0;
      suffixIndex++;
    } else {
      prefixIndex = lps[prefixIndex - 1];
    }
  }

  return lps;
}

function KMPSearch(text, pattern) {
  const M = pattern.length;
  const N = text.length;

  const lps = buildLPSArray(pattern, M);

  let textIndex = 0;
  let patterndIndex = 0;

  while(textIndex < N){
    if(text[textIndex] === pattern[patterndIndex]) {
      if(patterndIndex === M - 1) {
        return true;
      }
      textIndex++;
      patterndIndex++;
    } else if(patterndIndex > 0) {
      patterndIndex = lps[patterndIndex - 1];
    } else {
      patterndIndex = 0;
      textIndex++;
    }
  }
  return false;
}

function test() {
  let text = [..."ABCABBCABABBABB"];
  let pattern = [..."ABB"];
  console.log(KMPSearch(text, pattern));
}