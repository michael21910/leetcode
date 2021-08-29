class Solution
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack <int> temp;
        int indexPush = 0, indexPop = 0;
        while(indexPush < pushed.size() && indexPop < popped.size()){
            if(temp.size() > 0){
                if(temp.top() == popped[indexPop]){
                    temp.pop();
                    indexPop++;
                }
                else{
                    temp.push(pushed[indexPush]);
                    indexPush++;
                }
            }
            else{
                temp.push(pushed[indexPush]);
                indexPush++;
            }
        }
        if(indexPush == pushed.size() && indexPop != popped.size()){
            if(temp.size() == 0){
                return false;
            }
            while(indexPop != popped.size()){
                if(temp.top() == popped[indexPop]){
                    indexPop++;
                    temp.pop();
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
