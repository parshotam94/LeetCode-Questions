from collections import Counter
class Solution:
    def isNStraightHand(self, hand: list[int], groupSize: int) -> bool:
        mpp=Counter(hand)
        for i in sorted(mpp):
            if mpp[i]>0:
                for j in range(groupSize)[::-1]:
                    mpp[i+j]-=mpp[i]
                    if mpp[i+j]<0:
                        return False
        return True