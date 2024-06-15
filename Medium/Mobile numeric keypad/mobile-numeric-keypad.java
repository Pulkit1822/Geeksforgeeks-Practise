//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GfG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            Solution ob = new Solution();
            System.out.println(ob.getCount(n));
        }
    }
}
// } Driver Code Ends





//User function Template for Java

class Solution
{
	public long getCount(int N)
	{
		HashMap<Integer, Integer[] > graph = new HashMap<>();
	
		
		graph.put(0 ,  new Integer[]{8,0} );
		graph.put(1 ,  new Integer[]{2,4,1} );
		graph.put(2 ,  new Integer[]{1,3,5,2} );
		graph.put(3 ,  new Integer[]{2,6,3} );
		graph.put(4 ,  new Integer[]{1,5,7,4} );
		graph.put(5 ,  new Integer[]{2,4,6,8,5} );
		graph.put(6 ,  new Integer[]{3,5,9,6} );
		graph.put(7 ,  new Integer[]{4,8,7} );
		graph.put(8 ,  new Integer[]{5,7,9,0,8} );
		graph.put(9 ,  new Integer[]{6,8,9} );
		
		long totalCount = pressKeyTab( N , graph );
		return totalCount;
		
	}
	
	//recursion
	public static long pressKey( int row , int col , int counter , int[][] keypad  , long [][][] dp){
	    
	    if( keypad[row][col ]  == -1 ){
	        return 0;
	    }
	    
	    if( counter == 1 ){
	        return 1;
	    }
	    
	    //CHECKING MEMORY
	    if( dp[row][col][counter] != 0 ){
	        return dp[row][col][counter];
	    }
	    
	    
	    long selfPress = pressKey( row , col , counter-1 , keypad , dp );
	    
	    long upPress=0;
	    if( row-1 >=0 ){
	        upPress = pressKey( row-1 , col , counter-1 , keypad , dp );
	    }
	    
	    long leftPress=0;
	    if( col-1 >= 0 ){
	        leftPress = pressKey( row , col-1 , counter-1 , keypad , dp );
	    }
	    
	    long rightPress=0;
	    if( col+1 < keypad[0].length ){
	        rightPress = pressKey( row , col+1 , counter-1 , keypad , dp );
	    }
	    
	    long downPress=0;
	    if( row+1 < keypad.length ){
	        downPress = pressKey( row+1 , col , counter-1 , keypad , dp );
	    }
	    
	    
	    long totalPress =  selfPress + upPress + leftPress + rightPress + downPress;
	    
	    //MEMORISATION
	    dp[row][col][counter] = totalPress ;
	    
	    return totalPress;
	    
	}
	
	
	// Graph Style
	public static long pressKeyGraph( int key , int counter , HashMap<Integer,Integer[]> graph , long[][] dp ){
	    
	    if( counter ==1 ){
	        return 1;
	    }
	    
	    
	    //CHECKING MEMORY
	    if( dp[key][counter] != 0){
	        return dp[key][counter];
	    }
	    
	    
	    long totalWays=0;
	    
	    Integer[] possiblePressWay = graph.get(key);
	    
	    for( int next=0 ; next < possiblePressWay.length ; next++ ){
	        
	        int nextKey = (int) possiblePressWay[next];
	        
	        totalWays += pressKeyGraph( nextKey , counter-1 , graph , dp );
	    }
	    
	    
	    //MEMORISATION
	    dp[key][counter] = totalWays;
	    
	    return totalWays;
	}
	
	
	//DYNAMIN PROGRAMMING - TABULATION
	public static long pressKeyTab(  int totalCounter , HashMap<Integer, Integer[]> graph ){
	    
	    
	    long dp[][] = new long[10][ totalCounter+1 ];
	    
	    //filling Base case
	    
	    for( int key=0 ; key<=9 ; key++ ){
	        
	        int counter=1;
	        dp[ key ][counter] = 1;
	    }
	    
	    
	    //core-logic
	    
	    for( int counter=2 ; counter <= totalCounter ; counter++ ){
	        
	        for( int key=0 ; key <=9 ; key++ ){
	            
	            //core Logic
	            long totalWays=0;
        	    
        	    Integer[] possiblePressWay = graph.get(key);
        	    
        	    for( int next=0 ; next < possiblePressWay.length ; next++ ){
        	        
        	        int nextKey = (int) possiblePressWay[next];
        	        
        	        totalWays += dp[ nextKey ][ counter-1 ];
        	    }
        	    
        	    
        	    //MEMORISATION
        	    dp[key][counter] = totalWays;
	        }
	    }
	    
	    
	    //Now for the final Result , do what we did while calling the recursion
	    long totalCount=0;
		
		for( int key=0 ; key <= 9 ; key++ ){
		    
		    totalCount += dp[key][totalCounter];
		}
		
		return totalCount;
	    
	}
}