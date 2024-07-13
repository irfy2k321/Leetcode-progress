class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        robots = sorted([(positions[i], healths[i], directions[i], i) for i in range(n)])

        result = []
        i = 0

        while i < len(robots):
            pos, health, direction, index = robots[i]
            if direction == 'R':
                result.append(robots[i])
                i += 1
            else:
                if result and result[-1][2] == 'R':
                    last_health = result[-1][1]
                    if last_health > health:
                        result[-1] = (result[-1][0], last_health - 1, result[-1][2], result[-1][3])
                        i += 1
                    elif last_health < health:
                        health -= 1
                        result.pop()
                        robots[i] = (pos, health, direction, index)
                    else:
                        result.pop()
                        i += 1
                else:
                    result.append(robots[i])
                    i += 1

        # Extract and sort the healths of the surviving robots by their original indices
        result = sorted(result, key=lambda x: x[3])
        return [health for _, health, _, _ in result]
        