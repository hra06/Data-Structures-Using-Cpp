// We can also heap Sort
#include<vector>
using namespace std;


class PriorityQueue{
	vector<int> pq;
	
	public:
		PriorityQueue(){
		
		}
		
		bool isEmpty(){
			return (pq.size() == 0);
		}
		
		int getSize(){
			return pq.size();
		}
		
		int getMin(){
			if(isEmpty()){
				return 0;
			}
			return pq[0];
		}
		
		void insert(int element){
			pq.push_back(element);
			
			int childIndex = pq.size()-1;
			
			//while(pq[childIndex] >= pq[parentIndex]){
			while(childIndex > 0){				
				int parentIndex = (childIndex-1)/2;
			
				if(pq[childIndex] <pq[parentIndex]){
					int temp = pq[childIndex];
					pq[parentIndex] = pq[childIndex];
					pq[parentIndex] = pq[childIndex];
				}else{
					break;
				}
				parentIndex = (childIndex-1)/2;
			}
			
		}
		
		
		int removeMin() {
            int min = pq[0];
            int lastIndex = pq.size()-1;
            int last = pq[lastIndex];
            pq[0] = last;
            pq.pop_back();
            lastIndex--;
            int parentIndex = 0;
            while(2*parentIndex+1 <= lastIndex-1){
                if(lastIndex > (2*parentIndex+1)){
                    if(pq[parentIndex]<= pq[2*parentIndex+1] && pq[parentIndex]<= pq[2*parentIndex+2]){
                        parentIndex++;
                        break;
                    }else if(lastIndex == 2*parentIndex+1 ){
                        if(pq[lastIndex]<pq[parentIndex]){
                            int temp = pq[parentIndex];
                            pq[parentIndex] = pq[lastIndex];
                            pq[lastIndex] = temp;
                            break;
                        }
                    }else{
                        int minIndex = 0;
                        
                        if(pq[parentIndex] <= pq[2*parentIndex+1] && pq[parentIndex] <= pq[2*parentIndex+2])
                            minIndex = parentIndex;
                        if(pq[2*parentIndex+1] <= pq[parentIndex]  && pq[2*parentIndex+1] <= pq[2*parentIndex+2])
                            minIndex = 2*parentIndex+1;
                        else
                            minIndex = 2*parentIndex+2;
                        
                        int temp = pq[parentIndex];
                        pq[parentIndex] = pq[minIndex];
                        pq[minIndex] = temp;
                        parentIndex = minIndex;
                        
                    }
                }
            }
            return min;
        }
};
