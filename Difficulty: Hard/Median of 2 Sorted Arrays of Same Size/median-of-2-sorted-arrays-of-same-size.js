//{ Driver Code Starts
// Initial Template for javascript

// Initial Template for javascript

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => { inputString += inputStdin; });

process.stdin.on('end', _ => {
    inputString =
        inputString.trim().split('\n').map(string => { return string.trim(); });

    main();
});

function readLine() { return inputString[currentLine++]; }

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for (; i < t; i++) {
        let arr1 = readLine().split(' ').map(x => parseInt(x));
        let arr2 = readLine().split(' ').map(x => parseInt(x));
        let obj = new Solution();

        if (arr2.length === 1 && arr2[0] === 0) {
            arr2 = []
        }
        let res = obj.medianOf2(arr1, arr2);
        if (parseInt(res) === res) {
            console.log(parseInt(res))
        } else {
            console.log(res);
        }
        console.log("~")
    }
}
// } Driver Code Ends


// User function Template for javascript

/**
 * @param {Number[]} arr1
 * @param {Number[]} arr2
 * @returns {Number}
 */
class Solution {
    medianOf2(a, b) {
        let totalSorted = [...a, ...b]
        totalSorted.sort((x, y) => x - y) 
        let middle = Math.floor(totalSorted.length / 2)

        if (totalSorted.length % 2 === 0) {
            
            return (totalSorted[middle - 1] + totalSorted[middle]) / 2;
        } else {
            
            return totalSorted[middle];
        }
    }
}