class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        mpp=Counter(nums)
        XOR=0
        for num, freq in mpp.items():
            if freq==2:
                XOR^=num
        return XOR
        