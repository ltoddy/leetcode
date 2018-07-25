如果你想参与这个项目，然后把你在leetcode上解决问题的答案也添加到这个项目来。

- 第一步：
    fork 这个项目。

- 第二步:

    如果你所做的题目在这个项目中已经存在了，那么请在那个存在的答案文件中的后面添加你的答案。
    
    例如：

    ```c
    class Solution
    {
    private:
        bool isprime(int num)
        {
            for (size_t i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) return false;
            }
            return true;
        }

    public:
        int countPrimes(int n)
        {
            vector<bool> nums(static_cast<unsigned long>(n), true);
            nums[0] = false, nums[1] = false;

            for (size_t i = 2; i * i < nums.size(); i++) {
                if (!this->isprime(static_cast<int>(i))) continue;

                for (size_t j = i * i; j < nums.size(); j += i) nums[j] = false;
            }

            return accumulate(nums.begin(), nums.end(), 0,
                            [](int init, bool isprime) -> int { return isprime ? init + 1 : init; });
        }
    };

    // -------------------------------------------------

    //
    your code
    //
    ```

    如果你做的题目在本项目中没有，请在新建一个.cpp文件，然后添加你的答案，然后在对应文件夹下的READMD.md中添加上详情。

- 第三步：
    切一个分支：

    > git checkout -b algorithms/<题目名称>

    > git commit "<题号> <题目名称> (have solved)"

    > git push origin algorithms/<题目名称>

    去github上提一个Pulll request，我会尽可能第一时间merge你的代码。
