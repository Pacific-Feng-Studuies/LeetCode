class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map <int, int> basket;    // just for search

        int maxFruit = 0;       // The maximun fruit current picked
        int leftIndex = 0;      // The starting index current do

        for(int i = 0 ; i < fruits.size() ; i++)
        {
            basket[fruits[i]]++;

            while(basket.size()>2)
            {
                if(basket[fruits[leftIndex]] == 1)    basket.erase(fruits[leftIndex]);  // after -1, the result will be 1 -> so can erase
                else                                  basket[fruits[leftIndex]]--;      // reduce the number of the fruit

                leftIndex++;
            }

            maxFruit = max(maxFruit, i-leftIndex+1);
        }

        return maxFruit;
    }
};
