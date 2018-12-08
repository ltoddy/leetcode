class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        string_log = []
        digit_log = []
        for log in logs:
            if '0' <= log.split(' ')[1][0] <= '9':
                digit_log.append(log)
            else:
                string_log.append(' '.join(log.split()[1:]).lstrip(' ') + ' ' + log.split()[0])
        string_log.sort()
        tmp = []
        for log in string_log:
            tmp.append(log.split()[-1] + ' ' + ' '.join(log.split()[:-1]))
        return tmp + digit_log
