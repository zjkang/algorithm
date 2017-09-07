/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Design Phone Directory
 Source:     https://leetcode.com/problems/design-phone-directory/
 Difficulty: Medium
 Tags:       {Linked List}, {Design}
 Company:    Google
 
 Notes:
 Design a Phone Directory which supports the following operations:

 get: Provide a number which is not assigned to anyone.
 check: Check if a number is available or not.
 release: Recycle or release a number.
 Example:

 // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
 PhoneDirectory directory = new PhoneDirectory(3);

 // It can return any available phone number. Here we assume it returns 0.
 directory.get();

 // Assume it returns 1.
 directory.get();

 // The number 2 is available, so return true.
 directory.check(2);

 // It returns 2, the only number that is left.
 directory.get();

 // The number 2 is no longer available, so return false.
 directory.check(2);

 // Release number 2 back to the pool.
 directory.release(2);

 // Number 2 is available again, return true.
 directory.check(2);
 */

 class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        max = maxNumbers;
        for (int i = 0; i < maxNumbers; ++i) {
            numbers.push_back(i);
            avail.insert(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (numbers.size() == 0) return -1;
        int res = numbers.back();
        numbers.pop_back();
        avail.erase(res);
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return number < max && number >= 0 && avail.count(number);
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= 0 && number < max && !avail.count(number)) {
            avail.insert(number);
            numbers.push_back(number);
        }
    }
private:
    int max;
    unordered_set<int> avail;
    vector<int> numbers;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
