//{ Driver Code Starts
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

/* Function to print an array */
function printArray(arr, size) {

    let i;
    let s = '';
    for (i = 0; i < size; i++) {
        s += arr[i] + " ";
    }
    console.log(s);
}

function main() {
    let t = parseInt(readLine()); // Number of test cases
    for (let i = 0; i < t; i++) {
        let N = parseInt(readLine()); // Number of rows
        let M = parseInt(readLine()); // Number of columns

        // Read the board
        let board = [];
        for (let j = 0; j < N; j++) {
            let row = readLine().split(' ');
            board.push(row);
        }

        // Read the words to search
        let words = readLine().split(' ');

        // Create an instance of Solution and call the function to find words
        let obj = new Solution();
        let res = obj.findWords(
            board, words); // Assuming findWords is the function to search for words
        if (res.length === 0) { // Check if the array 'ans' is empty
            console.log("[]");  // Print empty array representation
            console.log("~");   // Print tilde symbol
            continue;           // Continue to the next iteration of the loop
        }
        res.sort();
        printArray(res, res.length); // Print the results

        console.log("~");
    }
}
// } Driver Code Ends
// User function Template for javascript
class Solution {
    helper(board, x, y, ind, target, visited){
      const m=board.length
      const n=board[0].length
      if(x<0 || x>=m || y<0 || y>=n || !!visited[x][y] || board[x][y] != target[ind])
        return false
      if(ind==target.length-1)
        return true;
      visited[x][y]=true;
      const ans = [
          [0, 1],
          [0,-1],
          [1, 0],
          [-1,0]
        ]
        .map(c=> [x+c[0], y+c[1]])
        .filter(c=> c[0] >= 0 && c[0] < m && c[1] >= 0 && c[1] < n && !visited[c[0]][c[1]])
        .some(c => this.helper(board, c[0], c[1], ind+1, target, visited))
      visited[x][y]=false;
      return ans;
    }
    findWords(board, words) {
     const m=board.length
     const n=board[0].length
     const coords=board.reduce((acc1, v1, i)=>v1.reduce((acc2, v2, j)=>(acc2[v2]= [...(acc2[v2] || []), {i, j}], acc2), acc1),{})
     const ws= Object.keys(words.reduce((acc, v)=> (acc[v]=v, acc), {}))
     return ws.filter(word => {
        const visited= Array.from({length: m }, _=> ({}))
        return (coords[word[0]]||[]).some(v => this.helper(board, v.i, v.j,0, word, visited))
     })
    }
}