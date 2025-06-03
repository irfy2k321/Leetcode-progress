class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        int n = status.size();
        int totalSweets = 0;

        std::vector<bool> iHaveBox(n, false);
        std::vector<bool> iHaveKey(n, false); 
        std::vector<bool> boxLooted(n, false);
        std::stack<int> boxesToOpen;

        for (int box : initialBoxes) {
            iHaveBox[box] = true;
            if (status[box] == 1 && !boxLooted[box]) {
                boxesToOpen.push(box);
                boxLooted[box] = true; 
            }
        }

        while (!boxesToOpen.empty()) {
            int currentBox = boxesToOpen.top();
            boxesToOpen.pop();

            totalSweets += candies[currentBox];

            for (int key : keys[currentBox]) {
                iHaveKey[key] = true;
                if (iHaveBox[key] && !boxLooted[key]) { 
                     boxesToOpen.push(key);
                     boxLooted[key] = true;
                }
            }

            for (int newBox : containedBoxes[currentBox]) {
                iHaveBox[newBox] = true;
                if ((status[newBox] == 1 || iHaveKey[newBox]) && !boxLooted[newBox]) {
                    boxesToOpen.push(newBox);
                    boxLooted[newBox] = true;
                }
            }
        }
        
        return totalSweets;
    }
};