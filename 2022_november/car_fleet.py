from typing import List

class Solution:
    def findPosMeet(self, dp, sp, dc, sc):
        return ((dp*sc) - (dc*sp))/(sc-sp)
    
    def getNewD(self, mp, pp, ps, p, s):
        t = (mp - pp)/ps

        return (s*t) + p

    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        if len(position) == 1:
            return 1
        
        tmp_dict = {}

        for i in range(0, len(position)):
            tmp_dict[position[i]] = speed[i]
        
        pos_spd = sorted(tmp_dict.items())

        merge_pos, merge_spd = -1, -1
        prev_pos, prev_spd = pos_spd.pop()
        fleets = 1

        while len(pos_spd) > 0:
            pos, spd = pos_spd.pop()
            if merge_pos != -1 and spd <= prev_spd:
                fleets += 1
                merge_pos, merge_spd = -1, -1
            else:
                tmp_pos = self.findPosMeet(prev_pos, prev_spd, pos, spd)

                if merge_pos == -1:
                    if tmp_pos <= target:
                        # they've met
                        merge_pos = tmp_pos
                        merge_spd = prev_spd
                    else:
                        fleets += 1
                        merge_pos, merge_spd = -1, -1
                else:
                    if tmp_pos <= merge_pos:
                        # they've met
                        merge_pos = tmp_pos
                        merge_spd = prev_spd
                    else:
                        # verify if they meet after
                        newD = self.getNewD(merge_pos, prev_pos, prev_spd, pos, spd)
                        tmp_pos = self.findPosMeet(merge_pos, merge_spd, newD, spd)

                        if tmp_pos <= target:
                            merge_pos = tmp_pos
                            merge_spd = prev_spd
                        else:
                            fleets += 1
                            merge_pos, merge_spd = -1, -1
            
            prev_pos, prev_spd = pos, spd
        
        return fleets


            


s = Solution()

print(s.carFleet(10, [0,4,2], [2,1,3]))