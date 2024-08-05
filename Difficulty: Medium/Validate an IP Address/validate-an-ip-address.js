//{ Driver Code Starts
// Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => { inputString += inputStdin; });

process.stdin.on("end", (_) => {
    inputString =
        inputString.trim().split("\n").map((string) => { return string.trim(); });

    main();
});

function readLine() { return inputString[currentLine++]; }

/* Function to print an array */
function printArray(arr, size) {
    let i;
    let s = "";
    for (i = 0; i < size; i++) {
        s += arr[i] + " ";
    }
    console.log(s);
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for (; i < t; i++) {
        let IPadd = readLine();

        let obj = new Solution();
        let res = obj.isValid(IPadd);
        if (res)
            console.log("true");
        else
            console.log("false");
    }
}
// } Driver Code Ends




//User function Template for javascript

/**
 * @param {string} s
 * @returns {number}
 */

class Solution {
    
    isValid(s){ 
        let a=[]
        a=s.split('.');
        if(a.length!==4){
          return 0
        }
        for(let i=0; i<a.length;i++) {
          let ele=""+a[i];
          if(ele.length>1 && ele[0]==0){
              return 0
          }
          if(!(a[i]>=0 && a[i]<=255) || a[i]===''){
              return 0
          }
        }
        return 1;
    }
}