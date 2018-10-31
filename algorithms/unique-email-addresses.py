class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        s = set()

        for email in emails:
            for i in range(len(email)):
                if email[i] == '+':
                    email = email[:i] + email[email.find('@'):]
                    break
                elif email[i] == '.':
                    email = email[:i] + email[i + 1:]
            s.add(email)
        return len(s)
