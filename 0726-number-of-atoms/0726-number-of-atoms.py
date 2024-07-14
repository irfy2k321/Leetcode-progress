class Solution(object):
    def countOfAtoms(self, formula):
        """
        :type formula: str
        :rtype: str
        """
        from collections import defaultdict

        def parse():
            n = len(formula)
            stack = [defaultdict(int)]
            i = 0

            while i < n:
                if formula[i] == '(':
                    stack.append(defaultdict(int))
                    i += 1
                elif formula[i] == ')':
                    top = stack.pop()
                    i += 1
                    i_start = i
                    while i < n and formula[i].isdigit():
                        i += 1
                    multiplicity = int(formula[i_start:i] or 1)
                    for atom, v in top.items():
                        stack[-1][atom] += v * multiplicity
                else:
                    i_start = i
                    i += 1
                    while i < n and formula[i].islower():
                        i += 1
                    atom = formula[i_start:i]
                    i_start = i
                    while i < n and formula[i].isdigit():
                        i += 1
                    multiplicity = int(formula[i_start:i] or 1)
                    stack[-1][atom] += multiplicity

            return stack[0]

        count = parse()
        sorted_atoms = sorted(count.items())

        # Updated part: Correctly format the output string
        return ''.join(f"{atom}{count if count > 1 else ''}" for atom, count in sorted_atoms)