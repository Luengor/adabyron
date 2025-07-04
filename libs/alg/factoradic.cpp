#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi factoradic(int n) {
    vi factors;
    n--;
    for (int i = 1; i <= n; i++) {
        factors.push_back(n % i);
        n /= i;
    }

    reverse(factors.begin(), factors.end());
    return factors;
}

vi nth_permutation(vi &factors) {
    vi res;
    res.reserve(factors.size());

    vi nums(factors.size());
    for (int i = 0; i < factors.size(); i++)
        nums[i] = i + 1;

    for (auto f : factors) {
        int n = nums[f];
        nums.erase(nums.begin() + f); // esto es muy lento
        res.push_back(n);
    }

    return res;
}