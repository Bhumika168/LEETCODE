class Solution {
public:
    int calPoints(vector<string>& ops) {
        int val1;
        int val2;
        int anss=0;
        stack<int>stk;
        for(string i:ops){
            if(i=="C"){
                stk.pop();
            }
            else if(i=="D"){
                stk.push(stk.top()*2);
            }
            else if(i=="+"){
                val1=stk.top();
                stk.pop();
                val2=stk.top();
                stk.push(val1);
                stk.push(val1+val2);
            }
            else{
                stk.push(stoi(i));
            }

        }
        while(stk.size()!=0){
            anss+=stk.top();
            stk.pop();

        }
        return anss;
    }
};