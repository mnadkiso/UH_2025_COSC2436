class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Convert wordList to unordered_set for O(1) lookup
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord is not in wordList, no solution exists
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        // BFS queue: stores pairs of (current word, level/steps)
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        // Set to track visited words
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while (!q.empty()) {
            auto [currentWord, level] = q.front();
            q.pop();
            
            // If we reached the endWord, return the level
            if (currentWord == endWord) {
                return level;
            }
            
            // Try changing each character of the current word
            for (int i = 0; i < currentWord.length(); i++) {
                string temp = currentWord;
                
                // Try all 26 lowercase letters
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    
                    // Skip if it's the same word
                    if (temp == currentWord) {
                        continue;
                    }
                    
                    // If the new word is in wordList and not visited
                    if (wordSet.find(temp) != wordSet.end() && 
                        visited.find(temp) == visited.end()) {
                        
                        visited.insert(temp);
                        q.push({temp, level + 1});
                    }
                }
            }
        }
        
        // No transformation sequence exists
        return 0;
    }
};