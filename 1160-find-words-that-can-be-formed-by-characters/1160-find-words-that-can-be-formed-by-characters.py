class Solution:
    def countCharacters(self, words: list[str], chars: str) -> int:
        def can(word, chars):
            mpp=Counter(chars)
            for char in word:
                if mpp[char]<=0:
                    return False
                mpp[char]-=1
            return True
        result=0
        for word in words:
            if can(word, chars):
                result+=len(word)
        return result
