const binarySearch = (arr, start, end, target) => {
  if (end >= start) {
    mid = parseInt(start + (end - start) / 2);
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      return binarySearch(arr, start, mid - 1, target);
    } else {
      return binarySearch(arr, mid + 1, end, target);
    }
  } else {
    return -1;
  }
};
