class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
         stack<int>s;
         s.push(-1);
         int n=heights.size();
         vector<int>nextsmaller(heights.size());
         for(int i=heights.size()-1;i>=0;i--){
             int curr = i;
             while(s.top()!=-1&&heights[s.top()]>=heights[curr]){
                 s.pop();
             }
            
             nextsmaller[i]=s.top();
             s.push(i); 
         }
         for(int i=0;i<heights.size();i++){
             if(nextsmaller[i]==-1){
                 nextsmaller[i]=heights.size();
             }
         }
         stack<int>k;
        k.push(-1); 
         vector<int>prevsmaller(heights.size());
       for(int i= 0;i<heights.size();i++){
           int curr =i;
           while(k.top()!=-1&&heights[k.top()]>=heights[curr]){
               k.pop();
           }
           prevsmaller[i]=k.top();
           k.push(i);
       }
      int i=0;
     
      int maxarea =INT_MIN;
      while(i<heights.size()){
        //   if(nextsmaller[i]==-1){
        //       ne
        //   }
          int area=(nextsmaller[i]-prevsmaller[i]-1)*heights[i];
          maxarea=max(maxarea,area);
          i++;
      }

      return maxarea;


    }
};