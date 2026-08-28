class Solution:
    def fullJustify(self, words, maxWidth):
        result = []
        i = 0

        while i < len(words):
            line = []
            line_length = 0

            # Pick as many words as possible for this line
            while i < len(words):
                if line_length + len(words[i]) + len(line) > maxWidth:
                    break

                line.append(words[i])
                line_length += len(words[i])
                i += 1

            # Last line or line with only one word
            if i == len(words) or len(line) == 1:
                text = " ".join(line)
                text += " " * (maxWidth - len(text))
                result.append(text)
                continue

            # Number of spaces that need to be distributed
            total_spaces = maxWidth - line_length
            gaps = len(line) - 1

            # Minimum spaces per gap
            spaces = total_spaces // gaps

            # Extra spaces go to the left gaps
            extra = total_spaces % gaps

            text = ""

            for j in range(gaps):
                text += line[j]
                text += " " * (spaces + (1 if j < extra else 0))

            text += line[-1]

            result.append(text)

        return result