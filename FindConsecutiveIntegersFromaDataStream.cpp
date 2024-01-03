class DataStream {
public:
    int val,k1,count=0,last = -1;
    DataStream(int value, int k) {
        val = value;
        k1 = k;
    }
    
    bool consec(int num) {
        if(last==-1)
        {
            last = num;
            count++;
        }
        else if(last==num)
        {
            count++;
        }
        else
        {
            last = num;
            count = 1;
        }
        if(count>=k1 && last == val)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
