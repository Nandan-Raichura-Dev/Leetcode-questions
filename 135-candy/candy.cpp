class Solution {// we will cal for lrft and then right, and the connsider max of  it, 
public:// optimal: through the slope method
    int candy(vector<int>& ratings) {
         int i=1;
         int n=ratings.size();

         int sum=1;
         int peak=1;

         while(i<n){
            if(ratings[i]==ratings[i-1]){// slope is straight
                sum+=1;
                i++;
                continue;

            }

            while(i<n && ratings[i]>ratings[i-1]){// peak increases
                peak+=1;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){// dec slope
                sum+=down;
                i++;
                down++;
                
            }

            if(down>peak){
                sum+=down-peak;
            }

            peak=1;
         }
         return sum;
    }
};



// int n=ratings.size();
//          vector<int> left(n);
//          left[0]=1;// there is no left element 
//          vector<int> right(n);
//          right[n-1]=1;// there iss no right elemeent

//          // for left
//          for(int i=1;i<n;i++){
//             if(ratings[i]>ratings[i-1]){
//                 left[i]=left[i-1]+1;
//             }else{
//                 left[i]=1;
//             }
//          }

//          // for right

//          for(int i=n-2;i>=0;i--){
//             if(ratings[i]>ratings[i+1]){
//                  right[i]=right[i+1]+1;
//             }else{
//                right[i]=1;
//             }
//          }

//          // taling ,ax from bpth becz we want the elememnt satisfies bith side conditions

//          int sum=0;

//          for(int i=0;i<n;i++){
//             sum=sum+max(left[i],right[i]);
//          }

//         return sum;
