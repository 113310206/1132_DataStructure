int findMax(const vector<in`t>& arr) {
    int count = 0;
    int max = arr[0];
    // count +1 for the initialization
    count ++;
    for (int i = 1; i < arr.size(); i++) {
        // count +1 for the comparison
        // count +1 for the assignment
        // count +1 for the increment
        count = count + 3;
        if (arr[i] > max) {
            max = arr[i];
            // count +1 for the assignment
            count ++;
        }
    }
    return max;
    // count +1 for the return
    count ++;
    return count;
}
