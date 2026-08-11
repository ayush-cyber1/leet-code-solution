class Solution:
    def weightedSum(self, parent: list[int], nums: list[int]) -> int:
        n = len(parent)

        if n == 1:
            return nums[0]

        # Build the tree
        children = [[] for _ in range(n)]

        for i in range(1, n):
            children[parent[i]].append(i)

        # Find the depth of every node using BFS
        depth = [0] * n
        queue = [0]
        max_depth = 0

        head = 0

        while head < len(queue):
            u = queue[head]
            head += 1

            for v in children[u]:
                depth[v] = depth[u] + 1
                max_depth = max(max_depth, depth[v])
                queue.append(v)

        # Weight of a node:
        # deepest depth - current depth + 1
        ans = 0

        for i in range(n):
            weight = max_depth - depth[i] + 1
            ans += nums[i] * weight

        return ans
        