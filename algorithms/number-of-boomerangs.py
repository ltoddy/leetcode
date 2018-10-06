class Solution:
    def _distance(self, p1, p2):
        return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2

    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        count = 0
        for i in points:
            store = {}
            for j in filter(lambda j: i != j, points):
                dis = self._distance(i, j)
                store[dis] = store.get(dis, 0) + 1
            for value in filter(lambda value: value >= 2, store.values()):
                count += (value - 1) * value
        return count
