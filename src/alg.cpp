// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      else {
        int leftCount = 1;
        int rightCount = 1;
        while (left + 1 < right && arr[left] == arr[left + 1]) {
          leftCount++;
          left++;
        }
        while (right - 1 > left && arr[right] == arr[right - 1]) {
          rightCount++;
          right--;
        }
        count += leftCount * rightCount;
        left++;
        right--;
      }
    }
    else if (sum < value) {
      left++;
    }
    else {
      right--;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int tar = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == tar) {
        int first = mid;
        int last = mid;
        while (first > left && arr[first - 1] == tar) {
          first--;
        }
        while (last < right && arr[last + 1] == tar) {
          last++;
        }
        count += (last - first + 1);
        break;
      } else if (arr[mid] < tar) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return count;
}
