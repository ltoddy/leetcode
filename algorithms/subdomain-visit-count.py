class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        cnt = {}
        for cpdomain in cpdomains:
            [amount, domain] = cpdomain.split(' ')
            amount = int(amount)
            for i in range(len(domain.split('.'))):
                tmp = domain.split('.', i).pop()
                cnt[tmp] = cnt[tmp] + amount if tmp in cnt.keys() else amount
        return list(map(lambda domain: '{!r} {}'.format(cnt[domain], domain), cnt))
