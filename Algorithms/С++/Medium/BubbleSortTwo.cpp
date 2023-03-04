
// a kind of bubble sort
// O(n)
void ShakeSort(std::vector<int>& vec) {
	if (vec.empty())
		return;

	int right = vec.size() - 1;
	int left = 0;
	while (left <= right) {
		for (int i = right; i > left; i--) {
			if (vec[i - 1] > vec[i]) {
				swap(vec[i - 1], vec[i]);
			}
		}
		left++;
		for (int i = left; i < right; i++) {
			if (vec[i + 1] < vec[i]) {
				swap(vec[i], vec[i + 1]);
			}
		}
		right--;
	}
}