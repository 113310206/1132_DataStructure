void printPair(const vector<int>& arr) {
    // count +1 for the initialization
    for (int i = 0; i < arr.size(); i++) {
        // count +1 for the comparison
        // count +1 for the increment
        // count +1 for the initialization
        for (int j = i + 1; j < arr.size(); j++) {
            // count +1 for the comparison
            // count +1 for the increment
            // count +1 for the initialization  
            cout << arr[i] << " " << arr[j] << endl;
        }
    }
}
