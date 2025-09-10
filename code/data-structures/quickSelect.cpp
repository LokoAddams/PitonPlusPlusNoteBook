int Partition(int A[], int l, int r) {
  int p = A[l];                                  // p is the pivot
  int m = l;                                     // S1 and S2 are empty
  for (int k = l+1; k <= r; ++k) {               // explore unknown region
    if (A[k] < p) {                              // case 2
      ++m;
      swap(A[k], A[m]);
    } // notice that we do nothing in case 1: a[k] >= p
  }
  swap(A[l], A[m]);                              // swap pivot with a[m]
  return m;                                      // return pivot index
}

int RandPartition(int A[], int l, int r) {
  int p = l + rand() % (r-l+1);                  // select a random pivot
  swap(A[l], A[p]);                              // swap A[p] with A[l]
  return Partition(A, l, r);
}

int QuickSelect(int A[], int l, int r, int k) {  // expected O(n)
  if (l == r) return A[l];
  int q = RandPartition(A, l, r);                // O(n)
  if (q+1 == k)
    return A[q];
  else if (q+1 > k)
    return QuickSelect(A, l, q-1, k);
  else
    return QuickSelect(A, q+1, r, k);
}

int main() {
  int A[] = { 2, 8, 7, 1, 5, 4, 6, 3 };          

  nth_element(A,A+4, A+8);
  printf("%d\n", A[4]);
  //output: 5
  for(auto i:A)
    cout << i << ",";
  //output: [3,2,1,4,5,7,6,8]
  
  return 0;
}
