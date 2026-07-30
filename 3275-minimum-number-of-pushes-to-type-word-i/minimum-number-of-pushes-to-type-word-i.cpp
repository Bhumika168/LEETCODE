class Solution {
public:
    int minimumPushes(string word) {
        int p=0;
        for(int i=0;i<word.size();i++){
            p+=(i/8)+1;

        }
        return p;
    }
};