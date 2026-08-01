class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(n<1){
            return true;
        }
        int cnt=0;

        int s=flowerbed.size();

        vector<int> flower(s,0);
        for(int i=0;i<s;i++){
            flower[i]=flowerbed[i];
        }

         if(flower[0]==0 && (s==1 || flower[1]!=1)){
            flower[0]=1;
            cnt++;
            if(cnt==n) return true;
        }


       for(int i=1;i<s-1;i++){
            if(flower[i]==0 && flower[i-1]!=1 && flower[i+1]!=1 ){
                flower[i]=1;
                cnt++;
                if(cnt==n){
                    return true;
                }
            }
       }

       if(s>1 && flower[s-1]==0 && flower[s-2]!=1){
            flower[s-1]=1;
            cnt++;
            if(cnt==n) return true;
        }


       return false;
    }
};