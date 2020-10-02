class Solution {
	public:    
		int findAns(vector<vector<int>>& books, int index, vector<int>& memo, int W) {        
			if(memo[index]) return memo[index];        
			int curw = books[index][0];        
			int curh = books[index][1];        
			int ans = INT_MAX;        
			for(int i=index+1; i<books.size(); i++) {            
				if(curw <= W) {                
					ans = min(ans, curh + findAns(books, i, memo, W));                
					curw += books[i][0];                
					curh = max(curh, books[i][1]);            
					}            else                break;        
			}        
			if(curw <= W)            ans = min(ans, curh);              
			memo[index] = ans;      
			return memo[index];      
		}        
		
		int minHeightShelves(vector<vector<int>>& books, int shelf_width) {       
			vector<int> memo(books.size(), 0);       
			return findAns(books, 0, memo, shelf_width);    
		}
};