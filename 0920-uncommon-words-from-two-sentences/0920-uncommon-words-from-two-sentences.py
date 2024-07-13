class Solution:
    def uncommonFromSentences(self, s1, s2):
        # Split sentences into words
        words_s1 = s1.split()
        words_s2 = s2.split()
        
        # Count occurrences of each word in both sentences
        count_s1 = Counter(words_s1)
        count_s2 = Counter(words_s2)
        
        # List to store the uncommon words
        uncommon_words = []
        
        # Check words in s1
        for word in count_s1:
            if count_s1[word] == 1 and count_s2[word] == 0:
                uncommon_words.append(word)
        
        # Check words in s2
        for word in count_s2:
            if count_s2[word] == 1 and count_s1[word] == 0:
                uncommon_words.append(word)
        
        return uncommon_words