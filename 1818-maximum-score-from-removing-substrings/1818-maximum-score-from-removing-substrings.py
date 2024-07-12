class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        if x >= y:
            s, score1 = self.removeSubstrings(s, 'a', 'b', x)
            s, score2 = self.removeSubstrings(s, 'b', 'a', y)
        else:
            s, score1 = self.removeSubstrings(s, 'b', 'a', y)
            s, score2 = self.removeSubstrings(s, 'a', 'b', x)
        return score1 + score2

    def removeSubstrings(self, s: str, first: str, second: str, points: int) -> (str, int):
        stack = []
        score = 0

        for char in s:
            if stack and stack[-1] == first and char == second:
                stack.pop()  # Remove the matching pair
                score += points  # Gain points
            else:
                stack.append(char)  # Push current character onto stack

        # Convert the stack back to string
        return ''.join(stack), score