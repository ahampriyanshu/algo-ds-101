xin = "Shubham";

treshold = 150;

c = {
	0: [], // input encoded
	1: [], // key encoded
	2: [], // cipher encoded
	3: []  // decoded encoded
};

for (i=0;i<=xin.length;++i) c[0].push((xin[i]+"").charCodeAt(0));
console.log("Encoded input: " + c[0].join(", "));

// c[0] is input

// generate challenge key

for (i=0;i<=c[0].length;++i) c[1].push(Math.round(Math.random()*treshold));
console.log("Generated Challenge Pad: " + c[1].join(", "));

// generate cipher

for (i=0;i<=c[0].length;++i) c[2].push(c[0][i] ^ c[1][i]);
console.log("Resulting Cipher: " + c[2].join(", "));

for (i=0;i<=c[0].length - 1;++i) c[3].push(c[2][i] ^ c[1][i]);
console.log("Recalculated Pad: " + c[3].join(", "));

console.log("Has decoding been successful? " + ( c[0].join() == c[3].join() ? "Yes" : "No" ));
