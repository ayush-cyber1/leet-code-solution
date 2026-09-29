class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()

        for word in words:
            node = root
            for c in word:
                if c not in node.children:
                    node.children[c] = TrieNode()
                node = node.children[c]
            node.word = word

        rows, cols = len(board), len(board[0])
        result = []

        def dfs(r: int, c: int, node: TrieNode):
            char = board[r][c]
            if char not in node.children:
                return

            nxt = node.children[char]

            if nxt.word:
                result.append(nxt.word)
                nxt.word = None

            board[r][c] = '#'

            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] != '#':
                    dfs(nr, nc, nxt)

            board[r][c] = char

            if not nxt.children:
                del node.children[char]

        for i in range(rows):
            for j in range(cols):
                dfs(i, j, root)

        return result