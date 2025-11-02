int main() {
  vector<int> perm = {1, 2, 3};
  sort(perm.begin(), perm.end());
  do {
    for (int x : perm)
      cout << x << ' ';
    cout << '\n';
  } while (next_permutation(perm.begin(), perm.end()));

  int arr[] = {2,3,4,5,1,0};
  sort(arr,arr+6);// arr+CANTIDAD DE ELEMENTOS
  do
  {
    for (int x : perm)
          cout << x << ' ';
      cout << '\n';
  } while (next_permutation(arr,arr+6));
  return 0;
}

