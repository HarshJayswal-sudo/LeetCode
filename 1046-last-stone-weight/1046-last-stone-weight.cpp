class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int l1 = pq.top();
            pq.pop();
            int l2 = pq.top();
            pq.pop();
            if((l1-l2) > 0){
                pq.push(l1-l2);
            }
        }if(pq.empty()) return 0;
        return pq.top();
    }
};