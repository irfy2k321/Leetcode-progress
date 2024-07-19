class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        # Find the minimum element in each row
        min_in_rows = [min(row) for row in matrix]
        
        # Transpose the matrix to get columns easily
        transposed_matrix = list(zip(*matrix))
        
        # Find the maximum element in each column
        max_in_cols = [max(col) for col in transposed_matrix]
        
        # Find all lucky numbers (elements that are minimum in their row and maximum in their column)
        lucky_numbers = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == min_in_rows[i] and matrix[i][j] == max_in_cols[j]:
                    lucky_numbers.append(matrix[i][j])
        
        return lucky_numbers