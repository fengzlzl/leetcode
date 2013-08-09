class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n <= 0) return false;
        int i = 0, j = n-1;
        while(i <= j) {
            int mid = (i + j) / 2;
            int mval = A[mid];
            if(target == mval) return true;
            if(i == j) return false;
            if(A[i] < A[j]) {
                if(target < mval)
                    j = mid - 1;
                else
                    i = mid + 1;
            } else if (A[i] > A[j]) {
                if(mval > A[i]) {
                    if(target < mval) {
                        if(target < A[i]) {
                            i = mid + 1;
                        } else if (target == A[i]) {
                            return true;
                        } else {
                            j = mid - 1;
                        }
                    }
                    else
                        i = mid + 1;
                } else if (mval < A[i]) {
                    if(target < mval) {
                        j = mid - 1;
                    } else {
                        if(target == A[j])
                            return j;
                        else if(target < A[j])
                            i = mid + 1;
                        else
                            j = mid - 1;
                    }
                } else {
                    i = mid + 1;
                }
            } else {
                if(mval == A[i]) {
                    bool onleft = search(A + i + 1, mid - i + 1 - 2, target);
                    if(onleft) return true;
                    return search(A + mid + 1, j - mid + 1 - 2, target);
                } else if (mval > A[i]) {
                    if(target < mval) {
                        if(target == A[i]) return true;
                        else if(target < A[i]) {
                            i = mid + 1;
                            --j;
                        } else {
                            ++i;
                            j = mid - 1;
                        }
                    } else {
                        i = mid + 1;
                        --j;
                    }
                } else {
                    if(target < mval) {
                        ++i;
                        j = mid + 1;
                    } else {
                        if(target == A[j]) return true;
                        else if(target < A[j]) {
                            --j;
                            i = mid + 1;
                        } else {
                            ++i;
                            j = mid - 1;
                        }
                    }
                }
            }
        }
        return false;
    }
};